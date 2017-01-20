#include "Kanal.h"
#include <iostream>
using namespace std;


Kanal::Kanal()
{
}

Kanal::Kanal(int kanalNR)
{
	kanalNummer = kanalNR;
}

Kanal::Kanal(MessageQueue &mq, int kanalNR)
{
	messageQueue = mq;
	kanalNummer = kanalNR;
}


Kanal::~Kanal()
{
}

void Kanal::setMessageQueue(MessageQueue *mq)
{
	messageQueue = *mq;
	//
}

MessageQueue* Kanal::getMessageQueue()
{
	return &messageQueue;
}

void Kanal::addAktionManagaer(Aktionmanager am)
{
}
int Kanal::getKanalId()
{
	return kanalNummer;
}
