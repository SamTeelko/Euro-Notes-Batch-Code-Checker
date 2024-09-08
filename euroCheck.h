#ifndef BLATT2_EUROCHECK_H
#define BLATT2_EUROCHECK_H

#include <string>
#include <iostream>

// TODO Aufgabe 2:
//  Deklariert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
int getEuroSerialNumberVersion(std::string & serialNumber);


bool checkEuroSerialNumber2002(std::string & serialNumber);
bool checkEuroSerialNumber2013(std::string & serialNumber);
bool isLetter(char c);
bool isNumber(char c);
int toNumber(char c);
int sumUp(std::string & serialNumber);
int createTestziffer2013(int sum);
int createTestziffer2002(int sum);
int createPruefziffer(std::string & serialNumber);

#endif //BLATT2_EUROCHECK_H
