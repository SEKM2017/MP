#pragma once
#include <string>
#include <list>
#include "ThreadMutexGuard.h"
#define DefinedslotCount  10
#define DefinedslotLen 5
using namespace std;
typedef struct SENDERANTWORT
{
	bool erfolg = false;
	int geschnittenAnzahl = 0;
	string antwortAnSender = "";
};
struct EMPFAENGERANTWORT {
	bool erfolg = false;
	int geschnittenAnzahl = 0;
	string antwortAnEmpfaenger = "";
};

class MessageQueue
{
private: 
	int slotCount;
	int slotLen;
	
	string nachrichten[100];
	ThreadMutex theLock;
public:
	SENDERANTWORT senAntwort;
	EMPFAENGERANTWORT empfAntwort;
	MessageQueue();
	~MessageQueue();
	MessageQueue(int count, int len);
	int getSlotCount();
	void setSlotCount(int count);
	int getSlotLen();
	void setSlotLen(int len);
	SENDERANTWORT schreiben(string nachricht);
	EMPFAENGERANTWORT lesen(int verlangeLaenge, string& kopierString);
	
};

