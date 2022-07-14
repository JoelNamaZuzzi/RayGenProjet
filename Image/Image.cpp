#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <string>
#include "../Libs/stb_image.h"
#include "../Libs/stb_image_write.h"
#include "../Tools/Serializer.h"
#include "../Tools/StringRW.h"

Image::Image(const std::string &filename) {
	if (read(filename)) {
		std::cout << "Read " << filename << std::endl;
		path = filename;
		size = width * height * channel;
	}
	else {
		std::cout << "can't read " << filename << std::endl;
	}
}

Image::Image(const Image &img) :Image(img.getWidth(), img.getHeight()) {
	data = new uint8_t[img.getSize()];
	for (int i = 0; i < img.getSize(); i++) {
		data[i] = img.getData()[i];
	}
	leftUp = img.leftUp;
	rigthtDown = img.rigthtDown;
	path = img.path;
}

Image::~Image() {
	stbi_image_free(data);
}

bool Image::read(const std::string &filename) {
	data = stbi_load(filename.c_str(), &width, &height, &channel, 0);
	return data != nullptr;
}

ImageType Image::getImgType(const std::string &filename) {
	int pos = filename.find_last_of('.');
	if (pos != -1) {
		std::string ext = filename.substr(pos);
		strrw::toLower(&ext);
		if (ext == ".png") {
			return ImageType::PNG;
		}
		else if (ext == ".jpg") {
			return ImageType::JPG;
		}
	}
	return ImageType::PNG;
}

bool Image::write(const std::string &filename) {
	ImageType t = Image::getImgType(filename);
	int success;
	if (t == ImageType::PNG) {
		success = stbi_write_png(filename.c_str(), width, height, channel, data, width * channel);
	}
	else if (t == ImageType::JPG) {
		success = stbi_write_jpg(filename.c_str(), width, height, channel, data, 100);
	}
	return success != 0;
}

Color Image::operator()(const float &x, const float &y) const {
	return (*this)(Serializer::deserialize(x, 0, height - 1), Serializer::deserialize(y, 0, width - 1));
}

Color Image::operator()(const int &x, const int &y) const {
	Color pixel(0.75);
	if (channel == 1) {
		pixel[0] = Serializer::serialize(data[(x * 1 * width) + (y * 1)], 0, 255);
	}
	else if (channel == 2) {
		pixel[0] = Serializer::serialize(data[(x * 2 * width) + (y * 2)], 0, 255);
		pixel[1] = Serializer::serialize(data[(x * 2 * width) + (y * 2) + 1], 0, 255);
	}
	else if (channel == 3) {
		pixel[0] = Serializer::serialize(data[(x * 3 * width) + (y * 3)], 0, 255);
		pixel[1] = Serializer::serialize(data[(x * 3 * width) + (y * 3) + 1], 0, 255);
		pixel[2] = Serializer::serialize(data[(x * 3 * width) + (y * 3) + 2], 0, 255);
	}
	else if (channel == 4) {
		pixel[0] = Serializer::serialize(data[(x * 4 * width) + (y * 4)], 0, 255);
		pixel[1] = Serializer::serialize(data[(x * 4 * width) + (y * 4) + 1], 0, 255);
		pixel[2] = Serializer::serialize(data[(x * 4 * width) + (y * 4) + 2], 0, 255);
		pixel.A(Serializer::serialize(data[(x * 4 * width) + (y * 4) + 3], 0, 255));
	}
	return pixel;
}

void Image::operator()(const int &x, const int &y, const Color &color) {
	if (channel == 1) {
		data[(x * 1 * width) + (y * 1)] = Serializer::deserialize(color[0], 0, 255);
	}
	else if (channel == 2) {
		data[(x * 2 * width) + (y * 2)] = Serializer::deserialize(color[0], 0, 255);
		data[(x * 2 * width) + (y * 2) + 1] = Serializer::deserialize(color[1], 0, 255);
	}
	else if (channel == 3) {
		data[(x * 3 * width) + (y * 3)] = Serializer::deserialize(color[0], 0, 255);
		data[(x * 3 * width) + (y * 3) + 1] = Serializer::deserialize(color[1], 0, 255);
		data[(x * 3 * width) + (y * 3) + 2] = Serializer::deserialize(color[2], 0, 255);
	}
	else if (channel == 4) {
		data[(x * 4 * width) + (y * 4)] = Serializer::deserialize(color[0], 0, 255);
		data[(x * 4 * width) + (y * 4) + 1] = Serializer::deserialize(color[1], 0, 255);
		data[(x * 4 * width) + (y * 4) + 2] = Serializer::deserialize(color[2], 0, 255);
		data[(x * 4 * width) + (y * 4) + 3] = Serializer::deserialize(color.A(), 0, 255);
	}
}