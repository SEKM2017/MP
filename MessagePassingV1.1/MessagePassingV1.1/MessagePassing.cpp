#include "MessagePassing.h"

MessagePassing::MessagePassing()
{
}


MessagePassing::~MessagePassing()
{

}

MessagePassing* MessagePassing::Exemplar()
{
	throw "Not implemented yet";
}


int main()
{
	InitUnit iu;
	KanalListe *kanalListe;
	//Kanal *kanal;
	kanalListe = iu.Init();
	MessageQueue *mqA , *mqB;
	
	//Kanal A(mqA,1);
	
	/*kanal = kanalListe->findKanalById(1);
	mqA = kanal->getMessageQueue();
	kanal = kanalListe->findKanalById(1);
	mqB = kanal->getMessageQueue();
	mqA->schreiben("Test");
	string leseTest = "leer";
	mqA->lesen(10, leseTest);*/
	ConnectUnit connectionUnit;
	Kanal kanalA(1);
	mqA = kanalA.getMessageQueue();
	mqA->schreiben("Test");
	string leseA = "leer";
	mqA->lesen(10, leseA); 


	string leseB = "ffff";
	Kanal kanalB(2);
	mqB = kanalB.getMessageQueue();
	Sender senderA;
	Empfaenger emA;
	Kanal test;
	string emtest = "--";
	senderA.connectedTo = connectionUnit.connect(1, &test);
	emA.connectedTo = connectionUnit.connect(1, &test);
	if (senderA.connectedTo > 0) {
		string tmp = "";
		cout << "gib Nachricht ein" << endl;
		cin >> tmp;
		senderA.sendeNachricht(tmp);
		cout << "Jetzt gibt der Empfaenger die Nachricht aus" << endl;
		emtest = emA.empfaengeNachricht();
		cout << emtest << endl;

	}

	system("PAUSE");
	Misc::WriteToLogfile("Logfile", "Programm beendet");
	return 0;
}

