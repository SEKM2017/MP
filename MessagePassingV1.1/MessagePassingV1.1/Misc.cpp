#include "Misc.h"



Misc::Misc()
{
}


Misc::~Misc()
{
}

static string ReadFromFile()
{
	fstream f;
	f.open("config/config_json.txt", ios::in);
	f.close();

	return "txt";
}