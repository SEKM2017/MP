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
	MessageQueue *mqA, *mqB;
	
	//Kanal A(mqA,1);
	
	kanal = kanalListe->findKanalById(1);
	mqA = kanal->getMessageQueue();
	kanal = kanalListe->findKanalById(1);
	mqB = kanal->getMessageQueue();
	mqA->schreiben("Test");
	string leseTest = "leer";
	mqA->lesen(10, leseTest);


	return 0;
}

