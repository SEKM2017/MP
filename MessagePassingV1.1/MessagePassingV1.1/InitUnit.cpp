#include "InitUnit.h"

InitUnit::InitUnit()
{
}


InitUnit::~InitUnit()
{
}
KanalListe* InitUnit::Init()
{
	int i;
	Kanal *kanal;
	KanalListe *kanalListe = KanalListe::Exemplar();

	Misc::ReadFromFile();

	//Erstellen der Kanaele und hinzufügen von Kanaelen
	for (i = 0; i < 10; i++)
	{
		kanal = new Kanal(i);
		kanalListe->add(kanal,10,10);
	}

	return kanalListe;
}
bool InitUnit::ReInit(KanalListe liste)
{
	throw "NIY";
}
Kanal InitUnit::erzeugeKanal()
{
	throw "NIY";
}
bool InitUnit::zerstoereKanal(int kanalNummer)
{
	throw "NIY";
}

