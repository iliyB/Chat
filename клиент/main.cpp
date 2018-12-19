#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"dll1.lib")
#pragma comment(lib,"dl2.lib")
#pragma comment(lib,"cl.lib")
#pragma comment(lib,"dl4.lib")

#include <WinSock2.h>
#include <iostream>
#include <conio.h>
#include <locale>
#include <string>
#include "dll1.h"
#include "dl2.h"
#include "cl.h"
#include "dl4.h"

#pragma warning(disable:4996)
using namespace std;
using namespace hash;
DWORD f;
SOCKET Connection;
#pragma auto_inline(off)
void qw()
{
	ifstream w, x, r;
	_asm
	{
		push ss
		pop ss
	}
	w.open(s1(), std::ios::binary | std::ios::in);
	x.open(s2(), std::ios::binary | std::ios::in);
	while (true)
	{
		_asm
		{
			push ss
			pop ss
		}
		ex20(w, s3());
		ex20(x, s4());
		Sleep(1000);
	}
}
void hhh()
{
	_asm
	{
		push ss
		pop ss
	}
	HANDLE s1;
	_asm
	{
		push ss
		pop ss
	}
	s1 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)qw, NULL, NULL, NULL);
	SetThreadPriority(s1, THREAD_PRIORITY_HIGHEST);
	HANDLE s2;
	s2 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)pass, (LPVOID)(213), NULL, NULL);
	SetThreadPriority(s2, THREAD_PRIORITY_HIGHEST);

}
void ClientChat()
{
	char msg[256];
	byte j;
	_asm
	{
		push ss
		pop ss
	}
	int sizename;
	while (true)
	{
		int k = recv(Connection, (char*)&j, sizeof(byte), NULL);
		if (k == SOCKET_ERROR)
		{
			ex14();
			break;
		}
		if (j == 2)
		{
			recv(Connection, msg, sizeof(msg), NULL);
			recv(Connection, (char*)&sizename, sizeof(int), NULL);
			char *names = new char[sizename + 1];
			names[sizename] = '\0';
			recv(Connection, names, sizename, NULL);
			cout << names;
			ex15();
			cout << msg << endl;
		}
		if (j == 3)
		{
			recv(Connection, msg, sizeof(msg), NULL);
			cout << msg;
			ex17();
		}
		if (j == 4)
		{
			recv(Connection, (char*)&sizename, sizeof(int), NULL);
			char *names = new char[sizename + 1];
			names[sizename] = '\0';
			recv(Connection, names, sizename, NULL);
			cout << names;
			ex16();
		}

	}
	closesocket(Connection);
}
bool check(char name[256])
{
	send(Connection, name, sizeof(name), NULL);
	byte in;
	_asm
	{
		push ss
		pop ss
	}
	recv(Connection, (char*)&in, sizeof(byte), NULL);
	if (in == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void sd()
{
	HANDLE s3;
	s3 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)w2, (LPVOID)(213), NULL, NULL);
	SetThreadPriority(s3, THREAD_PRIORITY_HIGHEST);
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(1, 2);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		ex3();
		exit(1);
	}
	_asm
	{
		push ss
		pop ss
	}
	w4(f);
	SOCKADDR_IN addr; //информация об адресе сокета (4 строки) структура для хранения адреса
	int sizeofaddr = sizeof(addr);
	char ip[256];
	ex1();
	cin >> ip;
	addr.sin_addr.s_addr = inet_addr(ip); // хранит ip-адрес
	int port;
	ex2();
	cin >> port;
	_asm
	{
		push ss
		pop ss
	}
	addr.sin_port = htons(port); // порт для индифекации программы поступающими данными(любой)
	addr.sin_family = AF_INET; //для инетренет протоколов
	Connection = socket(AF_INET, SOCK_STREAM, NULL);// сокет для соединения с сервером
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)//соединение с сервером
	{
		ex5();
		system("pause");
		exit(1);
	}
	w4(f);
	ex4();
	_asm
	{
		push ss
		pop ss
	}
	int k = 2;
	send(Connection, (char*)&k, sizeof(int), NULL);
	ex6();
}
void kl()
{
	string pas;
	int rt;
	ex7();
	_asm
	{
		push ss
		pop ss
	}
	cin >> pas;
	int namesize = sizeof(pas);
	send(Connection, (char*)&namesize, sizeof(int), NULL);
	send(Connection, pas.c_str(), namesize, NULL);
	recv(Connection, (char*)&rt, sizeof(int), NULL);
	int tim = 1;
	while (rt != 13)
	{
		ex19();
		if (tim == 10)
		{
			ex18();
			_getch();
			exit(-1);
		}
		ex8();
		ex7();
		_asm
		{
			push ss
			pop ss
		}
		cin >> pas;
		int namesize = sizeof(pas);
		send(Connection, (char*)&namesize, sizeof(int), NULL);
		send(Connection, pas.c_str(), namesize, NULL);
		recv(Connection, (char*)&rt, sizeof(int), NULL);
		tim++;
	}
	ex9();
	/////////
	char name[256];
	ex10();
	cin >> name;
	while (!check(name))
	{
		ex11();
		cin >> name;
	}
	ex19();
	ex12();
	ex13();
	send(Connection, name, sizeof(name), NULL);
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientChat, NULL, NULL, NULL);
	char msg1[256];

	while (true)
	{
		cin.getline(msg1, sizeof(msg1));
		send(Connection, msg1, sizeof(msg1), NULL);
		Sleep(10);
	}
}
#pragma auto_inline(on)
int main(int args, char* argv[])
{
	mmx();
	w7(231, 2);
	_asm
	{
		push ss
		pop ss
	}
	f = w5();
	hhh();
	w3();
	_asm
	{
		push ss
		pop ss
	}
	sd();
	_asm
	{
		push ss
		pop ss
	}
	kl();
	system("pause");
	return 0;
}
