
#include <stdlib.h>
#include <bitset>
#include "Converter.h"

std::string Converter::encode(const std::string &input) {
	
	std::string grpFour, octetStr;
	int lastGrpChrCount = input.length() % 3;
	for (size_t i = 0; i < input.length()- lastGrpChrCount; i += 3) {
		octetStr = getBinary(input[i]) + getBinary(input[i + 1]) + getBinary(input[i + 2]);
		grpFour = grpFour + processOctets(octetStr);
		octetStr.clear();
	}

	if (lastGrpChrCount == 2)
		octetStr = getBinary(input[input.length() - 2]) + getBinary(input[input.length() - 1]) + "00000000";
	else if (lastGrpChrCount == 1)
		octetStr = getBinary(input[input.length() - 1]) + "00000000" + "00000000";
	
	if(lastGrpChrCount)
		grpFour = grpFour + processOctets(octetStr);

	return grpFour;
}

char Converter::getASCIIChr(const std::string &binary) {
	return static_cast<char>(strtol(binary.c_str(), nullptr, 2));
	
}
		
std::string Converter::processGrpFour(const std::string inStr) {
	
	std::string result = "";

	for (size_t i = 0; i < inStr.length(); i += 8) {
		result = result + getASCIIChr(inStr.substr(i, 8));
	}

	return result;
}


std::string Converter::processOctets(const std::string octStr) {

	std::string result = "";

	for (size_t i = 0; i < octStr.length(); i += 6) {
		result = result + getBase64Chr(octStr.substr(i, 6));
	}

	addPadding(result);
	return result;
}

void Converter::addPadding(std::string &inputStr) {
	
	if (inputStr[inputStr.length() - 2] == 'A')
		inputStr[inputStr.length() - 2] = '=';

	if (inputStr[inputStr.length() - 1] == 'A')
		inputStr[inputStr.length() - 1] = '=';
}

void Converter::removePadding(std::string &inputStr) {

	if (inputStr[inputStr.length() - 2] == '=')
		inputStr[inputStr.length() - 2] = 'A';

	if (inputStr[inputStr.length() - 1] == '=')
		inputStr[inputStr.length() - 1] = 'A';
}

std::string Converter::getBinary(const char &ch, const int digits) {
	if(digits == 8)
		return (std::bitset<8>(ch)).to_string();
	else 
		return (std::bitset<6>(ch)).to_string();
}

char Converter::getBase64Chr(const std::string &binary)
{
	return INDEX_TABLE[strtol(binary.c_str(), nullptr, 2)];
}

int Converter::findIndex(const char &ch) {
	return INDEX_TABLE.find(ch);
}

std::string Converter::decode(const std::string &input) {

	std::string wrkStr = input, grpFour, result = "";
	removePadding(wrkStr);

	for (size_t i = 0; i < wrkStr.length(); i += 4 ) {
		grpFour.clear();
		for (size_t j = i; j < i + 4; j++) {
			int index = findIndex(wrkStr[j]);
			grpFour = grpFour + (std::bitset<6>(index)).to_string();
		}
		result = result + processGrpFour(grpFour);
	}
	return result;
}
