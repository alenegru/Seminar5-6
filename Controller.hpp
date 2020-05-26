//
//  Controller.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 27/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "Auto.h"
#include "Repository.hpp"
#include <vector>
#include "rental.h"

using namespace std;

class Controller: public Repo {
public:
    Repo repo;
    Controller();
    Controller(Repo r);
    ~Controller();

    Auto findAutoById(int id);
    vector <Auto> findAll();
    Kunde saveAuto(Auto car, Kunde client);
    Kunde updateAuto(Auto car1, Auto car2, Kunde& client);
    Kunde deleteAuto(Auto car, Kunde& client);
};
#endif /* Controller_hpp */
