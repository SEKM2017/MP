#pragma once
#include <windows.h>

class seThread
{
public:
	seThread(LPTHREAD_START_ROUTINE);
	~seThread(void);
	int checkCreationSuccess(void);
	int execute(LPVOID lpParam);
private:
	LPTHREAD_START_ROUTINE tRoutine;
	DWORD dwThreadId;
	DWORD dwThreadPar;
	HANDLE hThread;
	int isActive;
};
