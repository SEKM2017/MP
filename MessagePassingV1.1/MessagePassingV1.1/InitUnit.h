#pragma once
#include "KanalListe.h"
#include "Kanal.h"
#include "Misc.h"
#include <iostream>
#include <fstream>

class InitUnit
{
private:
	bool istInitialisiert;
	bool dateiErfolgreichgelesen = false;
	int zuErzeugendeKanaele[50][20] = {};

public:
	InitUnit();
	~InitUnit();
	KanalListe* Init();
	bool ReInit(KanalListe liste);
	void dateiEinlesen();
	int erzeugeKanal(int slotLen, int slotCount);
	bool zerstoereKanal(int kanalNummer);
};

