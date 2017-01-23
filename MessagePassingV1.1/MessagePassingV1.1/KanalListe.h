#pragma once
#include "Kanal.h"
#define MaxKanaele 10
class KanalListe
{
private:
	int anzahlMaxKanaele= MaxKanaele;
	int listCounter=0;
	Kanal liste[MaxKanaele];
	static KanalListe* theExemplar;
protected:
	KanalListe();
	KanalListe(const KanalListe&);
	KanalListe& operator= (const KanalListe&);
	~KanalListe();
public:
	int getAnzahlMaxKanaele();
	bool add(Kanal *kanal);
	bool destroy(int kanalNummer);
	static KanalListe* Exemplar();
	Kanal* findKanalById(int kanalNummer);
};

