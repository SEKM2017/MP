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
bool MessageQueue::schreiben(string gesendeteNchricht)
{
	//FIFO - Reinschreiben an der ersten freien Stelle
	for (int i = 0; i < DefinedslotCount; i++) {
		if (nachrichten[i] == "") {
			if (gesendeteNchricht.length() >= DefinedslotLen) {
				int differenz = gesendeteNchricht.length - DefinedslotLen;
				
			}
			//laenge untersuchen evt abschneiden
			nachrichten[i] = gesendeteNchricht;
			return true;
		}
		else if (i == DefinedslotCount) {
			return false;
		}
	}

	return true;
}
string MessageQueue::lesen()
{
	throw "NIY";
}
