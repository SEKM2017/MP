#include "KanalListe.h"

KanalListe::KanalListe()
{
}


KanalListe::~KanalListe()
{
}

bool KanalListe::add(Kanal *kanal,int slotLen, int slotCount)
{
	bool result = false;
	if (listCounter < anzahlMaxKanaele)
	{
		kanal->setMessageQueue(slotLen, slotCount);
		liste[listCounter] = *kanal;
		listCounter++;
		result = true;
	}

	return result;
}

bool KanalListe::destroy(int kanalNummer)
{
	bool result = false;
	int i;
	Kanal *kanal;

	kanal = theExemplar->findKanalById(kanalNummer);

	if (kanal != NULL)
	{
		kanal->~Kanal();
		result = true;
	}

	return result;

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

Kanal* KanalListe::findKanalById(int kanalNummer)
{
	int i;
	Kanal *gesuchterKanal;

	gesuchterKanal = new Kanal();

	for (i = 0; i < anzahlMaxKanaele; i++)
	{	
		*gesuchterKanal = liste[i];
		if (gesuchterKanal->getKanalId() == kanalNummer)
		{
			break;
		}
	}

	return gesuchterKanal;
}