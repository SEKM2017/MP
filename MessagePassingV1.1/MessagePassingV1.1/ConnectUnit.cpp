#include "ConnectUnit.h"



ConnectUnit::ConnectUnit()
{
}


ConnectUnit::~ConnectUnit()
{
}

void ConnectUnit::connect(Kanal &kanal, Aktionmanager aktionmanager)
{
	throw"not implemented yet";
}

int ConnectUnit::connect(int KanalNummer, Kanal* refzumVerbundenenKanal)
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

string Empfaenger::empfaengeNachricht()
{
	string returnString = "";
	KanalListe *kListe;
	Kanal *gesuchterKanal;
	kListe = KanalListe::Exemplar();
	gesuchterKanal = kListe->findKanalById(connectedTo);
	gesuchterKanal->getMessageQueue()->lesen(5, returnString);
	return returnString;
}
