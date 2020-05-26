#pragma once
#include <string>
using namespace std;
class Auto {
private:
	int id;
	string marke;
	string modell;

public:
    Auto();
	Auto(int id, string marke, string modell);

    // getters
	int getId() const;
	string getMarke() const;
	string getModell() const;

	// setters
	void setId(int newId);
	void setMarke(string newMarke);
	void setModell(string newModell);
    
    void show_auto();
    virtual string toString() const;

    // Overloading Comparsion Operators
    friend bool operator == (const Auto& a1, const Auto& a2);
    friend bool operator != (const Auto& a1, const Auto& a2);

};

