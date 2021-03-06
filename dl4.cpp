// dl4.cpp: определяет экспортированные функции для приложения DLL.
//

#pragma comment(lib, "md5.lib")
#include "stdafx.h"
#include "md5.h"
#include "dl4.h"
#include <string>
#include <ctime>
#include <fstream> 

void mmx()
{
	ifstream inBigArrayfile;
	inBigArrayfile.open("ClientChat.exe", std::ios::binary | std::ios::in);

	//Find length of file
	inBigArrayfile.seekg(0, std::ios::end);
	long Length = inBigArrayfile.tellg();
	inBigArrayfile.seekg(0, std::ios::beg);

	//read in the data from your file
	char * InFileData = new char[Length];
	inBigArrayfile.read(InFileData, Length);

	//Calculate MD5 hash
	std::string Temp = md5::md5x(InFileData, Length);
	string q="43a18c8db13a27c5b2d461ee61e40169";
	if (md5::md5(Temp.c_str()) != q)
	{
		_asm
		{
			push ss
			pop ss
		}
		exit(-1);
	}
	//Clean up
	delete[] InFileData;
}
