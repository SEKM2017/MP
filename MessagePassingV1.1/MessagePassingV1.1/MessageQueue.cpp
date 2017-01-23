#include "MessageQueue.h"
using namespace std;
MessageQueue::MessageQueue()
{
}


MessageQueue::~MessageQueue()
{
}

MessageQueue::MessageQueue(int count, int len)
{
	slotCount = count;
	slotLen = len;
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
SENDERANTWORT MessageQueue::schreiben(string gesendeteNchricht)
{
	for (int i = 0; i < slotCount; i++) {
		if (nachrichten[i] == "") {
			int kopierLaenge = static_cast<int>(gesendeteNchricht.length());
			if (kopierLaenge >= slotLen) {
				senAntwort.geschnittenAnzahl = kopierLaenge - slotLen;
				kopierLaenge = slotLen;
			}
				nachrichten[i].assign(gesendeteNchricht, 0,kopierLaenge);
				senAntwort.erfolg = true;
			return senAntwort;
		}
		else if (i == slotCount) {
			senAntwort.erfolg = false;
			return senAntwort;
		}
	}
	senAntwort.antwortAnSender = "Unerwarteter Fehler";
	return senAntwort;
}
//aktuell
EMPFAENGERANTWORT MessageQueue::lesen(int verlangteLaenge, string& kopierString)
{
	string returnString = "";
		if (nachrichten[0] != "") {
			int kopierLaenge = static_cast<int>(nachrichten[0].length());
			//if (slotLen < kopierLaenge) kopierLaenge = slotLen;
			if (verlangteLaenge < kopierLaenge) {
				empfAntwort.geschnittenAnzahl = kopierLaenge -verlangteLaenge;
				kopierLaenge = verlangteLaenge;
			}
			kopierString.assign(nachrichten[0],0,kopierLaenge);
			empfAntwort.erfolg = true;

			//in der Messaggequeue alles um eins höher
			if (true) //Bei mehreren Empfängern, alle haben die Nachricht gelesen
			{
				for (int i = 1; i < slotCount; i++) {
					if (nachrichten[i] != "") {
						nachrichten[0].assign(nachrichten[i]);
						nachrichten[i] = "";
					}
				}
			}

			return empfAntwort;
		}
	
		return empfAntwort;
}
