#include "MessagePassing.h"

MessagePassing::MessagePassing()
{
}


MessagePassing::~MessagePassing()
{

}

MessagePassing* MessagePassing::Exemplar()
{
	throw "Not implemented yet";
}


int main()
{
	InitUnit ui;
	KanalListe *kanalListe;
	Kanal *kanal;
	kanalListe = ui.Init();
	MessageQueue *mqA, *mqB, *mqC;
	
	//Kanal A(mqA,1);
	
	kanal = kanalListe->findKanalById(1);
	mqA = kanal->getMessageQueue();
	mqA->schreiben("Test");
	kanal = kanalListe->findKanalById(0);
	mqB = kanal->getMessageQueue();
	mqB->schreiben("Test123");
	kanal = kanalListe->findKanalById(5);
	mqC = kanal->getMessageQueue();
	mqC->schreiben("TestDel");
	kanalListe->destroy(5);
	
	mqC = kanal->getMessageQueue();

	return 0;
}

