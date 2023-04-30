#include <fstream>
#include <cassert>
#include <iostream>
#include <array>

/// Output image resolution
static const int imageWidth = 256;
static const int imageHeight = 256;

static const int pixelWidth = 1920;
static const int pixelHeight = 1080;


static const int maxColorComponent = 255;

struct CRTColor {
	int red;
	int green;
	int blue;
};
CRTColor randColor(const unsigned int bitMask) {
	//assert(bitMask < maxColorComponent);
	srand(time(NULL));
	return CRTColor{
		bitMask & 1 ? rand() % maxColorComponent : 0,
		bitMask & 2 ? rand() % maxColorComponent : 0,
		bitMask & 4 ? rand() % maxColorComponent : 0,
	};
}


int main() {
	const int rows = 4;
	const int cols = 4;
	const int pixelsPerHRect = imageHeight / rows;
	const int pixelsPerWRect = imageWidth / cols;
	std::array<CRTColor, rows*cols> rectangle;
	for (auto amountOfRectanglesH = 0; amountOfRectanglesH < rows; ++amountOfRectanglesH) {
		for (auto amountOfRectangleW = 0; amountOfRectangleW < cols; ++amountOfRectangleW) {
			CRTColor RGB;
			RGB.red = rand() % 256;
			RGB.blue = rand() % 256;
			RGB.green = rand() % 256;
			rectangle[amountOfRectanglesH * cols + amountOfRectangleW] = RGB;

		}
	}
	std::ofstream ppmFileStream("crt_output_image.ppm", std::ios::out | std::ios::binary);
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";

	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {
			int rectIdxH = rowIdx / pixelsPerHRect;
			int rectIdxW = colIdx / pixelsPerWRect;
			CRTColor RGB = rectangle[rectIdxH * cols + rectIdxW];
			ppmFileStream << RGB.red << ' ' << RGB.green << ' ' << RGB.blue << '\n';
			ppmFileStream << randColor(255).red << ' ' << randColor(255).green<< ' ' << randColor(255).blue << '\t';
		}
		ppmFileStream << "\n";
	}

	for (int rowIdx = 0; rowIdx < pixelHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < pixelWidth; ++colIdx) {
			ppmFileStream << randColor(255).red << ' ' << randColor(255).green << ' ' << randColor(255).blue << '\t';
		}
		ppmFileStream << "\n";
	}
	ppmFileStream.close();
	std::cout << "File created successfully!";
	return 0;
}

