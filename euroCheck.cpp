#include "euroCheck.h"
#include <iostream>
#include <regex>


using std::string;

// TODO Aufgabe 2:
//  Implementiert die Funktion `getEuroSerialNumberVersion(serialNumber)`.
//  Sie soll je nach Version der Banknote das entsprechende Jahr (2013 oder 2002) als `int` zurückgeben, und 0 für ungültige Seriennummern.
//  Seriennummern vor 2013 haben *einen* Buchstaben am Anfang. Seit 2013 sind es *zwei*.



int getEuroSerialNumberVersion(string & serialNumber) {
    // ^ und $ begrenzen die Länge des Strings, damit nur ein String geprüft wird der nur eine bestimmte Zahl an Zeichen lang ist.
    // [a-zA-Z]{n} prüft, ob die ersten n Zeichen im Alphabet vorkommen.
    // [0-9]{n} prüft, ob die ersten n Zeichen Zahlen sind.
    std::regex pattern2013("^[a-zA-Z]{2}[0-9]{10}$");
    std::regex pattern2002("^[a-zA-Z]{1}[0-9]{11}$");

    if (std::regex_match(serialNumber, pattern2013)) {
        return 2013;
    }
    else if (std::regex_match(serialNumber, pattern2002)) {
        return 2002;
    }
    return 0;
}

// TODO Aufgabe 3+5:
//  Definiert die Funktion `checkEuroSerialNumber2002(serialNumber)`.
//  Format: L NNNNNNNNNN N
//  (Leerzeichen im Format werden vom Nutzer nicht mit eingegeben, sondern helfen hier nur beim Zählen)
//  Tipp: `x / 10` liefert die Zehnerstelle und `x % 10` die Einerstelle einer zweistelligen Zahl x.


bool checkEuroSerialNumber2002(std::string & serialNumber) {
    int sum = sumUp(serialNumber);
    int testziffer = createTestziffer2002(sum);
    int pruefziffer = createPruefziffer(serialNumber);
    return testziffer == pruefziffer;
}

// TODO Aufgabe 3+6:
//  Definiert die Funktion `checkEuroSerialNumber2013(serialNumber)`.
//  Format: LL NNNNNNNNN N
bool checkEuroSerialNumber2013(std::string & serialNumber) {
    int sum = sumUp(serialNumber);
    int testziffer = createTestziffer2013(sum);
    int pruefziffer = createPruefziffer(serialNumber);
    return testziffer == pruefziffer;
}

int sumUp(std::string & serialNumber) {
    int sum = 0;
    for (int i = 0; i < serialNumber.length()-1; i++) {
        sum += toNumber(serialNumber[i])%10 +toNumber(serialNumber[i])/10 ;
    }
    return sum;
}


int createTestziffer2013(int sum) {
    int testziffer = 7 - (sum % 9);
    switch(testziffer){
        case 0:
            testziffer = 9;
            return testziffer;
            break;
        case -1:
            testziffer = 8;
            return testziffer;
    };

    return testziffer ;
}

int createTestziffer2002(int sum) {
    int testziffer = 8 - (sum % 9);
    if(testziffer == 0){
        testziffer = 9;
    }
    return testziffer;

}

int createPruefziffer(std::string & serialNumber) {
    int pruefziffer = toNumber(serialNumber[serialNumber.length()-1]);
    return pruefziffer;
}

// L
bool isLetter(char c) {
    return isalpha(c);                //; 'A' <= c && c <= 'Z'  um allgemein auch für kleine Buchstaben zu funktionieren  " isalpha() "  benutzen
}
// N

bool isNumber(char c) {
    return '0' <= c && c <= '9';
}

int toNumber(char c) {
    if (isNumber(c)) {
        return c - '0';
    }
    if (isLetter(c)) {
        c = static_cast<char>(toupper(c));
        return c - 'A' + 1;
    }
    std::cout << "Error: toNumber(char): " << c << std::endl;
    return 0;
}