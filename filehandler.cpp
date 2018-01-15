

#include "filehandler.h"

int FileOps::writeToFile(const std::string &content, const std::string &filename) {

	std::fstream m_outFile;
	m_outFile.open(filename, std::ios::out);
	if (m_outFile.is_open()) {
		m_outFile.write(content.c_str(), content.length());
	}
	//cout << getFileLength(m_outFile) << endl;
	m_outFile.close();

	return 0;
}

FileOps::~FileOps() {
	m_File.close();
}

int FileOps::getFileLength(std::fstream &fileHandle) {

	int length;

	fileHandle.seekg(0, m_File.end);
	length = static_cast<int>(fileHandle.tellg());
	m_File.seekg(0, fileHandle.beg);

	return (length);
}

int FileOps::readFile(const std::string &fileName) {

	int fileSize = 0;
	std::string tmpStr;
	m_File.open(fileName, std::ios::in);
	if (m_File.is_open()) {
		fileSize = getFileLength(m_File);
		m_File.seekg(0, std::ios::beg);
		while (!m_File.eof()) {
			getline(m_File, tmpStr);
			m_Data = m_Data + tmpStr;
			tmpStr.clear();
		}
	}
	//cout << m_Data << endl;
	return 0;
}

std::string& FileOps::getInputText() {
	return m_Data;
}