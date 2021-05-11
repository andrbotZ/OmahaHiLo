// OmahaHiLo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OmahaIO.h"



int main()
{
    OmahaIO omahoIO;

    bool isOpened = omahoIO.OpenFile("C:/Users/pocht/Desktop/jobs/iGates/OmahaHiLo/input.txt");
    if (isOpened) {
        omahoIO.ReadFile();
        omahoIO.CloseFile();
        omahoIO.PrintData();
    }
   

   
}

