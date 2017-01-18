#pragma once
#include "Kanal.h"

class ConnectUnit
{
private:

public:
	ConnectUnit();
	~ConnectUnit();

	void connect(Kanal &kanal, Aktionmanager aktionmanager);

	void disconnect(Aktionmanager aktionManager, Kanal kanal);

	bool ueberpruefeKanalVerbindung(int KanalNummer);
};

