#pragma once
#include <string>
#include <list>
#include "ThreadMutexGuard.h"
#define DefinedslotCount  10
#define DefinedslotLen 1
using namespace std;

class MessageQueue
{
private: 
	int slotCount;
	int slotLen;
	struct SENDERANTWORT {
		bool erfolg = false;
		int geschnittenAnzahl = 0;
		string antwortAnSender = "";
	};
	struct empfaengerAntwort {
		bool erfolg = false;
		int geschnittenAnzahl = 0;
		string antwortAnEmpfaenger = "";
	};
	string nachrichten[DefinedslotCount];
	ThreadMutex theLock;
public:
	MessageQueue();
	~MessageQueue();
	int getSlotCount();
	void setSlotCount(int count);
	int getSlotLen();
	void setSlotLen(int len);
	bool schreiben(string nachricht);
	bool lesen(int verlangeLaenge, string& kopierString);
};

