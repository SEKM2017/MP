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
	int erzeugeKanal(int slotLen, int slotCount);
	bool zerstoereKanal(int kanalNummer);
};

