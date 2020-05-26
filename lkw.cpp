#include "Auto.h"
#include "lkw.h"
#include <iostream>
#include <string>

using namespace std;

LKW::LKW()
{
    Gesamtgewicht = 0;
    Bezeichnung = "?";
}

LKW::LKW(int Gesamtgewicht, string Bezeichnung, int ID, string MARKE, string MODELL):Auto(ID, MARKE, MODELL) {
    this->Gesamtgewicht = Gesamtgewicht;
    this->Bezeichnung = Bezeichnung;
}

void LKW::Load() {
    Gesamtgewicht += 1;
}

void LKW::Unload() {
    if (Gesamtgewicht > 0)
        Gesamtgewicht -= 1;
    else
        cout << "Gesamtgewicht ist schon 0! Kann man nicht reduzieren\n";
}
