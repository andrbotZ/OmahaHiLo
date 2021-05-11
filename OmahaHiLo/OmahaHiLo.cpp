// OmahaHiLo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OmahaIO.h"
#include "OmahaBoard.h"
#include <string>
#include <vector>



int main()
{
    OmahaIO omahoIO;
    OmahaBoard omahaBoard;

    bool isOpened = omahoIO.OpenFile("C:/Users/pocht/Desktop/jobs/iGates/OmahaHiLo/input.txt");
    if (isOpened) {
        omahoIO.ReadFile();
        omahoIO.CloseFile();
        omahoIO.PrintData();

        omahaBoard.DealCards(omahoIO.getData());
        omahaBoard.Play();
        vector<string> lines = omahaBoard.PrintResults();
        omahoIO.SaveResultsInFile(lines, "C:/Users/pocht/Desktop/jobs/iGates/OmahaHiLo/output.txt");
    }
   

   
}

