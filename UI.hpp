//
//  UI.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 26/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef UI_hpp
#define UI_hpp

#include <stdio.h>
#include "AutoController.hpp"
#include "pkw.h"
#include "lkw.h"
#include "Statistics.hpp"

class UI {
private:
    AutoController* ac;

    // Menu options for SEMINAR4
    void build_menu_v1();

    // Menu options for SEMINAR5
    void build_menu_v2();

    // Prints all clients and cars
    void show_clients_and_cars();

    Statistics stats;
public:
    // Constructor with parameter
    UI(AutoController* c, Sort_Method_Type type);

    // Destructor
    ~UI();

    // Choose between SEMINAR4 UI and SEMIANR5 UI
    void choose_menu();

    // Main menu for SEMINAR4
    void SEMINAR4_menu();

    // Main menu for SEMINAR5
    void SEMINAR5_menu();
};
#endif /* UI_hpp */
