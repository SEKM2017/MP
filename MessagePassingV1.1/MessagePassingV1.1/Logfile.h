#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <windows.h>

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

using namespace std;

class Logfile
{
public:
	bool static Write(string message);
};

