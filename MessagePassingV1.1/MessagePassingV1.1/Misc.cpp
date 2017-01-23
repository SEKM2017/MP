#include "Misc.h"

/*
bool Misc::WriteToLogfile(string message)
{
	bool result = false;
	time_t t;
	tm *now;

	t = time(0);
	now = localtime(&t);

	fstream f;
	f.open("Logfile.txt", ios::app);
	f << now->tm_year + 1900 << '.' <<  now->tm_mon + 1 << '.' << now->tm_mday << " - " << now->tm_hour << ':' << now->tm_min << ':' << now->tm_sec << " ";
	f << message << endl;
	f.close();

	return result;
}
*/