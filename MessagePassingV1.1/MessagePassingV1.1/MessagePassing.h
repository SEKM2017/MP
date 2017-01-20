#pragma once
#include "InitUnit.h"
#include "KanalListe.h"
#include "ConnectUnit.h"
class MessagePassing
{
private: 
	static MessagePassing* theExemplar;
public:
	MessagePassing();
	~MessagePassing();

	static MessagePassing* Exemplar();
	
};

