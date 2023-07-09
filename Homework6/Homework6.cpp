#include <iostream>
#include "Camera.h"
#include <vector>
#include <fstream>
#include <string>
#include "../Homework5/Triangle.h"
int main()
{
	static const int imageWidth = 1920;
	static const int imageHeight = 1080;

	static const int maxColorComponent = 255;
	float aspectRatio = (float)imageWidth / imageHeight;

	std::vector<Triangle> triangles = { Triangle(my_v3(-1.75, -1.75, -3), my_v3(1.75, -1.75, -3), my_v3(0, 1.75, -3)),
										Triangle(my_v3(0, -1, -3), my_v3(1.5, 0, -3), my_v3(0, 1, -3)) };

	Camera cam;
	cam.pan(-30.0F);
	for (auto frames = 0; frames < 10; ++frames) {
		std::ofstream ppmFileStream("frames" + std::to_string(frames) + ".ppm", std::ios::out | std::ios::binary);
		if (!ppmFileStream) {
			std::ofstream ppmFileStream("frames" + std::to_string(frames) + ".ppm", std::ios::out, std::ios::app);
		}
		ppmFileStream << "P3\n";
		ppmFileStream << imageWidth << " " << imageHeight << "\n";
		ppmFileStream << maxColorComponent << "\n";
		for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
			for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
				float x = (float)colIdx + 0.5;
				float y = (float)rowIdx + 0.5;
				x /= imageWidth;
				y /= imageHeight;
				x = (2.0 * x) - 1.0;
				y = 1.0 - (2.0 * y);
				x *= aspectRatio;
				my_v3 cameraRayDir(x, y, -1.0F);
				cameraRayDir.normalize();
				Ray cameraRay(cam.origin, cam.orient * cameraRayDir);
				if (triangles[0].intersection(cameraRay)) {
					ppmFileStream << 255 << ' ' << 52 << ' ' << 255 << ' ';
				}
				else if (triangles[1].intersection(cameraRay)) {
					ppmFileStream << 70 << ' ' << 235 << ' ' << 225 << ' ';
				}
				else {
					ppmFileStream << 154 << ' ' << 187 << ' ' << 65 << ' ';
				}
			}
			ppmFileStream << "\n";

		}
		ppmFileStream.close();
		cam.pan(6.0F);
	}
	return 0;
}
