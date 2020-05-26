//
//  Console.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 27/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef Console_hpp
#define Console_hpp

#include <stdio.h>
#include "Controller.hpp"
#include "pkw.h"
#include "lkw.h"
using namespace std;

class Console {
private:
    Controller cont;
public:
    Console(Controller c);
    ~Console();

    void build_menu();
    void choose_option();
    void show_clients_and_cars();

};
#endif /* Console_hpp */
