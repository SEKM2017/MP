#pragma once
#include "ThreadMutex.h"
#define UNUSED_ARG(arg) {if (&arg) /* do nothing */ ; }

class ThreadMutexGuard // Wächterklasse
{
public:
	ThreadMutexGuard(ThreadMutex &lock);
	~ThreadMutexGuard(void);
	void acquire(void);
	void release(void);
private:
	ThreadMutex *theLock;  // Zeiger auf die Sperre
	bool isOwner;		// Vermerk, ob Sperre noch akquiriert
	ThreadMutexGuard(const ThreadMutexGuard &); // Kopierschutz
	void operator= (const ThreadMutexGuard &); //Schutz vor Zuweisung
};
