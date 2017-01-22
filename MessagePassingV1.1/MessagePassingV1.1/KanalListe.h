#pragma once
#include "Kanal.h"

class KanalListe
{
private:
	int anzahlMaxKanaele=10;
	int listCounter=0;
	Kanal liste[10];
	static KanalListe* theExemplar;
public:
	KanalListe();
	~KanalListe();
	bool add(Kanal *kanal);
	bool destroy(int kanalNummer);
	static KanalListe* Exemplar();
	Kanal* findKanalById(int kanalNummer);
};

