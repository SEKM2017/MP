#include "ConnectUnit.h"

ConnectUnit::ConnectUnit()
{
}

ConnectUnit::ConnectUnit(const ConnectUnit &)
{
}

//ConnectUnit & ConnectUnit::operator=(const ConnectUnit &)
//{
//	// TODO: insert return statement here
//}


ConnectUnit::~ConnectUnit()
{
}
ConnectUnit* ConnectUnit::theExemplar = 0;
ConnectUnit * ConnectUnit::Exemplar()
{
	if (theExemplar == 0)
	{
		theExemplar = new ConnectUnit;
	}
	return (theExemplar);
}


int ConnectUnit::connect(int KanalNummer)
{
	KanalListe *kListe;
	Kanal *gesuchterKanal;
	kListe = KanalListe::Exemplar();
	gesuchterKanal = kListe->findKanalById(KanalNummer);
	if (gesuchterKanal->getKanalNummer() != -1) {
		//refzumVerbundenenKanal = gesuchterKanal;
		return gesuchterKanal->getKanalNummer();
		
	}
	//return gesuchterKanal = new Kanal();
	return -2;
}


bool ConnectUnit::disconnect()
{
	return false;
}

bool ConnectUnit::ueberpruefeKanalVerbindung(int KanalNummer)
{
	KanalListe *kListe;
	Kanal *gesuchterKanal;
	kListe = KanalListe::Exemplar();
	gesuchterKanal = kListe->findKanalById(KanalNummer);
	if (gesuchterKanal->getKanalNummer() != -1) {
		return true;
	}
	else false;
}

Sender::Sender()
{
	//verbundenderKanal = new Kanal();
}

Sender::~Sender()
{
}

//void Sender::sendeNachricht(string nachricht, MessageQueue* mqx)
//{
//	mq = mqx;
//	//verbundenderKanal->getMessageQueue()->schreiben(nachricht);
//	mq->schreiben(nachricht);
//}

void Sender::sendeNachricht(string nachricht)
{
	ThreadMutexGuard theGuard(theLock);
	KanalListe *kListe;
	Kanal *gesuchterKanal;
	kListe = KanalListe::Exemplar();
	gesuchterKanal = kListe->findKanalById(connectedTo);
	gesuchterKanal->getMessageQueue()->schreiben(nachricht);

}

Empfaenger::Empfaenger()
{
}

Empfaenger::~Empfaenger()
{
}

string Empfaenger::empfaengeNachricht(int len)
{
	if (connectedTo > 0) {
		ThreadMutexGuard theGuard(theLock);
		string returnString = "";
		KanalListe *kListe;
		Kanal *gesuchterKanal;
		kListe = KanalListe::Exemplar();
		gesuchterKanal = kListe->findKanalById(connectedTo);
		gesuchterKanal->getMessageQueue()->lesen(len, returnString);
		return returnString;
	}
	else {
		throw"Exepction: Keine Verbindung vorhanden";
	}
}
