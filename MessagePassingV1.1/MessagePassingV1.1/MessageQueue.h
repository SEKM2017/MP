#pragma once
#include <string>
#include "ThreadMutexGuard.h"
#define DefinedslotCount  10
using namespace std;

class MessageQueue
{
private: 
	int slotCount;
	int slotLen;
	string nachrichten[2][10];
	ThreadMutex theLock;
public:
	MessageQueue();
	~MessageQueue();
	int getSlotCount();
	void setSlotCount(int count);
	int getSlotLen();
	void setSlotLen(int len);
	bool schreiben(string nachricht);
	string lesen();
};

