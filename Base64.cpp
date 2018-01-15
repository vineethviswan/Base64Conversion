
#include <memory>
#include "Base64.h"

Base64::Base64() {
	mConverter = std::make_unique<Converter>();
	file = std::make_unique<FileOps>();
}

void Base64::encode(const std::string &infile, const std::string &outfile) {
	file->readFile(infile);
	std::string opStr = mConverter->encode(file->getInputText());
	file->writeToFile(opStr, outfile);
}

void Base64::decode(const std::string &infile, const std::string &outfile) {
	file->readFile(infile);
	std::string opStr = mConverter->decode(file->getInputText());
	file->writeToFile(opStr, outfile);
}