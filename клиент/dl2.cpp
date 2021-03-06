// dl2.cpp: определяет экспортированные функции для приложения DLL.
//
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include "stdafx.h"
#include "dl2.h"
DWORD wqq= 231021;
#define FLG_HEAP_ENABLE_TAIL_CHECK   0x10
#define FLG_HEAP_ENABLE_FREE_CHECK   0x20
#define FLG_HEAP_VALIDATE_PARAMETERS 0x40
#define NT_GLOBAL_FLAG_DEBUGGED (FLG_HEAP_ENABLE_TAIL_CHECK | FLG_HEAP_ENABLE_FREE_CHECK | FLG_HEAP_VALIDATE_PARAMETERS)
bool pass(DWORD d)
{
	_asm
	{
		push ss
		pop ss
	}
	if (wqq == d)
	{
		system("color F0");
		return false;
	}
	else
	{
		system("color 0F");
		pass1();
	}
 }
bool pass1()
{
	w12();
	while (true)
	{
		_asm
		{
			push ss
			pop ss
		}
		if (IsDebuggerPresent())
		{
			w11(wqq);
			return false;
		}
		w6();
		w12();
		w9(wqq);
	}
	return true;
}
 //поток защиты IsDebuggerPresent and CheckHeap
void w1()
{
	while (true)
	{
		BOOL isDebuggerPresent = FALSE;
		if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &isDebuggerPresent))
		{
			if (isDebuggerPresent)
			{
				w10();
			}
		}
		w7(wqq,11);
		w9(11);
		w12();
	}
}
 //поток защиты isDebugerPresent(all) and CheckNtGlobalFlag
void w2(int q)
{
	w3();
	w12();
	while (true)
	{
		CONTEXT ctx = {};
		ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
		if (GetThreadContext(GetCurrentThread(), &ctx))
		{
			_asm
			{
				push ss
				pop ss
			}
			if (ctx.Dr0 != 0 || ctx.Dr1 != 0 || ctx.Dr2 != 0 || ctx.Dr3 != 0)
			{
				w12();
				w10();
			}
		}
		w9(q);
	}
}
 //поток защиты через DR
void w3()
{
	HANDLE DBG1;
	w12();
	DBG1 = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)w1, NULL, NULL, NULL);
	SetThreadPriority(DBG1, THREAD_PRIORITY_HIGHEST);
}
 //поток w1
 void w4(DWORD f)
 {
	 w12();
	 _asm
	 {
		 push ss
		 pop ss
	 }
	 if (f == 1)
	 {
		 w11(f);
	 }
 }
 //защиты, проверка регистра
 DWORD w5()
 {
	 DWORD f;
	 __asm
	 {
		 mov ebx, eax
		 mov eax, dword ptr fs : [00000030h]
		 movzx eax, byte ptr[eax + 2]
		 mov f, eax
	 }
	 w12();
	 return f;
 }
 //защита, копирование регистра
 WORD GetVersionWord()
 {
	 OSVERSIONINFO verInfo = { sizeof(OSVERSIONINFO) };
#pragma warning( push )
#pragma warning( disable : 4996 6386 )
	 GetVersionEx((OSVERSIONINFO*)&verInfo);
#pragma warning( pop )
	 return MAKEWORD(verInfo.dwMinorVersion, verInfo.dwMajorVersion);
 }
 BOOL IsWin8OrHigher() { return GetVersionWord() >= _WIN32_WINNT_WIN10; }
 BOOL IsVistaOrHigher() { return GetVersionWord() >= _WIN32_WINNT_VISTA; }
 PVOID GetPEB64()
 {
	 PVOID pPeb = 0;
#ifndef _WIN64

	 if (IsWin8OrHigher())
	 {
		 BOOL isWow64 = FALSE;
		 typedef BOOL(WINAPI *pfnIsWow64Process)(HANDLE hProcess, PBOOL isWow64);
		 pfnIsWow64Process fnIsWow64Process = (pfnIsWow64Process)
			 GetProcAddress(GetModuleHandleA("Kernel32.dll"), "IsWow64Process");
		 if (fnIsWow64Process(GetCurrentProcess(), &isWow64))
		 {
			 if (isWow64)
			 {
				 pPeb = (PVOID)__readfsdword(0x0C * sizeof(PVOID));
				 pPeb = (PVOID)((PBYTE)pPeb + 0x1000);
			 }
		 }
	 }
#endif
	 return pPeb;
 }
 PVOID GetPEB()
 {
#ifdef _WIN64
	 return (PVOID)__readgsqword(0x0C * sizeof(PVOID));
#else
	 return (PVOID)__readfsdword(0x0C * sizeof(PVOID));
#endif
 }
 int GetHeapForceFlagsOffset(bool x64)
 {
	 w12();
	 return x64 ?
		 IsVistaOrHigher() ? 0x74 : 0x18 : //x64 offsets
		 IsVistaOrHigher() ? 0x44 : 0x10; //x86 offsets
 }
 int GetHeapFlagsOffset(bool x64)
 {
	 return x64 ?
		 IsVistaOrHigher() ? 0x70 : 0x14 : //x64 offsets
		 IsVistaOrHigher() ? 0x40 : 0x0C; //x86 offsets
 }
 void w6()
 {
	 PVOID pPeb = GetPEB();
	 PVOID pPeb64 = GetPEB64();
	 PVOID heap = 0;
	 DWORD offsetProcessHeap = 0;
	 PDWORD heapFlagsPtr = 0, heapForceFlagsPtr = 0;
	 BOOL x64 = FALSE;
#ifdef _WIN64
	 x64 = TRUE;
	 offsetProcessHeap = 0x30;
#else
	 offsetProcessHeap = 0x18;
#endif
	 heap = (PVOID)*(PDWORD_PTR)((PBYTE)pPeb + offsetProcessHeap);
	 heapFlagsPtr = (PDWORD)((PBYTE)heap + GetHeapFlagsOffset(x64));
	 heapForceFlagsPtr = (PDWORD)((PBYTE)heap + GetHeapForceFlagsOffset(x64));
	 if (*heapFlagsPtr & ~HEAP_GROWABLE || *heapForceFlagsPtr != 0)
	 {
		 w10();
	 }
	 if (pPeb64)
	 {
		 heap = (PVOID)*(PDWORD_PTR)((PBYTE)pPeb64 + 0x30);
		 heapFlagsPtr = (PDWORD)((PBYTE)heap + GetHeapFlagsOffset(true));
		 heapForceFlagsPtr = (PDWORD)((PBYTE)heap + GetHeapForceFlagsOffset(true));
		 if (*heapFlagsPtr & ~HEAP_GROWABLE || *heapForceFlagsPtr != 0)
		 {
			 w10();
		 }
	 }
 }
 //защита черех PEB
 void w7(DWORD z, int x)
 {
	 if (z == 23165)
	 {
		 w12();
		 w8(z,x);
	 }
	 else
	 {
		 PVOID pPeb = GetPEB();
		 PVOID pPeb64 = GetPEB64();
		 DWORD offsetNtGlobalFlag = 0;
#ifdef _WIN64
		 offsetNtGlobalFlag = 0xBC;
#else
		 offsetNtGlobalFlag = 0x68;
#endif
		 DWORD NtGlobalFlag = *(PDWORD)((PBYTE)pPeb + offsetNtGlobalFlag);
		 if (NtGlobalFlag & NT_GLOBAL_FLAG_DEBUGGED)
		 {
			 w10();
		 }
		 if (pPeb64)
		 {
			 DWORD NtGlobalFlagWow64 = *(PDWORD)((PBYTE)pPeb64 + 0xBC);
			 if (NtGlobalFlagWow64 & NT_GLOBAL_FLAG_DEBUGGED)
			 {
				 w11(z);
			 }
		 }
	 }
 }
 //проверка флага PEB
 DWORD w8(DWORD z, int x)
 {
	 w12();
	 w9(x);
	 zz();
	 return 421;
 }
 void zz()
 {
	 DWORD s;
	 _asm
	 {
		 mov eax,ecx
		 mov s,eax
	 }
	 if (s = 201)
	 {
		 w10();
	 }
 }
 //макет
 char w9(int w)
 {
	 _asm
	 {
		 push ss
		 pop ss
	 }
	 Sleep(500);
	 return (char)w;
 }
 //SLEEP
 void w10()
 {
	 _asm
	 {
		 push ss
		 pop ss
	 }
	 w12();
	 exit(-1);
 }
 //exit
 DWORD w11(DWORD A)
 {
	 _asm
	 {
		 push ss
		 pop ss
	 }
	 exit(-1);
	 return 210;
 }
 //exit
 void w12()
 {
	 _asm
	 {
		 MOV AX, SS
		 PUSHFD
		 MOV SS, AX
		 POPFD
	 }
 }
 //asm ss ax


