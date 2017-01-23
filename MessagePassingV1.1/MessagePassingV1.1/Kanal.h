#pragma once
#include "MessageQueue.h"
class Kanal
{
private:
	MessageQueue *messageQueue;
	int kanalNummer =-1;
public:
	Kanal();
	Kanal(int kanalNR);
	Kanal(int kanalNR, int slotLen, int slotCount);
	Kanal(MessageQueue *mq, int kanalNR);
	~Kanal();
	bool setMessageQueue(int slotLen, int slotCount);
	MessageQueue* getMessageQueue();
	int getKanalNummer();
};

