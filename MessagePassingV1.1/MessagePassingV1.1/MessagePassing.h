#pragma once
#include "InitUnit.h"

class MessagePassing
{
private: 
	static MessagePassing* theExemplar;
public:
	MessagePassing();
	~MessagePassing();

	static MessagePassing* Exemplar();
	
};

