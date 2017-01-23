#pragma once
#include "KanalListe.h"
#include "Kanal.h"
#include "Misc.h"
#include <sstream>  //for std::istringstream
#include <iterator> //for std::istream_iterator
#include <vector>   //for std::vector
#include <iostream>
#include <fstream>

class InitUnit
{
private:
	bool istInitialisiert;
	bool dateiErfolgreichgelesen = false;
	int zuErzeugendeSlotCounts[20] = {};
	int zuErzeugendeSlotLens[50] = {};
	int anzahlKanaele;
public:
	InitUnit();
	~InitUnit();
	KanalListe* Init();
	bool ReInit(KanalListe liste);
	void dateiEinlesen();
	int erzeugeKanal(int slotLen, int slotCount);
	bool zerstoereKanal(int kanalNummer);
};

