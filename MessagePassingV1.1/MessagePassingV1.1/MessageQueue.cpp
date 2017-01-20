#include "MessageQueue.h"
#include <list>

using namespace std;
MessageQueue::MessageQueue()
{
}


MessageQueue::~MessageQueue()
{
}

int MessageQueue::getSlotCount()
{
	return slotCount;
}

void MessageQueue::setSlotCount(int count)
{
	slotCount = count;
}
int MessageQueue::getSlotLen()
{
	return slotLen;
}
void MessageQueue::setSlotLen(int len)
{
	slotLen = len;
}
//FIFO - Reinschreiben an der ersten freien Stelle
//laenge von slotlen oder uebergebene Laenge
bool MessageQueue::schreiben(string gesendeteNchricht)
{
	SENDERANTWORT sAntwort;
	for (int i = 0; i < DefinedslotCount; i++) {
		if (nachrichten[i] == "") {
			int kopierLaenge = static_cast<int>(gesendeteNchricht.length());
			if (kopierLaenge >= DefinedslotLen) {
				sAntwort.geschnittenAnzahl = kopierLaenge - DefinedslotLen;
				kopierLaenge = DefinedslotLen;
			}
				nachrichten[i].assign(gesendeteNchricht, 0,kopierLaenge);
				sAntwort.erfolg = true;
				
			return true;
		}
		else if (i == DefinedslotCount) {
			sAntwort.erfolg = false;
			return false;
		}
	}
	sAntwort.antwortAnSender = "Unerwarteter Fehler";
	return false;
}

bool MessageQueue::lesen(int verlangteLaenge, string& kopierString)
{
	empfaengerAntwort bAntwort;
	string returnString = "";
		if (nachrichten[0] != "") {
			int kopierLaenge = static_cast<int>(nachrichten[0].length());
			if (verlangteLaenge < kopierLaenge) {
				bAntwort.geschnittenAnzahl = verlangteLaenge - kopierLaenge;
				kopierLaenge = verlangteLaenge;
			}
			kopierString.assign(nachrichten[0],0,kopierLaenge);
			bAntwort.erfolg = true;

			//in der Messaggequeue alles um eins höher
			if (true) //Bei mehreren Empfängern, alle haben die Nachricht gelesen
			{
				for (int i = 1; i < DefinedslotCount; i++) {
					if (nachrichten[i] != "") {
						nachrichten[0].assign(nachrichten[i]);
						nachrichten[i] = "";
					}
				}
			}

			return true;
		}
		else {
			return false;
		}
	
		return false;
}
