#include "Aktionmanager.h"



Aktionmanager::Aktionmanager()
{
}


Aktionmanager::~Aktionmanager()
{
}

string Aktionmanager::getType()
{
	return type;
}

void Aktionmanager::setType(string sT)
{
	type = sT;
}

int Aktionmanager::getId()
{
	return id;
}

void Aktionmanager::setId(int pId)
{
	id = pId;
}


//bool Aktionmanager::connectionRequest(ConnectUnit connectUnit, int KanalNummer)
//{
//	throw"not implemented yet";
//}

string Aktionmanager::nachrichtEntnehmen()
{
	throw"not implemented yet";
}

void Aktionmanager::nachrichtSenden(string nachricht)
{
	throw"not implemented yet";
}
