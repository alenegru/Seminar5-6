//
//  Console.cpp
//  seminarul3
//
//  Created by Alexandra Negru on 27/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "Console.hpp"
#include <iostream>
using namespace std;

Console::Console(Controller c) {
    cont = c;
}

Console::~Console() {
}

void Console::show_clients_and_cars() {
    cout << "Autos:\n";

    for (int i = 0; i < cont.repo.rental.autos.size(); i++)
        cont.repo.rental.autos[i].show_auto();

    cout << "\nClients:\n";
    for (int i = 0; i < cont.repo.rental.clients.size(); i++)
        cont.repo.rental.clients[i].show_clients();
    cout << endl;
}

void Console::build_menu() {
    cout << "\nOptions\n0 - Exit\n1 - Find Auto by ID\n2 - Find All\n3 - Save Auto to Client\n4 - Update Auto\n5 - Delete Auto\n6 - Show Orders\n";
}

void Console::choose_option() {
    build_menu();
    cout << "Choose option:\nYour option: ";
    char option = '7';

    cin >> option;

    if (option == '1') {
        int id;
        cout << "\nEnter Auto ID to be found: ";
        cin >> id;

        Auto a;
        a = cont.findAutoById(id);
        a.show_auto();
    }
    
    if (option == '2') {
        cout << "List of Autos:\n";

        for (int i = 0; i < cont.repo.rental.autos.size(); i++)
            cont.repo.rental.autos[i].show_auto();
    }
    
    if (option == '3') {
        show_clients_and_cars();

        int id;
        int id_car;

        cout << "Give client ID: ";
        cin >> id;

        cout << "Give car ID: ";
        cin >> id_car;

        Auto a;
        for (int i = 0; i < cont.repo.rental.autos.size(); i++)
            if (id_car == cont.repo.rental.autos[i].getId())
                a = cont.repo.rental.autos[i];

        Kunde k;
        for (int i = 0; i < cont.repo.rental.clients.size(); i++)
            if (id == cont.repo.rental.clients[i].getId())
                k = cont.repo.rental.clients[i];
        cont.saveAuto(a, k);
    }
    if (option == '4') {
        show_clients_and_cars();
        cont.repo.rental.show_orders();

        int id;
        int id_car1;
        int id_car2;

        cout << "Give client ID: ";
        cin >> id;

        cout << "Give client car ID: ";
        cin >> id_car1;

        cout << "Give update car ID: ";
        cin >> id_car2;

        Auto a1;
        for (int i = 0; i < cont.repo.rental.autos.size(); i++)
            if (id_car1 == cont.repo.rental.autos[i].getId())
                a1 = cont.repo.rental.autos[i];
        Auto a2;
        for (int i = 0; i < cont.repo.rental.autos.size(); i++)
            if (id_car2 == cont.repo.rental.autos[i].getId())
                a2 = cont.repo.rental.autos[i];

        Kunde k;
        for (int i = 0; i < cont.repo.rental.clients.size(); i++)
            if (id == cont.repo.rental.clients[i].getId())
                k = cont.repo.rental.clients[i];

        cont.updateAuto(a1, a2, k);
    }
    if (option == '5') {
        int id;
        int id_car;

        cout << "Give client ID: ";
        cin >> id;

        cout << "Give car ID: ";
        cin >> id_car;
    
        Auto a;
        for (int i = 0; i < cont.repo.rental.autos.size(); i++)
            if (id == cont.repo.rental.autos[i].getId())
                a = cont.repo.rental.autos[i];

        Kunde k;
        for (int i = 0; i < cont.repo.rental.clients.size(); i++)
            if (id_car == cont.repo.rental.clients[i].getId())
                k = cont.repo.rental.clients[i];

        cont.deleteAuto(a, k);
    }
    if (option == '0') {
        return;
    }
    if (option == '6') {
        cont.repo.rental.show_orders();
    }
    choose_option();
}
