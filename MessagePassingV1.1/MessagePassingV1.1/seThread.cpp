#include "seThread.h"

seThread::seThread(LPTHREAD_START_ROUTINE execute) {
	tRoutine = execute;
}

seThread::~seThread(void) {
	if (hThread != NULL) {
		CloseHandle(hThread);  // Thread schlieﬂen
	}
}

int seThread::checkCreationSuccess(void) {
	return isActive;
}

int seThread::execute(LPVOID lpParam) {

	hThread = CreateThread(
		NULL,                        // default security attributes 
		0,                           // use default stack size  
		tRoutine,                    // thread function 
		lpParam,                     // argument to thread function 
		0,                           // use default creation flags 
		&dwThreadId);                // returns the thread identifier
	isActive = hThread != NULL ? 1 : 0;
	return isActive;
}
