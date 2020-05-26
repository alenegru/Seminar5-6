//
//  Controller.cpp
//  seminarul3
//
//  Created by Alexandra Negru on 27/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "Controller.hpp"
using namespace std;

Controller::Controller(Repo repo) {
    this->repo = repo;
}

Controller::Controller() {
}

Controller::~Controller() {
}

Auto Controller::findAutoById(int id) {
    return repo.findOne(id);
}

vector <Auto> Controller::findAll() {
    return repo.findAll();
}

Kunde Controller::saveAuto(Auto car, Kunde client) {
    Kunde client_fals;

    int gasit_client = -1;
    int gasit_masina = -1;

    for (int i = 0; i < repo.rental.clients.size(); i++)
        if (repo.rental.clients[i].getId() == client.getId())
            gasit_client = i;
    
    for (int i = 0; i < repo.rental.autos.size(); i++)
        if (repo.rental.autos[i].getId() == car.getId())
            gasit_masina = i;

    if (gasit_client != -1 and gasit_masina != -1) {
        repo.rental.clients[gasit_client].orders.push_back(car);
        return client;
    }
    return client_fals;
}

Kunde Controller::updateAuto(Auto car1, Auto car2, Kunde& client) {
    Kunde client_fals;

    int gasit_client = -1;
    int gasit_masina = -1;

    for (int i = 0; i < repo.rental.clients.size(); i++)
        if (repo.rental.clients[i].getId() == client.getId())
            gasit_client = i;

    for (int i = 0; i < repo.rental.autos.size(); i++)
        if (repo.rental.autos[i].getId() == car2.getId())
            gasit_masina = i;

    if (gasit_client != -1 and gasit_masina != -1) {
        for (int i = 0; i < repo.rental.clients[gasit_client].orders.size(); i++)
            if (repo.rental.clients[gasit_client].orders[i].getId() == car1.getId()) {
                repo.rental.clients[gasit_client].orders.erase(repo.rental.clients[gasit_client].orders.begin() + i);
                repo.rental.clients[gasit_client].orders.push_back(car2);
                return client;
            }
    }
    return client_fals;
}

Kunde Controller::deleteAuto(Auto car, Kunde& client) {
    Kunde client_fals;
    int gasit_client = -1;

    for (int i = 0; i < repo.rental.clients.size(); i++)
        if (repo.rental.clients[i].getId() == client.getId())
            gasit_client = i;
    if (gasit_client != -1) {
        for (int i = 0; i < repo.rental.clients[gasit_client].orders.size(); i++)
            if (repo.rental.clients[gasit_client].orders[i].getId() == car.getId()) {
                repo.rental.clients[gasit_client].orders.erase(repo.rental.clients[gasit_client].orders.begin() + i);
                return client;
            }
    }
    return client_fals;
}
