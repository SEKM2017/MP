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
	void add(Kanal *kanal);
	static KanalListe* Exemplar();
	Kanal findKanalById(int kanalNummer);
};

