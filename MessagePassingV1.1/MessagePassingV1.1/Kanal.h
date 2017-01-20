#pragma once
#include "MessageQueue.h"
#include "Aktionmanager.h"
#include "AktionmanagerListe.h"
class Kanal
{
private:
	MessageQueue messageQueue;
	int KanalNummer;
	
	AktionmanagerListe aktionManagerList;
public:
	Kanal();
	Kanal(int kanalNR);
	Kanal(MessageQueue &mq, int kanalNR);
	~Kanal();
	void setMessageQueue(MessageQueue mq);
	MessageQueue getMessageQueue();
	void addAktionManagaer(Aktionmanager am);
	
};

