#pragma once
#include <string>
#include <fstream>
#include <list>

using namespace std;

class OmahaIO
{
private:
	fstream _inputFile;
	list<string> _lines;

	public:
		bool OpenFile(string  path);
		bool CloseFile();
		void ReadFile();
		void PrintData();


};