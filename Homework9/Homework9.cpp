#include <iostream>
#include "../Homework8/Scene.h"
int main()
{
	Scene scene1;
	scene1.ParseScene("scene0.crtscene");
	srand(time(NULL));
	color colors[5] = {
  {rand() % 256, rand() % 256, rand() % 256},
  {rand() % 256, rand() % 256, rand() % 256},
  {rand() % 256, rand() % 256, rand() % 256},
  {rand() % 256, rand() % 256, rand() % 256},
  {rand() % 256, rand() % 256, rand() % 256}
	};

	static const int maxColorComponent = 255;
	float aspectRatio = (float)scene1.imageWidth / scene1.imageHeight;

	std::ofstream ppmFileStream("scene3.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << scene1.imageWidth << " " << scene1.imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";
	for (int rowIdx = 0; rowIdx < scene1.imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < scene1.imageWidth; ++colIdx) {
			float x = (float)colIdx + 0.5;
			float y = (float)rowIdx + 0.5;
			x /= scene1.imageWidth;
			y /= scene1.imageHeight;
			x = (2.0 * x) - 1.0;
			y = 1.0 - (2.0 * y);
			x *= aspectRatio;
			my_v3 cameraRayDir(x, y, -1.0F);
			cameraRayDir.normalize();
			Ray cameraRay(scene1.camera.origin, scene1.camera.orient * cameraRayDir);
			float closestDistance = FLT_MAX;
			int renderItemIdx = -1;
			int renderTriangleIdx = -1;
			for (auto itemIdx = 0; itemIdx < scene1.items.size(); ++itemIdx) {
				for (auto triangleIdx = 0; triangleIdx < scene1.items[itemIdx].indicies.size(); ++triangleIdx) {
					TriangleIdxes triangleIndex = scene1.items[itemIdx].indicies[triangleIdx];
					Triangle triangle(scene1.items[itemIdx].vertices[triangleIndex.v0],
						scene1.items[itemIdx].vertices[triangleIndex.v1],
						scene1.items[itemIdx].vertices[triangleIndex.v2]);
					float distance = FLT_MAX;
					if (triangle.intersection(cameraRay, distance)) {
						if (distance < closestDistance) {
							closestDistance = distance;
							renderItemIdx = itemIdx;
							renderTriangleIdx = triangleIdx;
						}
					}
				}
			}

			color triColor;
			if (renderTriangleIdx != -1) {
				triColor = colors[renderTriangleIdx % 5];
			}
			else {
				triColor = scene1.bgc;
			}
			ppmFileStream << triColor.red << ' ' << triColor.green << ' ' << triColor.blue << ' ';
		}
		ppmFileStream << "\n";
	}
	ppmFileStream.close();
=======
	
>>>>>>> d6d3756b290dbab62b4014a716fb1a91146cbb2f
	return 0;
}
