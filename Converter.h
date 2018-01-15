#pragma once

#include <string>
#include "filehandler.h"

const std::string INDEX_TABLE = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/" };

class Converter {
public:
	Converter() = default;
	~Converter() {};
	std::string encode(const std::string &input);
	std::string decode(const std::string &input);
private:
	std::string getBinary(const char &ch, const int digits = 8);
	char getBase64Chr(const std::string &binary);
	char getASCIIChr(const std::string &binary);
	std::string processOctets(const std::string octStr);
	std::string processGrpFour(const std::string inStr);
	void addPadding(std::string &inputStr);
	void removePadding(std::string &inputStr);
	int findIndex(const char &ch);
};
