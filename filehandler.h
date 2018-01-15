#pragma once

#include <fstream>
#include <string>

class FileOps {
public:
	FileOps() {};
	~FileOps();
	int readFile(const std::string &fileName);
	int writeToFile(const std::string &content, const std::string &filename);
	int getFileLength(std::fstream &fileHandle);
	std::string& getInputText();

private:
	std::string m_Data;
	std::fstream m_File;
};
