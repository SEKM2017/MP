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
	int connect(int KanalNummer);
	//void connect()
	bool disconnect();

	bool ueberpruefeKanalVerbindung(int KanalNummer);
};
class Sender : public ConnectUnit
{
private:
	
public:
	SENDERANTWORT sAntwort;
	int connectedTo = -1;
	Sender();
	~Sender();
	//void sendeNachricht(string nachricht, MessageQueue* mqx);
	void sendeNachricht(string nachricht);
};

class Empfaenger : public ConnectUnit
{
private:
	
public:
	EMPFAENGERANTWORT eAntwort;
	int connectedTo = -1;
	bool connectionAvailable = false;
	Empfaenger();
	~Empfaenger();
	string empfaengeNachricht(int len);
};

