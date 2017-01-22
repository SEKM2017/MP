#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <windows.h>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

class Misc
{
private:
public:
	Misc();
	~Misc();
	static string ReadFromConfig(string searchString);
	static bool WriteToLogfile(string filename, string message);
};

