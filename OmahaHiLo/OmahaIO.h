#pragma once
#include <string>
#include <fstream>
#include <list>
#include <vector>

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
		list<string> getData();
		bool CreateFile(string path);
		void SaveResultsInFile(vector<string> lines, string path);
};