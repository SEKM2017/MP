#pragma once
#include "KanalListe.h"
#include "Kanal.h"
#include "Misc.h"

class InitUnit
{
private:
	bool istInitialisiert;
public:
	InitUnit();
	~InitUnit();
	KanalListe* Init();
	bool ReInit(KanalListe liste);
	Kanal erzeugeKanal();
	bool zerstoereKanal(int kanalNummer);
};

