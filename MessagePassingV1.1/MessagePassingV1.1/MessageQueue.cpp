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
			int differenz = static_cast<int>(gesendeteNchricht.length());
			if (differenz >= DefinedslotLen) {
				differenz = DefinedslotLen;
			}
				nachrichten[i].assign(gesendeteNchricht, 0,differenz);
			return true;
		}
		else if (i == DefinedslotCount) {
			return false;
		}
	}

	//return false;
}
string MessageQueue::lesen()
{
	throw "NIY";
}
