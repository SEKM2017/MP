#include "MessagePassing.h"

MessagePassing::MessagePassing()
{
}

MessagePassing::MessagePassing(const MessagePassing &)
{
}


MessagePassing::~MessagePassing()
{

}
MessagePassing* MessagePassing::theExemplar = 0;
MessagePassing* MessagePassing::Exemplar()
{
	if (theExemplar == 0) {
		theExemplar = new MessagePassing;
	}
	return (theExemplar);
}


int main()
{
	InitUnit initUnit;
	ConnectUnit *connectUnit;
	connectUnit	= ConnectUnit::Exemplar();
	KanalListe *kanalListe;
	Sender senderA, senderB;
	Empfaenger empfA, empfB;

	kanalListe = initUnit.Init();
	cout <<"|Message Passing Komponente - vorfuehrung|"<< endl;
	cout << " -----------------------------------------" << "\n\n";
	

	Kanal *kA = kanalListe->findKanalById(0);
	MessageQueue *mqA = kA->getMessageQueue();
	Kanal *kB = kanalListe->findKanalById(6);
	MessageQueue *mqB = kB->getMessageQueue();

	empfA.connectedTo = connectUnit->connect(0);
	empfB.connectedTo = connectUnit->connect(6);
	senderA.connectedTo = connectUnit->connect(0);
	senderB.connectedTo = connectUnit->connect(6);

	string tempText = empfA.empfaengeNachricht(5);
	string tempText2 = empfB.empfaengeNachricht(5);
	int tmp = kB->getKanalNummer();
	cout << "In Kanal Nr." << kA->getKanalNummer() << " steht: \"" << tempText <<"\" \n";
	cout << "In Kanal Nr." << kB->getKanalNummer() << " steht: \"" << tempText2 << "\" \n\n";

	cout << "Sendevorgang und Empfangvorgang: " << endl;
	cout << "Geben Sie eine Nachricht ein, die im Kanal " << kA->getKanalNummer() << " gespeichert werden soll." << endl;
	cin >> tempText;
	senderA.sendeNachricht(tempText);
	tmp = senderA.sAntwort.geschnittenAnzahl;
	if (tmp > 0) {
		cout << "Die verfuegbare Laenge (slotLen) ist kuerzer als die eingegebene Nachtichlaenge." <<
			"Daher wurden " << tmp << " Zeichen abgeschnitten" << endl;
	}
		
	cout <<"Geben Sie die gewuenschte Laenge fuer dem Empfang an."<< endl;
	cin >> tmp;
	cout << "In Kanal Nr." << kA->getKanalNummer() << " steht: \"" << empfA.empfaengeNachricht(tmp) << "\" \n";
	tmp = empfA.eAntwort.geschnittenAnzahl;
	if (tmp > 0) {
		cout << "Die Gespeicherte Nachricht war Laenger als die gewuenschte Laenge. Daher wurden " 
			<<tmp<<" Zeichen gekuerzt"<< endl;
	}

	
	

	system("PAUSE");
	Misc::WriteToLogfile("Logfile", "Programm beendet");
	return 0;
}

