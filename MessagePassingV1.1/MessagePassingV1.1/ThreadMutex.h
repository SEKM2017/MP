#pragma once
#define _WIN32_WINNT 0x0403

#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <time.h>
#include <sys/timeb.h>
#include <stdio.h>
#define WAIT TRUE
#define NOWAIT FALSE

class ThreadMutex
{
public:
	ThreadMutex(void);  // Konstruktor
	~ThreadMutex(void);  // Destruktor
	void acquire(bool waitOnEntry); // Sperren
	void release(void); // Freigeben
private:
	CRITICAL_SECTION theMutex; // WIN32 Mutex Mechanismus
	bool isInitialized;
	ThreadMutex(const ThreadMutex &); // Kopierschutz ThreadMutex
	//void operator= (const ThreadMutex &); //Schutz vor Zuweisung ThreadMutex
};

