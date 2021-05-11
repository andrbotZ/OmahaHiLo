#include "OmahaIO.h"
#include <fstream>
#include <iostream>



bool OmahaIO::OpenFile(string path)
{
	
	_inputFile.open(path, std::fstream::in);

	if (_inputFile.is_open()) {
		return true;
	}
 
	return false;
}

bool OmahaIO::CloseFile()
{
	_inputFile.close();

	if (!_inputFile.is_open()) {
		return true;
	};

	return false;
}

void OmahaIO::ReadFile()
{
	string line;

	if (_inputFile.is_open()) {

		while (getline(_inputFile, line)){
			_lines.push_back(line);
		}
	 }
}

void OmahaIO::PrintData()
{
	string line;

	if (!_lines.empty()) {

		for (std::list<string>::iterator it = _lines.begin(); it != _lines.end(); ++it)
			std::cout << *it << '\n';	
	}
}


list<string> OmahaIO::getData()
{

	return _lines;
}

