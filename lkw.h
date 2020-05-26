#pragma once
#include <string>
#include <iostream>
#include "Auto.h"

using namespace std;

class LKW : public Auto {
private:
    int Gesamtgewicht;
    string Bezeichnung;
public:

    LKW();
    LKW(int Gesamtgewicht, string Bezeichnung, int ID, string MARKE, string MODELL);
    int get_Gesamtgewicht() { return Gesamtgewicht; }
    void Load();
    void Unload();

};

