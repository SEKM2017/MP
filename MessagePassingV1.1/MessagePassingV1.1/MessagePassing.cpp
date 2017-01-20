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

	kanalListe = ui.Init();
	MessageQueue mqA;
	
	Kanal A(mqA,1);
	


	
	mqA.schreiben("Test");
	string lesenTest = "leer";
	mqA.lesen(5, lesenTest);
	return 0;
}

