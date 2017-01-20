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
int InitUnit::erzeugeKanal(int slotLen, int slotCount)
{
	KanalListe *kanalListe = KanalListe::Exemplar();
	
	Kanal *kanal = new Kanal();

	kanalListe->add(kanal, slotLen, slotCount);

	return kanal->getKanalId();
	
}
bool InitUnit::zerstoereKanal(int kanalNummer)
{
	bool result = false;
	KanalListe *kanalListe = KanalListe::Exemplar();

	result = kanalListe->destroy(kanalNummer);
	
	return result;
}