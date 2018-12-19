// dl3.cpp: определяет экспортированные функции для приложения DLL.
//

#pragma comment(lib,"md5.lib")
#include "stdafx.h"
#include "md5.h"
#include "dl3.h"
#include <string>
#include <ctime>
#include <fstream> 
using namespace std;
using namespace md5;
int as231[100] = { 8 };//23747
std::string lv1= "$2Фy!", lv2= "Ww+ч7>";
std::string qq= "5a18dc378ce59f81ce938fc9189e32ee";
void qw8()
{
	for (int i = 0; i < 100; i++)
	{
		as231[i] = 8;
	}
}
void qw3(std::string pasw)
{
	lv1 = sugar();
	lv2 = sugar();
	_asm
	{
		push ss
		pop ss
	}
	qq = md5::md5(md5::md5(pasw + lv1) + lv2);
	for (int i = 0; i < 100; i++)
	{
		as231[i] = 8;
	}
}
std::string sugar()
{
	srand(time(0));
	std::string sug;
	int time = rand() % 4 + 4;
	for (int i = 0; i < time; i++)
	{
		sug += (char)(int)(rand() % 256 - 128);
	}
	return sug;
}
bool qw2(int i)
{
	_asm
	{
		push ss
		pop ss
	}
	if (as231[i] != 23747)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void qw1()
{
	while (true)
	{
		for (int g = 0; g < 100; g++)
		{
			_asm
			{
				push ss
				pop ss
			}
			if ((as231[g] != 8) && (as231[g] != 23747))
			{
				_asm
				{
					push ss
					pop ss
				}
				exit(-1);
			}
		}
		Sleep(1000);
	}
}
bool qw4(std::string formerpa, int i)
{
	_asm
	{
		push ss
		pop ss
	}
	if (qq == md5::md5(md5::md5(formerpa + lv1) + lv2))
	{
		_asm
		{
			push ss
			pop ss
		}
		as231[i] = 23747;
		return true;
	}
	else
	{
		return false;
	}
}
void qw5(ifstream &d, std::string q)
{
	d.seekg(0, std::ios::end);
	long Length = d.tellg();
	d.seekg(0, std::ios::beg);
	//read in the data from your file
	char * InFileData = new char[Length];
	d.read(InFileData, Length);
	//Calculate MD5 hash
	std::string Temp = md5x(InFileData, Length);
	_asm
	{
		push ss
		pop ss
	}
	if (md5::md5(Temp.c_str()) != q)
	{
		_asm
		{
			push ss
			pop ss
		}
		exit(-1);
	}
}
DWORD qw6(PUCHAR funcBegin, PUCHAR funcEnd, DWORD wq,bool e)
{
	DWORD crc = 0;
	for (; funcBegin < funcEnd; ++funcBegin)
	{
		crc += *funcBegin * 2 + 5;
	}
	if (e)
	{
		if (wq != crc)
		{
			exit(-1);
		}
	}
	else
	{
		cout << crc << endl;
	}
	return wq;
}

