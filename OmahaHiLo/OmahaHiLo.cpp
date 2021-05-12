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

    directory = argv[0];
    inputFile = argv[1];


  //  directory = directory.substr(0, directory.find_last_of("\\/"));
    cout << directory << endl;
    std::replace(directory.begin(), directory.end(), '\\', '\/');
 //   inputFile = directory + '/' + inputFile;
    outputFile = argv[2];
 //   outputFile = directory + '/' + outputFile;
  //  std::replace(outputFile.begin(), outputFile.end(), '\\', '/');
    

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
 

