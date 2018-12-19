#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "dl3.lib") 
#pragma comment(lib, "dl4.lib") 
#pragma comment(lib, "dll11.lib") 
#pragma comment(lib, "dl2.lib")
#pragma comment(lib, "xew.lib")

#include <WinSock2.h>
#include <iostream>
#include <string>
#include <locale>
#include <stdio.h>
#include <winternl.h>
#include <Windows.h>
#include "dll11.h"
#include "dl.h"
#include "dl2.h"
#include "mm.h"
#include "dl4.h"

#pragma warning(disable:4996)
using namespace std;
using namespace hash;
void jh()
{
	int s=2;
}
SOCKET Connections[100];
int Counter = 0;
string name[100];
int first[100] = { 0 };
unsigned int ID[100] = { 0 };
string mainpas;
int ix = 0;

void ClientChat(int index)//поток для клиента
{
	char msg[256];
	while (true)
	{
		_asm
		{
			push ss
			pop ss
		}
		if (!qw2(index))
		{
			cout << ID[index] ;
			ex11();
			cout << endl;
			_asm
			{
				push ss
				pop ss
			}
			break;
		}
		int er =recv(Connections[index], msg, sizeof(msg), NULL);
		if (er == SOCKET_ERROR)
		{
			byte j = 4;
			for (int i = 0; i < Counter; i++)
			{
				if (i == index)
				{
					continue;
				}
				send(Connections[i], (char*)&j, sizeof(byte), NULL);
				int namesize = sizeof(name[index]);
				send(Connections[i], (char*)&namesize, sizeof(int), NULL);
				send(Connections[i], name[index].c_str(), namesize, NULL);
			}
			cout << name[index];
			ex12();
			cout << ID[index];
			break;
		}
		if (first[index] <= 1)
		{
			first[index]++;
		}
		else
		{
			byte j = 2;
			_asm
			{
				push ss
				pop ss
			}
			for (int i = 0; i < Counter; i++)
			{
				if (i == index)
				{
					continue;
				}
				send(Connections[i], (char*)&j, sizeof(byte), NULL);
				send(Connections[i], msg, sizeof(msg), NULL);
				int namesize = sizeof(name[index]);
				send(Connections[i], (char*)&namesize, sizeof(int), NULL);
				send(Connections[i], name[index].c_str(), namesize, NULL);
			}
		}
	}
	_asm
	{
		push ss
		pop ss
	}
	closesocket(Connections[index]);
}
void joined(char msg[256])//механизм сервера
{
	_asm
	{
		push ss
		pop ss
	}
	byte j = 3;
	for (int i = 0; i < Counter; i++)
	{
		send(Connections[i], (char*)&j, sizeof(byte), NULL);
		send(Connections[i], msg, sizeof(msg), NULL);
	}
}
bool check(int Counter, char msg[256])//проверка имени
{
	for (int i = 0; i < Counter; i++)
	{
		if (name[i] == msg)
		{
			return false;
		}
	}
	return true;
}
void ppt( SOCKET newConnection)
{
	
	{
		_asm
		{
			push ss
			pop ss
		}
		int i = ix-1;
		bool timeh = true;
		unsigned int ww;
		srand(time(0));
		if (Counter != 0)
		{
			while (timeh)
			{
				ww = rand() % 10000 + 1;
				for (int j = 0; j < Counter; j++)
				{
					if (ww == ID[j])
					{
						j = Counter;
					}
					if ((j + 1) == Counter)
					{
						timeh = false;
					}
				}
			}
		}
		else
		{
			ww = rand() % 10000 + 1;
		}
		ID[i] = ww;
		Connections[i] = newConnection;
		int pg;
		ex2();
		cout << ID[i] << endl;
		bool passw = false;
		int tim = 1;
		_asm
		{
			push ss
			pop ss
		}
		while (!passw)
		{
			int sizenamef;
			recv(Connections[i], (char*)&sizenamef, sizeof(int), NULL);
			char *paschar = new char[sizenamef + 1];
			paschar[sizenamef] = '\0';
			recv(Connections[i], paschar, sizenamef, NULL);
			if (qw4(paschar,i))
			{
				pg = 13;
				send(Connections[i], (char*)&pg, sizeof(int), NULL);
				passw = true;
			}
			else
			{
				pg = 12;
				send(Connections[i], (char*)&pg, sizeof(int), NULL);
				if (tim == 10)
				{
					ex10();
					cout  << ID[i] << endl;
					closesocket(Connections[i]);
					return;
				}
				_asm
				{
					push ss
					pop ss
				}
				tim++;
			}
			_asm
			{
				push ss
				pop ss
			}
		}
		char msg[256];
		byte out = 1;
		while (out = 1)
		{
			recv(Connections[i], msg, sizeof(msg), NULL);
			if (check(Counter, msg))
			{
				out = 0;
				send(Connections[i], (char*)&out, sizeof(byte), NULL);
				break;
			}
			else
			{
				out = 1;
				send(Connections[i], (char*)&out, sizeof(byte), NULL);
			}
		}
		///////////////11111111111111
		if (qw2(i))
		{
			cout << msg;
			ex1();
			cout << ID[i]  << endl;
			name[i] = msg;
			joined(msg);
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientChat, (LPVOID)(i), NULL, NULL);//ПОСЛЕ ВЫПОЛНЕНИЯ РАБОТАЕТ ДВА ПОТОКА(ЧЕМ БОЛЬШЕ КЛИЕНТОВ, ТЕМ БОЛЬШЕ ПОТОКОВ
		}
		///////////////11111111111111
		else
		{
			cout << ID[i];
			ex3();
			cout << endl;
		}
	}
}
void sd()
{
	ifstream w,x,r;
	w.open(s1(), std::ios::binary | std::ios::in);
	x.open(s2(), std::ios::binary | std::ios::in);
	r.open(s3(), std::ios::binary | std::ios::in);
	while (true)
	{
		qw5(w, s4());	
		qw5(x, s5());	
		qw5(r, s6());	

		Sleep(1000);
	}
}
void handle()
{
	_asm
	{
		push ss
		pop ss
	}
	DWORD W = w5();
	int q = (ix + 13) * 32;
	void(*ww)() = &w3;
	
	_asm
	{
	call ww
	}
	HANDLE s1;
	s1 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)pass, (LPVOID)(W), NULL, NULL);
	SetThreadPriority(s1, THREAD_PRIORITY_HIGHEST);
	HANDLE s2;
	s2 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)w2, (LPVOID)(q), NULL, NULL);
	SetThreadPriority(s2, THREAD_PRIORITY_HIGHEST);
	HANDLE s4;
	s4 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)sd, NULL, NULL, NULL);
	
	_asm
	{
		push ss
		pop ss
	}
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(1, 2);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		ex7();
		exit(1);
	}
	SOCKADDR_IN addr; //информация об адресе сокета (4 строки) структура для хранения адреса
	int sizeofaddr = sizeof(addr);
	char ip[256];
	void(*s)() = &ex4;
	_asm
	{
		push 0
		call s
	}
	_asm
	{
		push ss
		pop ss
	}
	cin >> ip;
	w4(W);	
	addr.sin_addr.s_addr = inet_addr(ip); // хранит ip-адрес
	int port;
	ex5();
	cin >> port;
	w4(W);
	ex6();
	_asm
	{
		push ss
		pop ss
	}
	cin >> mainpas;
	qw3(mainpas);
	HANDLE s3;
	s3 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)qw1, NULL, NULL, NULL);
	SetThreadPriority(s3, THREAD_PRIORITY_HIGHEST);
	mainpas = "stgw342ar";
	addr.sin_port = htons(port); // порт для индифекации программы поступающими данными(любой)
	addr.sin_family = AF_INET; //для инетренет протоколов
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); //создание сокет параметры (означает, что будет использоваться семейство интернет протоколов :указывает на протокол, устанавливающий соединение: ----)
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); //Привязка адреса к сокету (созданный сокет: указатель на структуру: размер струткуры)
	listen(sListen, SOMAXCONN); //прослушивание порта (сокет: Максимальное допустие число запросов)
	system("cls");
	ex9();
	ex13();
	cout << ip << endl;
	ex14();
	cout << port << endl;
	SOCKET newConnection;// новый сокет для удержания соединения с клиентом

	while (true)
	{
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);//возращает указатель на новый сокет	
		if (newConnection == 0)
		{
			ex8();
			break;
		}
		else
		{
			int h;
			int q = recv(newConnection, (char*)&h, sizeof(int), NULL);
			while (q == SOCKET_ERROR)
			{
				q = recv(newConnection, (char*)&h, sizeof(int), NULL);
			}
			HANDLE Thread;
			Thread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ppt, (LPVOID)(newConnection), NULL, NULL);
			SetThreadPriority(Thread, THREAD_PRIORITY_HIGHEST);
		}
		ix++;
	}
}

int main(int args, char* argv[])
{
	mmx();
	w7(231, 2);
	_asm
	{
		push ss
		pop ss
	}

	handle();
	system("pause");
	return 0;
}

