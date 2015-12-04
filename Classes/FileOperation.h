#ifndef __HELLOWORLD_FILE_OPERATION__
#define __HELLOWORLD_FILE_OPERATION__

#include <string>

class FileOperation 
{
public:
	static void saveFile(const char*  Level);
	static int readFile();
	static std::string getFilePath();
};

#endif
