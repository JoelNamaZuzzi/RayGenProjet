#pragma once
#ifndef RAYGEN_IMG_H
#define RAYGEN_IMG_H

#include <vector>
#include <array>
#include <string>

#include"ImgType.h"
#include "../Tools/Color.h"

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

};

#endif //RAYGEN_IMG_H
