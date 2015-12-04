// to enable CCLOG()
#define COCOS2D_DEBUG 1

#include "cocos2d.h"
#include "FileOperation.h"
#include <stdio.h>

using namespace std;

void FileOperation::saveFile(const char* Level)
{
	string path = getFilePath();
	FILE *fp = fopen(path.c_str(), "w");

	if (!fp)
	{
		CCLOG("can not create file %s", path.c_str());
		return;
	}

	fputs(Level, fp);
	fclose(fp);
}

int FileOperation::readFile()
{
	string path = getFilePath();
	FILE *fp = fopen(path.c_str(), "r");
	char buf[50] = { 0 };

	char current[1] = { 0 };

	if (!fp)
	{
		CCLOG("can not open file %s", path.c_str());
		return 0;
	}

	fgets(buf, 50, fp);
	CCLOG("read content %s", buf);


	int level = 1;

	if (buf[0] == '2')
	{
		int level = 2;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '3')
	{
		int level = 3;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '4')
	{
		int level = 4;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '5')
	{
	    int level = 5;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '6')
	{
		int level = 6;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '7')
	{
		int level = 7;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '8')
	{
		int level = 8;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '9')
	{
		int level = 9;
		fclose(fp);
		return level;
	}
	else if (buf[0] == '1' && buf[1] == '0')
	{
		int level = 10;
		fclose(fp);
		return level;
	}
	
	fclose(fp);
	return level;

}

string FileOperation::getFilePath()
{
	string path("");

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	// In android, every programe has a director under /data/data.
	// The path is /data/data/ + start activity package name.
	// You can save application specific data here.
	path.append("/data/data/leandro.gecozo.ballshat/GameData.xml");
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	// You can save file in anywhere if you have the permision.
	path.append("E:/GameData.xml");
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WOPHONE)
	path = cocos2d::CCApplication::sharedApplication().getAppDataPath();

#ifdef _TRANZDA_VM_
	// If runs on WoPhone simulator, you should insert "D:/Work7" at the
	// begin. We will fix the bug in no far future.
	path = "D:/Work7" + path;
	path.append("tmpfile");
#endif

#endif

	return path;
}