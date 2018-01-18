
#include <iostream>
#include <string>
#include "filehandler.h"
#include "Converter.h"
#include "Base64.h"


int main() {

	Base64 appln;
	
	//Adding comments to test Git
	appln.encode("D:\\Projects\\Base64\\Ascii.txt", "D:\\Projects\\Base64\\Ascii_out.txt");
	appln.decode("D:\\Projects\\Base64\\Ascii.txt", "D:\\Projects\\Base64\\Ascii_out.txt");
	return 0;
}