#pragma once

#include <string>
#include <memory>
#include "Converter.h"
#include "filehandler.h"

class Base64 {
public:
	Base64();
	~Base64() {};
	void decode(const std::string &infile, const std::string &outfile);
	void encode(const std::string &infile, const std::string &outfile);
private:
	std::unique_ptr<Converter> mConverter;
	std::unique_ptr<FileOps> file;
};
