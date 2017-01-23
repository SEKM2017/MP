#pragma once
#include "Kanal.h"
#include "KanalListe.h"
#include "ThreadMutexGuard.h"
class ConnectUnit 
{
private:
	static ConnectUnit* theExemplar;
protected:
	ConnectUnit();
	ConnectUnit(const ConnectUnit&);
	ConnectUnit& operator= (const ConnectUnit&);
	~ConnectUnit();
public:
	static ConnectUnit* Exemplar();
	ThreadMutex theLock;
	void connect(Kanal &kanal, Aktionmanager aktionmanager);
	int connect(int KanalNummer);
	//void connect()
	bool disconnect();

	bool ueberpruefeKanalVerbindung(int KanalNummer);
};
class Sender : public ConnectUnit
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

class Empfaenger : public ConnectUnit
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

