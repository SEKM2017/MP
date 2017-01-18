#pragma once
#include "KanalListe.h";

class InitUnit
{
private:
	bool istInitialisiert;
public:
	InitUnit();
	~InitUnit();
	bool Init(KanalListe liste);
	bool ReInit(KanalListe liste);
	Kanal erzeugeKanal();
	bool zerstoereKanal(int kanalNummer);
};

