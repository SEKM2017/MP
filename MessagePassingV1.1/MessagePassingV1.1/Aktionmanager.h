#pragma once
#include <string>
using namespace std;
class Aktionmanager
{
private:
	string type;
	int id;
	bool connectionAvailable;

public:
	Aktionmanager();
	~Aktionmanager();
	string getType();
	void setType(string pType);
	int getId();
	void setId(int pId);
	//bool connectionRequest(ConnectUnit connectUnit, int KanalNummer);
	string nachrichtEntnehmen();
	void nachrichtSenden(string nachricht);

};

