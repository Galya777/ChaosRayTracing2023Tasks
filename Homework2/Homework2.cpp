#include <fstream>
#include "v3.h"
struct CRTColor {
	int red;
	int green;
	int blue;
};
static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;

int main() {
	float aspectRatio = (float)imageWidth / imageHeight;
	std::ofstream ppmFileStream("crt_output_image.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			CRTColor RGB;
			float x = (float)colIdx + 0.5;
			float y = (float)rowIdx + 0.5;
			x /= imageWidth;
			y /= imageHeight;
			x = (2.0 * x) - 1.0;
			y = 1.0 - (2.0 * y);
			x *= aspectRatio;
			my_v3 cameraRay(x, y, -1.0F);
			cameraRay.normalize();
			RGB.red = (int)(((cameraRay.get_x() + 1) / 2.0F) * 255);
			RGB.green = (int)(((cameraRay.get_y() + 1) / 2.0F) * 255);
			RGB.blue = (int)(((cameraRay.get_z() + 1) / 2.0F) * 255);
			ppmFileStream << RGB.red << ' ' << RGB.green << ' ' << RGB.blue << ' ';
		}
		ppmFileStream << "\n";
	}

	ppmFileStream.close();

	return 0;
}


