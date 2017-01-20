#include "KanalListe.h"

KanalListe::KanalListe()
{
	
}


KanalListe::~KanalListe()
{
}

void KanalListe::add(Kanal *kanal,int slotLen, int slotCount)
{
	mq = new MessageQueue();

	mq->setSlotCount(slotCount);
	mq->setSlotLen(slotLen);
	kanal->setMessageQueue(mq);
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