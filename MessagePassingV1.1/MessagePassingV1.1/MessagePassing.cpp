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
	MessageQueue mqA;
	Kanal A(mqA,1);
	
	mqA.schreiben("Test");
	return 0;
}

