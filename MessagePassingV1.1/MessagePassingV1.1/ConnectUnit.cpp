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
		Logfile::Write("Verbindung mit Kanal " + std::to_string(KanalNummer) + " aufgebaut");
	}
	//return gesuchterKanal = new Kanal();
	Logfile::Write("Verbindung mit Kanal " + std::to_string(KanalNummer) + " konnte nicht aufgebaut");
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
	if (connectedTo >= 0) {
		ThreadMutexGuard theGuard(theLock);
		KanalListe *kListe;
		Kanal *gesuchterKanal;
		kListe = KanalListe::Exemplar();
		gesuchterKanal = kListe->findKanalById(connectedTo);
		MessageQueue *mq = gesuchterKanal->getMessageQueue();
		sAntwort = mq->schreiben(nachricht);
		Logfile::Write("Kanal " + std::to_string(gesuchterKanal->getKanalNummer()) + " - schreiben: " + nachricht);
		if(sAntwort.geschnittenAnzahl > 0)
			Logfile::Write("Kanal " + std::to_string(gesuchterKanal->getKanalNummer()) + " - schreiben: " + "Nachricht wurde um " + std::to_string(sAntwort.geschnittenAnzahl) + " gekuerzt");

	}
	else {
		sAntwort.antwortAnSender = "Verbindungsfehler mit dem Kanal";
		Logfile::Write("Sender mit keinem Kanal verbunden");
	}

}

Empfaenger::Empfaenger()
{
}

Empfaenger::~Empfaenger()
{
}

string Empfaenger::empfaengeNachricht(int len)
{
	if (connectedTo >= 0) {
		ThreadMutexGuard theGuard(theLock);
		string returnString = "";
		KanalListe *kListe;
		Kanal *gesuchterKanal;
		kListe = KanalListe::Exemplar();
		gesuchterKanal = kListe->findKanalById(connectedTo);
		MessageQueue *mq = gesuchterKanal->getMessageQueue();
		eAntwort = mq->lesen(len, returnString);
		Logfile::Write("Kanal " + std::to_string(gesuchterKanal->getKanalNummer()) + " - lesen: " + returnString);
		if (eAntwort.geschnittenAnzahl > 0)
			Logfile::Write("Kanal " + std::to_string(gesuchterKanal->getKanalNummer()) + " - lesen: " + "Nachricht wurde um " + std::to_string(eAntwort.geschnittenAnzahl) + " gekuerzt");
		return returnString;
	}
	else {
		eAntwort.antwortAnEmpfaenger = "Verbindungsfehler mit dem Kanal";
		Logfile::Write("Empfänger mit keinem Kanal verbunden");
		return "_ERROR";
	}
}
