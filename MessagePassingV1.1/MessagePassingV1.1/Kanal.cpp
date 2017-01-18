#include "Kanal.h"
#include <iostream>
using namespace std;


Kanal::Kanal()
{
}

Kanal::Kanal(MessageQueue &mq, int kanalNR)
{
	messageQueue = mq;
	KanalNummer = kanalNR;
}


Kanal::~Kanal()
{
}

void Kanal::setMessageQueue(MessageQueue mq)
{
	messageQueue = mq;
	//
}

MessageQueue Kanal::getMessageQueue()
{
	//return messageQueue;
	throw"NIY";
}

void Kanal::addAktionManagaer(Aktionmanager am)
{
}

