#pragma once
#include <string>
#include "Auto.h"
#include <vector>
using namespace std;
class Kunde
{
private:
	int id;
	string name;

public:
	Kunde(int id, string name);
    Kunde();
    vector <Auto> orders;
	// getters
	int getId() const;
	string getName() const;

	// setters
	void setId(int newId);
	void setName(string newName);
    void show_clients();
    
    std::string toString() const;

    // Overloading Comparsion Operators
    friend bool operator == (const Kunde& k1, const Kunde& k2);
    friend bool operator != (const Kunde& k1, const Kunde& k2);
};

