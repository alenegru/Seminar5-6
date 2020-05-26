#pragma once
#include "kunde.h"
#include "Auto.h"
#include "Reservation.hpp"
#include "AutoInMemoryRepository.hpp"
#include <vector>
#include "kunde.h"
using namespace std;


class Rental {
private:
    AutoInMemoryRepository repository;  // List with all the available cars of the rental company
    std::vector<Auto*> autos;  // List with all the available cars of the rental company from SEMINAR3
    std::vector<Kunde> clients;  // List with all the clients of the rental company

    std::vector<Reservation> orders;  // List with all the orders made by the clients of the rental company
public:
    // Default Constructor
    Rental();

    // Destructor
    ~Rental();

    // Returns the list of clients
    std::vector<Kunde> getClients() const;

    // Returns a reference to the list of clients vector
    std::vector<Kunde>& getClients();

    // Returns a reference to the list with all the available cars to be rented
    AutoInMemoryRepository& getRepository();

    // Adds a client into the clients vector
    void add_client(Kunde _client);

    // Deletes a client from the clients vector
    void delete_client(Kunde _client);

    // Updates a clients data
    void update_client(Kunde _client, double new_id, std::string new_name);

    // Adds a car into the cars vector
    void add_auto(Auto* _auto);

    // Deletes a car from the cars vector
    void delete_auto(Auto* _auto);

    // Prints details about the cars
    void toString_cars() const;

    // Prints details about the clients
    void toString_clients() const;

    // Returns the list of orders and a refference to the list of orders
    std::vector<Reservation> getOrders() const;
    std::vector<Reservation>& getOrders();

    // Shows the orders of the clients
    void show_orders() const;

    // Adds a oder into the list with orders
    void reserve_auto(int, int, int);

    // Shows all orders
    void show_reservierungen();

    // Deletes an order
    void delete_reservierung(int, int);
    
    // Deletes a reservierung
    void return_auto(Auto a, Kunde k);

    // Extends the days for a reservierung
    void extend_reservation(Auto a, Kunde k);
};
