#include "rental.h"
#include "pkw.h"
#include "lkw.h"
#include <iostream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using std::cout; using std::cin;
using std::endl;
using std::string;

Rental::Rental() {
    //cout << "Rental wurde gebaut" << endl;
}

Rental::~Rental() {
    //for (int i = 0; i != autos.size(); i++)
        //delete autos[i];

    //cout << "Rental wurde zerstort" << endl;
}

std::vector<Kunde> Rental::getClients() const {
    return clients;
}

std::vector<Kunde>& Rental::getClients() {
    return clients;
}

AutoInMemoryRepository& Rental::getRepository() {
    return repository;
}

void Rental::add_client(Kunde _client) {
    bool already_exists = false;
    
    // Checks if this _client already exists in the list
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getId() == _client.getId()) {
            already_exists = true;
            cout << "\nDiese ID existiert schon fur ein Kunde, nichts wird eingefugt\n";
            break;
        }
            
    this->clients.push_back(_client);
}

void Rental::delete_client(Kunde _client) {
    // Checks if the client exists, if not, nothing happens
    bool deleted = false;
    for (int i = 0; i != clients.size(); i++)
        if (clients[i].getId() == _client.getId()) {
            clients.erase(clients.begin() + i);
            deleted = true;
            break;
        }
    if (deleted == false)
        cout << "\nKunde wurde nicht gefunden, nichts wurde geloscht\n";
}

void Rental::update_client(Kunde _client, double new_id, std::string new_name) {
    // Checks if the client exists, if not, nothing happens
    for (int i = 0; i != clients.size(); i++)
        if (clients[i].getId() == _client.getId()) {
            clients[i].setId(new_id);
            clients[i].setName(new_name);
            break;
        }
}
// ---------- Funktion vom Seminar 3 ---------- //
void Rental::add_auto(Auto* _auto) {
    this->autos.push_back(_auto);
}
// ---------- Funktion vom Seminar 3 ---------- //
void Rental::delete_auto(Auto* _auto) {
    for (int i = 0; i != autos.size(); i++)
        if (*autos[i] == *_auto) {
            autos.erase(autos.begin() + i);
            break;
        }
}
// ---------- Funktion vom Seminar 3 ---------- //
void Rental::toString_cars() const {
    cout << "\nAutos die vermietet wurden: \n";

    for (int i = 0; i != autos.size(); i++) {
        // Und ist es ok wie ich dowcastig gemacht habe?
        LKW* lkw = dynamic_cast<LKW*>(autos.at(i));
        PKW* pkw = dynamic_cast<PKW*>(autos.at(i));
        if (lkw)
            cout << lkw->toString();
        else if (pkw)
            cout << pkw->toString();
        else
            cout << autos[i]->toString();


        // Wenn ich diese 2 losche, werden die Adressen der eigentlichen Objekten zerstort, aber werden keine memory leaks geben wenn diese unzerstort bleiben?
        //delete lkw;
        //delete pkw;
    }
}

void Rental::toString_clients() const {
    cout << "\nKunden die Autos vermietet haben:\n";
    for (int i = 0; i != clients.size(); i++)
        cout << clients[i].toString() << endl;
}

void Rental::show_orders() const {
    cout << "\nOrders:\n";

    // Shows the clients and all orders for each client
    for (size_t i = 0; i < clients.size(); i++) {
        sleep_for(nanoseconds(800000000));
        //cout << clients[i].orders.toString();
        if (clients[i].orders.size() != 0) {
            cout << "HAS ORDERED: \n";
            for (size_t j = 0; j < clients[i].orders.size(); j++) {
                sleep_for(nanoseconds(300000000));
                cout << clients[i].orders[j].toString();
            }
                
        }
        else
            cout << "HAS ORDERED NOTHING\n";
        cout << endl;
    }
}

std::vector<Reservation> Rental::getOrders() const {
    return orders;
}
std::vector<Reservation>& Rental::getOrders() {
    return orders;
}

void Rental::reserve_auto(int id_client, int id_car, int _days) {
    bool already_exists = false;
    bool gasit_client = false;
    bool gasit_masina = false;

    // Searching to see if a valid ID was introduced
    Auto a;
    for (size_t i = 0; i < repository.getAutos_InMemory().size(); i++)
        if (repository.getAutos_InMemory()[i].getID() == id_car) {
            a = repository.getAutos_InMemory()[i];
            gasit_masina = true;
            break;
        }
        
    // Searching to see if a valid ID was introduced
    Kunde k;
    for (size_t i = 0; i < clients.size(); i++)
        if (clients[i].getId() == id_client) {
            k = clients[i];
            gasit_client = true;
            break;
        }

    // If both client and car exists in our list -> make the order
    if (gasit_masina == true and gasit_client == true) {
        Reservation order(k, a, _days);
        // Checks if the order has already been placed, if yes, nothing happens
        int pos;
        for (size_t i = 0; i < orders.size(); i++)
            if (order == orders[i]) {
                already_exists = true;
                pos = i;
            }
                
        if (already_exists == false)  // If order doesn't exist, add it
            orders.push_back(order);
        else  // If order already exists->extend it
            extend_reservation(a, k);
    }
    else
        cout << "\nClient ID or car ID incorrect\n";
}


void Rental::show_reservierungen() {
    cout << "\nReservierungen:\n";

    // Shows the clients and all orders for each client
    for (size_t i = 0; i < orders.size(); i++) {
        sleep_for(nanoseconds(800000000));
        cout << orders[i].toString();
    }
}


void Rental::delete_reservierung(int id_client, int id_car) {
    bool already_exists = false;
    bool gasit_client = false;
    bool gasit_masina = false;

    // Searching for the order with this infos
    for (size_t i = 0; i < orders.size(); i++)
        if (orders[i].getCar().getId() == id_car and orders[i].getClient().getId() == id_client) {  // If found delete the auto (marks status as 2)
            Auto a = orders[i].getCar();
            Kunde k = orders[i].getClient();
            return_auto(a, k);
            return;
        }
    cout << "\nReservierung existiert nicht\n";
}

void Rental::return_auto(Auto a, Kunde k) {
    for (size_t i = 0; i < orders.size(); i++)
        if (orders[i].getCar() == a and orders[i].getClient() == k)
            orders[i].setStatus(2);
}


void Rental::extend_reservation(Auto a, Kunde k) {
    for (size_t i = 0; i < orders.size(); i++)
        if (orders[i].getCar() == a and orders[i].getClient() == k)
            orders[i].setStatus(1);
}
