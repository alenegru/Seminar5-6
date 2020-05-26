#include "kunde.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Kunde::Kunde() {
    this->id = 0;
    this->name = "?";
}

Kunde::Kunde(int id, string name) {
	this->id = id;
	this->name = name;
}

// getters
int Kunde::getId() const { return this->id; }
string Kunde::getName() const { return this->name; }

// setters
void Kunde::setId(int newId) { this->id = newId; }
void Kunde::setName(string newName) { this->name = newName; }

void Kunde::show_clients() {
    cout << "ID: " << id << " Name: " << name << endl;
}

std::string Kunde::toString() const {
    stringstream out;
    out << "Kunde \n\tID: " << this->id << endl << "\tName: " << this->name << endl << endl;
    return out.str();
}

bool operator == (const Kunde& k1, const Kunde& k2) {
    return ((k1.getId() == k2.getId()) && (k1.getName() == k2.getName()));
}
bool operator != (const Kunde& k1, const Kunde& k2) {
    return !(k1 == k2);
}
