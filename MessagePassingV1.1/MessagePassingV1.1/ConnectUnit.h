#pragma once
#include "Kanal.h"
#include "KanalListe.h"

class ConnectUnit 
{
private:

public:
	ConnectUnit();
	~ConnectUnit();

	void connect(Kanal &kanal, Aktionmanager aktionmanager);
	int connect(int KanalNummer, Kanal* refzumVerbundenenKanal);
	//void connect()
	bool disconnect();

	bool ueberpruefeKanalVerbindung(int KanalNummer);
};
class Sender
{
private:
	struct SENDERANTWORT {
		bool erfolg = false;
		int geschnittenAnzahl = 0;
		string antwortAnSender = "";
	};
public:
	
	//MessageQueue* mq;
	int connectedTo = 0;
	Sender();
	~Sender();
	//void sendeNachricht(string nachricht, MessageQueue* mqx);
	void sendeNachricht(string nachricht);
};

class Empfaenger 
{
private:
	struct EMPFAENGERANTWORT {
		bool erfolg = false;
		int geschnittenAnzahl = 0;
		string antwortAnEmpfaenger = "";
	};
public:
	int connectedTo = 0;
	bool connectionAvailable = false;
	Empfaenger();
	~Empfaenger();
	string empfaengeNachricht();
};

