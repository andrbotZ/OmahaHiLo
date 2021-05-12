// OmahaHiLo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

 
#include "OmahaIO.h"
#include "OmahaBoard.h"
#include <string>
#include <vector>
#include<iostream>
 

using namespace std;

int main(int argc, char** argv)
{
    OmahaIO omahoIO;
    OmahaBoard omahaBoard;
    string directory;
    string inputFile;
    string outputFile;


    inputFile = argv[1];
    outputFile = argv[2];

    bool isOpened = omahoIO.OpenFile(inputFile);
    if (isOpened) {
        omahoIO.ReadFile();
        omahoIO.CloseFile();
        omahoIO.PrintData();

        omahaBoard.DealCards(omahoIO.getData());
        omahaBoard.Play();
        vector<string> lines = omahaBoard.PrintResults();
        omahoIO.SaveResultsInFile(lines, outputFile);
    }   
}
 

