#include <iostream>
#include <fstream>
#include "Triangle.h"
#include <vector>
int main()
{
	static const int imageWidth = 1920;
	static const int imageHeight = 1080;

	static const int maxColorComponent = 255;
	float aspectRatio = (float)imageWidth / imageHeight;

	std::vector<Triangle> triangles = { Triangle(my_v3(-1.75, -1.75, -3), my_v3(1.75, -1.75, -3), my_v3(0, 1.75, -3)),
										Triangle(my_v3(0, -1, -3), my_v3(1.5, 0, -3), my_v3(0, 1, -3)) };

	std::ofstream ppmFileStream("rombcho.ppm", std::ios::out | std::ios::binary);
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
			Ray cameraRay(my_v3(0.0F, 0.0F, 0.0F), cameraRayDir);
			if (triangles[0].intersection(cameraRay)) {
				ppmFileStream << 25 << ' ' << 86 << ' ' << 255 << ' ';
			}
			else if (triangles[1].intersection(cameraRay)) {
				ppmFileStream << 150 << ' ' << 255 << ' ' << 177 << ' ';
			}
			else {
				ppmFileStream << 255 << ' ' << 180 << ' ' << 50 << ' ';
			}
		}
		ppmFileStream << "\n";
	}

	ppmFileStream.close();

	return 0;
}
