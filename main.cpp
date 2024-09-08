//Prüfzifferbeispiel 2013:
//rp2401037235
//nc1134053495
//ec0543821399
//VA6529953143
//Prüfzifferbeispiel 2002:
//n61137837714

#include <iostream>


// TODO Aufgabe 3:
//  Inkludiert die Funktionen aus den `euroCheck.h/cpp`-Dateien.

#include "euroCheck.h"


using std::string;

// TODO Aufgabe 1:
//  Definiert die Funktion `inputNextSerialNumber()` so, dass sie eine Seriennummer als `string` auf der Konsole einliest und diese zurückgibt.

string inputNextSerialNumber() {
    string serialNumber;
    std::cout << "Input serial number"<< std::endl;
    std::cin >> serialNumber;
    return serialNumber;
};

// TODO Aufgabe 3:
//  Implementiert die Funktion `checkSerialNumberAndPrintResult(serialNumber)`.
//  Sie soll mithilfe der Funktion `getEuroSerialNumberVersion(serialNumber)` ermitteln, um welche Version einer Euro-Banknote es sich handelt, und die entsprechende Jahreszahl in der Konsole ausgeben.
//  Anschliessend soll in einer Fallunterscheidung (switch) anhand der Jahreszahl die entsprechende Funktion `checkEuroSerialNumber2013/2002(serialNumber)` aufgerufen und das Ergebnis (Gueltig/Ungueltig) auf der Konsole ausgeben werden.

void printValidity(bool isValid) {
    if(isValid) {
        std::cout << "Gueltig" << std::endl;
    } else {
        std::cout << "Ungueltig" << std::endl;
    }
}

void checkSerialNumberAndPrintResult(string & serialNumber) {
    int version = getEuroSerialNumberVersion(serialNumber);

    switch(version) {
        case 2013:
            printValidity(checkEuroSerialNumber2013(serialNumber));
            break;

        case 2002:
            printValidity(checkEuroSerialNumber2002(serialNumber));
            break;

        case 0: default:
            std::cout << "Ungueltig" << std::endl;
            break;
    }
}




int main() {

    // TODO Aufgabe 4:
    //  Nutzt eine Kontrollstruktur, sodass nacheinander beliebig viele Seriennummern geprüft werden können.

    // TODO Aufgabe 1:
    //  Ruft `inputNextSerialNumber()` auf, um eine Seriennummer einzugeben.


    // TODO Aufgabe 4:
    //  Das Programm soll beendet werden, wenn statt einer Seriennummer "fertig" eingegeben wurde.





    bool finished = false;
    while(!finished) {

        std::string serialNumber = inputNextSerialNumber();;
        if (serialNumber != "fertig") {
            checkSerialNumberAndPrintResult(serialNumber);
        } else {
            std::cout << "Das Pruefungsprogramm wird geschlossen";
            finished = true;
        }
    }
    return 0;
}
