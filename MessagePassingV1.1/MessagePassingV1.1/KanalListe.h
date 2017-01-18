#pragma once
#include "Kanal.h"
class KanalListe
{
private:
	int anzahlMaxKanaele;
	//Kanal liste[];
	static KanalListe* theExemplar;
public:
	KanalListe();
	~KanalListe();
	void add(Kanal Kanal);
	static KanalListe* Exemplar();
	Kanal findKanalById(int kanalNummer);
};

