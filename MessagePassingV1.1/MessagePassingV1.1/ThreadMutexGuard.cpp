#include "ThreadMutexGuard.h"
ThreadMutexGuard::ThreadMutexGuard(ThreadMutex &lock) : theLock(&lock), isOwner(false) {
	acquire();
}  // Konstruktor

ThreadMutexGuard::~ThreadMutexGuard(void) {
	release();
}      // Destruktor
void ThreadMutexGuard::acquire(void) {			// Sperren
	theLock->acquire(WAIT);
	isOwner = true;  // nur, falls acquire erfolgreich abgeschlossen
}
void ThreadMutexGuard::release(void) { 			// Freigeben
	if (isOwner) {
		isOwner = false;
		theLock->release();
	}
}