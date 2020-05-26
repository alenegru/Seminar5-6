#include "pkw.h"
#include "Auto.h"
#include <iostream>

using namespace std;

PKW::PKW(string Sonderausstattungen, int ID, string MARKE, string MODELL):Auto(ID, MARKE, MODELL) {
    this->Sonderausstattungen = Sonderausstattungen;
}

PKW::PKW() {
    Sonderausstattungen = "?";
}
