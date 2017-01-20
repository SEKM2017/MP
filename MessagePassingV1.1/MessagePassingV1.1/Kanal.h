#pragma once
#include "MessageQueue.h"
#include "Aktionmanager.h"
#include "AktionmanagerListe.h"
class Kanal
{
private:
	MessageQueue *messageQueue;
	int kanalNummer =-1;
	
	AktionmanagerListe aktionManagerList;
public:
	Kanal();
	Kanal(int kanalNR);
	Kanal(int kanalNR, int slotLen, int slotCount);
	Kanal(MessageQueue *mq, int kanalNR);
	~Kanal();
	bool setMessageQueue(int slotLen, int slotCount);
	MessageQueue* getMessageQueue();
	void addAktionManagaer(Aktionmanager am);
	int getKanalNummer();
};

