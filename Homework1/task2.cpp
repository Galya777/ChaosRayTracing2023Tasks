/*#include <fstream>
#include <cassert>

/// Output image resolution
static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;
const int radius = 500;
int main() {
	const int radius = 500;
	std::ofstream ppmFileStream("crt_output_imageCircle.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			float newXIdx = colIdx - (imageWidth / 2);
			float newYIdx = (imageHeight / 2) - 1 - rowIdx;
			if (((newXIdx * newXIdx) + (newYIdx * newYIdx)) < (radius*radius)) {
				ppmFileStream << 255 << ' ' << 255 << ' ' << 0 << '\n';
			}
			else {
				ppmFileStream << 255 << ' ' << 255 << ' ' << 255 << '\n';
			}
		}
		ppmFileStream << "\n";
	}

	ppmFileStream.close();

	return 0;
}*/
