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
	f.open("config/config_xml.txt", ios::in);
	//Test
	char a = f.get();
	f.close();

	return "txt";
}