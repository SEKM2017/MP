#pragma once
#include "Kanal.h"

class KanalListe
{
private:
	int anzahlMaxKanaele=10;
	int listCounter=0;
	Kanal liste[10];
	static KanalListe* theExemplar;
	MessageQueue *mq;
public:
	KanalListe();
	~KanalListe();
	void add(Kanal *kanal, int slotLen, int slotCount);
	static KanalListe* Exemplar();
	Kanal findKanalById(int kanalNummer);
};

