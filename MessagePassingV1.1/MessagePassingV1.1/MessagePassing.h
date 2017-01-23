#pragma once
#include "InitUnit.h"
#include "KanalListe.h"
#include "ConnectUnit.h"
class MessagePassing
{
private: 
	static MessagePassing* theExemplar;
protected:
	MessagePassing();
	MessagePassing(const MessagePassing&);
	~MessagePassing();
public:
	

	static MessagePassing* Exemplar();
	
};

