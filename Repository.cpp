//
//  Repository.cpp
//  seminarul3
//
//  Created by Alexandra Negru on 27/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "Repository.hpp"
 #include "CrudRepo.h"
#include <string>
#include "rental.h"
using namespace std;

Repo::Repo() {
}

Repo::Repo(Rental r) {
    rental = r;
}

Auto Repo::findOne(int id) {
    Auto null_auto;
    for (int i = 0; i < rental.autos.size(); i++)
        if (rental.autos[i].getId() == id)
            return rental.autos[i];
    return null_auto;
}

vector <Auto> Repo::findAll() {
    return rental.autos;
}

Auto Repo::save(Auto new_car) {
    Auto null_auto;
    for (int i = 0; i < rental.autos.size(); i++)
        if (rental.autos[i].getId() == new_car.getId())
            return rental.autos[i];
    rental.autos.push_back(new_car);
    return null_auto;
}

Auto Repo::del(int id) {
    Auto null_auto;
    for (int i = 0; i < rental.autos.size(); i++)
        if (rental.autos[i].getId() == id) {
            null_auto = rental.autos[i];
            rental.autos.erase(rental.autos.begin() + i);
            return null_auto;
        }
    return null_auto;
}

Auto Repo::update(Auto car, string marke) {
    Auto null_auto;
    for (int i = 0; i < rental.autos.size(); i++)
        if (rental.autos[i].getId() == car.getId()) {
            rental.autos[i].setMarke(marke);
            car = rental.autos[i];
            return rental.autos[i];
        }

    return null_auto;
}
