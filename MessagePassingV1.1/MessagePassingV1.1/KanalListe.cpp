#include "KanalListe.h"

KanalListe::KanalListe()
{
	
}


KanalListe::~KanalListe()
{
}

void KanalListe::add(Kanal *kanal)
{
	liste[listCounter] = *kanal;
	listCounter++;
}

KanalListe* KanalListe::theExemplar = 0;
KanalListe * KanalListe::Exemplar()
{
	if (theExemplar == 0)
	{
		theExemplar = new KanalListe;
	}
	return (theExemplar);
}

Kanal KanalListe::findKanalById(int kanalNummer)
{
	throw "Not implemented yet";
}