#include "Misc.h"



Misc::Misc()
{
}


Misc::~Misc()
{
}

string Misc::ReadFromFile()
{
	fstream f;
	string s[100],t = "";
	int i = 0,x=0,z=0,j;
	f.open("config/config_xml.txt", ios::in);
	while (!f.eof())
	{
		getline(f,s[i]);
		i++;
	}
	
	f.close();
	for (j = 0; j < 100; j++)
	{
		t = s[j].substr(0, s[j].find("Kanal"));
		
		if (t == "<")
		{
			if (x == 0)
				x = j;
			z++;
		}
		if (t == "")
			break;
		
	}

	for (i = x; i < j; i++)
	{

	}
	return "txt";
}