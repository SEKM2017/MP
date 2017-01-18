#pragma once
#include "InitUnit.h"
#include "KanalListe.h"

class MessagePassing
{
private: 
	static MessagePassing* theExemplar;
public:
	MessagePassing();
	~MessagePassing();

	static MessagePassing* Exemplar();
	
};

