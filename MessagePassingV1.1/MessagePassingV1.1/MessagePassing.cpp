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
	KanalListe *kanalListe;
	Sender senderA, senderB;
	Empfaenger empfA, empfB;
	int tmp;
	Logfile::Write("Programm Message Passing Komponente gestartet");

	connectUnit = ConnectUnit::Exemplar();

	kanalListe = initUnit.Init();
	cout <<"|Message Passing Komponente - vorfuehrung|"<< endl;
	cout << " -----------------------------------------" << "\n\n";
	

	Kanal *kA = kanalListe->findKanalById(0);
	MessageQueue *mqA = kA->getMessageQueue();

	empfA.connectedTo = connectUnit->connect(0);
	senderA.connectedTo = connectUnit->connect(0);

	string tempText = empfA.empfaengeNachricht(5);
	cout << "In Kanal Nr." << kA->getKanalNummer() << " steht: \"" << tempText <<"\" \n";

	cout << "Sendevorgang und Empfangvorgang: " << endl;
	cout << "\nGeben Sie eine Nachricht ein, die im Kanal " << kA->getKanalNummer() << " gespeichert werden soll." << endl;
	cin >> tempText;
	senderA.sendeNachricht(tempText);
	tmp = senderA.sAntwort.geschnittenAnzahl;
	if (tmp > 0) {
		cout << "Die verfuegbare Laenge (slotLen) ist kuerzer als die eingegebene Nachtichlaenge." <<
			"Daher wurden " << tmp << " Zeichen abgeschnitten" << endl;
	}
	cout << "\nGeben Sie eine Nachricht ein, die im Kanal " << kA->getKanalNummer() << " gespeichert werden soll." << endl;
	cin >> tempText;
	senderA.sendeNachricht(tempText);
	tmp = senderA.sAntwort.geschnittenAnzahl;
	if (tmp > 0) {
		cout << "Die verfuegbare Laenge (slotLen) ist kuerzer als die eingegebene Nachtichlaenge." <<
			"Daher wurden " << tmp << " Zeichen abgeschnitten" << endl;
	}
	cout << "\nGeben Sie eine Nachricht ein, die im Kanal " << kA->getKanalNummer() << " gespeichert werden soll." << endl;
	cin >> tempText;
	senderA.sendeNachricht(tempText);
	tmp = senderA.sAntwort.geschnittenAnzahl;
	if (tmp > 0) {
		cout << "Die verfuegbare Laenge (slotLen) ist kuerzer als die eingegebene Nachtichlaenge." <<
			"Daher wurden " << tmp << " Zeichen abgeschnitten" << endl;
	}

	


	//----Empfang
	cout << "\nGeben Sie die gewuenschte Laenge fuer dem Empfang an." << endl;
	cin >> tmp;
	tempText = empfA.empfaengeNachricht(tmp);
	if (empfA.eAntwort.erfolg == false)
	{
		cout << "Empfang Fehlgeschlagen. Die Uebergebene Antwort lautet: " << empfA.eAntwort.antwortAnEmpfaenger << endl;
	}
	else
	{
		cout << "In Kanal Nr." << kA->getKanalNummer() << " steht: \"" << tempText << "\" \n";
		tmp = empfA.eAntwort.geschnittenAnzahl;


		if (tmp > 0) {
			cout << "Die Gespeicherte Nachricht war Laenger als die gewuenschte Laenge. Daher wurden "
				<< tmp << " Zeichen gekuerzt" << endl;
		}
	}
	//----Empfang
	cout << "\nGeben Sie die gewuenschte Laenge fuer dem Empfang an." << endl;
	cin >> tmp;
	tempText = empfA.empfaengeNachricht(tmp);
	if (empfA.eAntwort.erfolg == false)
	{
		cout << "Empfang Fehlgeschlagen. Die Uebergebene Antwort lautet: " << empfA.eAntwort.antwortAnEmpfaenger << endl;
	}
	else
	{
		cout << "In Kanal Nr." << kA->getKanalNummer() << " steht: \"" << tempText << "\" \n";
		tmp = empfA.eAntwort.geschnittenAnzahl;


		if (tmp > 0) {
			cout << "Die Gespeicherte Nachricht war Laenger als die gewuenschte Laenge. Daher wurden "
				<< tmp << " Zeichen gekuerzt" << endl;
		}
	}
	//----Empfang
	cout << "\nGeben Sie die gewuenschte Laenge fuer dem Empfang an." << endl;
	cin >> tmp;
	tempText = empfA.empfaengeNachricht(tmp);
	if (empfA.eAntwort.erfolg == false)
	{
		cout << "Empfang Fehlgeschlagen. Die Uebergebene Antwort lautet: " << empfA.eAntwort.antwortAnEmpfaenger << endl;
	}
	else
	{
		cout << "In Kanal Nr." << kA->getKanalNummer() << " steht: \"" << tempText << "\" \n";
		tmp = empfA.eAntwort.geschnittenAnzahl;


		if (tmp > 0) {
			cout << "Die Gespeicherte Nachricht war Laenger als die gewuenschte Laenge. Daher wurden "
				<< tmp << " Zeichen gekuerzt" << endl;
		}
	}
	//----Empfang
	cout << "\nGeben Sie die gewuenschte Laenge fuer dem Empfang an." << endl;
	cin >> tmp;
	tempText = empfA.empfaengeNachricht(tmp);
	if (empfA.eAntwort.erfolg == false)
	{
		cout << "Empfang Fehlgeschlagen. Die Uebergebene Antwort lautet: " << empfA.eAntwort.antwortAnEmpfaenger << endl;
	}
	else
	{
		cout << "In Kanal Nr." << kA->getKanalNummer() << " steht: \"" << tempText << "\" \n";
		tmp = empfA.eAntwort.geschnittenAnzahl;


		if (tmp > 0) {
			cout << "Die Gespeicherte Nachricht war Laenger als die gewuenschte Laenge. Daher wurden "
				<< tmp << " Zeichen gekuerzt" << endl;
		}
	}
	
	//initUnit.zerstoereKanal(0);
	initUnit.erzeugeKanal(6,30, 1);
	Kanal *kC = kanalListe->findKanalById(6);
	MessageQueue *mqC = kC->getMessageQueue();
	senderA.connectedTo = connectUnit->connect(6);
	empfA.connectedTo = connectUnit->connect(6);
	cout << "\nGeben Sie eine Nachricht ein, die im Kanal " << kC->getKanalNummer() << " gespeichert werden soll." << endl;
	cin >> tempText;
	senderA.sendeNachricht(tempText);
	tmp = senderA.sAntwort.geschnittenAnzahl;
	if (tmp > 0) {
		cout << "Die verfuegbare Laenge (slotLen) ist kuerzer als die eingegebene Nachtichlaenge." <<
			"Daher wurden " << tmp << " Zeichen abgeschnitten" << endl;
	}
	//----Empfang
	cout << "\nGeben Sie die gewuenschte Laenge fuer dem Empfang an." << endl;
	cin >> tmp;
	tempText = empfA.empfaengeNachricht(tmp);
	if (empfA.eAntwort.erfolg == false)
	{
		cout << "Empfang Fehlgeschlagen. Die Uebergebene Antwort lautet: " << empfA.eAntwort.antwortAnEmpfaenger << endl;
	}
	else
	{
		cout << "In Kanal Nr." << kC->getKanalNummer() << " steht: \"" << tempText << "\" \n";
		tmp = empfA.eAntwort.geschnittenAnzahl;


		if (tmp > 0) {
			cout << "Die Gespeicherte Nachricht war Laenger als die gewuenschte Laenge. Daher wurden "
				<< tmp << " Zeichen gekuerzt" << endl;
		}
	}
	
	system("PAUSE");
	Logfile::Write("Programm beendet");
	return 0;
}
