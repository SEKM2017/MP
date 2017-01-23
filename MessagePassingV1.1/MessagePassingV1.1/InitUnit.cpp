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
	string str;
	KanalListe *kanalListe = KanalListe::Exemplar();

	Misc::WriteToLogfile("Logfile", "Programm gestartet");
	dateiEinlesen();
		
	//Erstellen der Kanaele und hinzufügen von Kanaelen
	/*
	for (i = 0; i < 10; i++)
	{
		kanal = new Kanal(i);
		kanalListe->add(kanal,10,10);
	}
	*/
	for (int i = 0; i <anzahlKanaele || i< (kanalListe->getAnzahlMaxKanaele() ); i++) {
		kanal = new Kanal(i, zuErzeugendeSlotLens[i], zuErzeugendeSlotCounts[i]);
		kanalListe->add(kanal);
		Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	}
	/*kanal = new Kanal(1,10,10);
	kanalListe->add(kanal);
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(2, 20, 12);
	kanalListe->add(kanal); 
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(3, 15, 10);
	kanalListe->add(kanal);
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(4, 12, 15);
	kanalListe->add(kanal); 
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(5, 14, 10);
	kanalListe->add(kanal); 
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(6, 18, 10);
	kanalListe->add(kanal); 
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(7, 16, 10);
	kanalListe->add(kanal); 
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(8, 25, 10);
	kanalListe->add(kanal); 
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(9, 30, 10);
	kanalListe->add(kanal);
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");
	kanal = new Kanal(10, 40, 10);
	kanalListe->add(kanal);
	Misc::WriteToLogfile("Kanal" + std::to_string(kanal->getKanalNummer()), "Kanal erfolgreich erstellt");*/
	Misc::WriteToLogfile("Logfile", "Kanaliste mit Kanaelen erfolgreich erstellt");
	
	return kanalListe;
}
void InitUnit::dateiEinlesen()
{
	ifstream initFile;
	string line;
	int anzahlLines = 0;
	initFile.open("init.txt");
	vector<string> stringVector;
	if (initFile.is_open()) {
		/*while (!initFile.eof())
		{
			getline(initFile, line);
			anzahlLines++;
		}*/
		while (!initFile.eof())
		{
			istringstream iss(line);
			for (string line; initFile >> line; )
				stringVector.push_back(line);
		}
		dateiErfolgreichgelesen = true;
	}
	initFile.close();
	anzahlKanaele = stringVector.size() / 2;
	int a = 0;
	for (int i = 0; i<stringVector.size(); i++) {
		if (i % 2 == 0) {
			zuErzeugendeSlotCounts[a] = stoi(stringVector[i]);
			
		}
		else {
			zuErzeugendeSlotLens[a] = stoi(stringVector[i]);
			a++;
		}

	}
	
	
}
//bool InitUnit::ReInit(KanalListe liste)
//{
//	throw "NIY";
//}
int InitUnit::erzeugeKanal(int slotLen, int slotCount)
{
	KanalListe *kanalListe = KanalListe::Exemplar();
	
	string logfile;

	Kanal *kanal = new Kanal();

	kanalListe->add(kanal);

	logfile = "Kanal mit der Nummer: " + std::to_string(kanal->getKanalNummer()) + " mit Anzahl der Slots: " + std::to_string(slotCount) + " und der Slotgroesse: " + std::to_string(slotLen) + " erstellt.";

	Misc::WriteToLogfile("Logfile", logfile);

	return kanal->getKanalNummer();
	
}
bool InitUnit::zerstoereKanal(int kanalNummer)
{
	bool result = false;
	KanalListe *kanalListe = KanalListe::Exemplar();

	result = kanalListe->destroy(kanalNummer);

	Misc::WriteToLogfile("Logfile", "Kanal mit der Nummer: " + std::to_string(kanalNummer) + " zerstoert.");

	return result;
}