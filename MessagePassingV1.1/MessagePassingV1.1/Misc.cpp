#include "Misc.h"




Misc::Misc()
{
}


Misc::~Misc()
{
}

string Misc::ReadFromConfig(string searchString)
{
	fstream f;
	string s,fs = "";
	int i = 0,x=0,z=0,j;
	f.open("config/config.ini", ios::in);
	while (!f.eof())
	{
		getline(f,s);

		std::size_t found = s.find(searchString);
		if (i == 0)
		{

		}
		else
		{
			if (found != std::string::npos)
			{
				fs.erase(fs.end() - 1);
				fs = fs + ";";
			}
			else
			{
				fs = fs + s + ",";
			}
		}
		
		

		i++;
	}
	
	f.close();

	return fs;
}

bool Misc::WriteToLogfile(string filename, string message)
{
	bool result = false;
	time_t t;
	tm *now;

	t = time(0);
	now = localtime(&t);

	fstream f;
	f.open("log/" + filename + ".txt", ios::app);
	f << now->tm_year + 1900 << '.' <<  now->tm_mon + 1 << '.' << now->tm_mday << " - " << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << " ";
	f << message << endl;
	f.close();

	return result;
}
