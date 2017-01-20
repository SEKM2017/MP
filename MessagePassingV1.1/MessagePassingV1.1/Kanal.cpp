#include "Kanal.h"
#include <iostream>
using namespace std;


Kanal::Kanal()
{
}

Kanal::Kanal(int kanalNR)
{
	kanalNummer = kanalNR;
	setMessageQueue(DefinedslotLen, DefinedslotCount);
}
Kanal::Kanal(int kanalNR, int slotLen, int slotCount)
{
	kanalNummer = kanalNR;
	setMessageQueue(slotLen, slotCount);
}

Kanal::Kanal(MessageQueue *mq, int kanalNR)
{
	messageQueue = mq;
	kanalNummer = kanalNR;
}


Kanal::~Kanal()
{
	//Hier muss noch der Speicher freigegeben werden
}

bool Kanal::setMessageQueue(int slotLen, int slotCount)
{
	bool result = false;

	messageQueue = new MessageQueue();
	messageQueue->setSlotLen(slotLen);
	messageQueue->setSlotCount(slotCount);
	
	result = true;

	return result;
}

MessageQueue* Kanal::getMessageQueue()
{
	return messageQueue;
}

void Kanal::addAktionManagaer(Aktionmanager am)
{
}
int Kanal::getKanalNummer()
{
	return kanalNummer;
}
