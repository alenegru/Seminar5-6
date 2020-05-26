#include "Auto.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Auto::Auto() {
    id = 0;
    marke = "?";
    modell = "?";
}

Auto::Auto(int id, string marke, string modell) {
	this->id = id;
	this->marke = marke;
	this->modell = modell;
}

// getters
int Auto::getId() const{ return this->id; }
string Auto::getMarke() const{ return this->marke; }
string Auto::getModell() const{ return this->modell; }

// setters
void Auto::setId(int newId) { this->id = newId; }
void Auto::setMarke(string newMarke) { this->marke = newMarke; }
void Auto::setModell(string newModell) { this->modell = newModell; }

void Auto::show_auto() {
    cout << "ID: " << id << " Marke: " << marke << " Modell: " << modell << endl;
}

std::string Auto::toString() const {
    stringstream out;
    out << "Auto \n\tID: " << this->id << endl << "\tMarke: " << this->marke << endl << "\tModell: " << this->modell << endl << endl;
    return out.str();
}

bool operator == (const Auto& a1, const Auto& a2) {
    return ((a1.getId() == a2.getId()) && (a1.getMarke() == a2.getMarke()) && (a1.getModell() == a2.getModell()));
}
bool operator != (const Auto& a1, const Auto& a2) {
    return !(a1 == a2);
 }

