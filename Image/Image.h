#pragma once
#ifndef RAYGEN_IMG_H
#define RAYGEN_IMG_H

#include <vector>
#include <array>
#include <string>

#include"ImgType.h"
#include "../Tools/Color.h"

//instead of the usual, i will partially define the constructors in the .cpp to keep this file clear and define some function here

class Image
{
private:
	uint8_t *data = nullptr;
	size_t size = 0;
	int width;
	int height;
	int channel;
	std::array<int, 2> leftUp;
	std::array<int, 2> rigthtDown;
	std::string path;
public: 
	Image(const std::string &filename);
	Image(int w, int h, Color col) :width(w), height(h), channel(3) {
		size = width * height * channel;
		data = new uint8_t[size];

		for (int x = 0; x < width; ++x) {
			for (int y = 0; y < height; ++y) {
				(*this)(x, y, col);
			}
		}
	}
	Image(const Image &img);
	Image(int w, int h) : width(w), height(h), channel(3) {
		size = width * height * channel;
		data = new uint8_t[size];
	}
	~Image();

	//Load image
	bool read(const std::string &filename);
	//Write image
	bool write(const std::string &filename);

	Color operator()(const int &x, const int &y) const;
	Color operator()(const float &x, const float &y) const;
	void operator()(const int &x, const int &y, const Color &color);

	//image type
	static ImageType getImgType(const std::string &filename);

	int getWidth() const {
		return width;
	}

	int getHeight() const {
		return height;
	}

	inline int getChannel() const {
		return channel;
	}

	inline size_t getSize() const {
		return size;
	}

	inline uint8_t *getData() const {
		return data;
	}

	inline std::string getPath() const {
		return path;
	}

	inline std::array<int, 2> getLeftTop() {
		return leftUp;
	}

	inline void setLeftTop(std::array<int, 2> rt) {
		leftUp = rt;
	}

	inline std::array<int, 2> getRightBottom() {
		return rigthtDown;
	}

	inline void setRightBottom(std::array<int, 2> rb) {
		rigthtDown = rb;
	}
};

#endif //RAYGEN_IMG_H
