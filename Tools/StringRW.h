#pragma once
#ifndef RAYGEN_STRRW_H
#define RAYGEN_STRRW_H

#include <string>
#include <iostream>

namespace strrw {
	void toLower(std::string *str) {
		for (char &c : *str) {
			c = std::tolower(c);
		}
	};

	std::string toLowerCopy(const std::string &str) {
		std::string res;
		for (char c : str) {
			res += std::tolower(c);
		}
		return res;
	};

	void toUpper(std::string *str) {
		for (char& c : *str) {
			c = std::toupper(c);
		}
	};

	int strToInt(const std::string &val) {
		try {
			return std::stoi(val);
		}
		catch (std::invalid_argument const& e) {
			std::cout << "not int" << std::endl;

		}
		catch (std::out_of_range const& e) {
			std::cout << "int overflow" << std::endl;
		}
		return 0;
	}
}

#endif //RAYGEN_STRRW_H