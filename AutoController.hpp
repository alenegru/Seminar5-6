//
//  AutoController.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 25/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef AutoController_hpp
#define AutoController_hpp

#include <stdio.h>
#include "SortMethod.h"
#include "AutoInMemoryRepository.hpp"
#include "rental.h"


class AutoController {
private:
    Rental rental;  // Rental class, where the clients with their orders and all the available cars are stored
    AutoController();
    static AutoController* instance;  // Instance of the class, attributte used for the Singleton pattern

    Sort_Method* sort_method;
public:
    // Method used to deny this class having more than 1 instance
    static AutoController* get_instance();

    // Resests the instance, if scope kills the instans another one can be built
    static void reset_instance();
    
    // Searches for a car in the repository by ID
    Auto find_auto_by_id(int id);

    // Returns all cars from the repository
    std::vector <Auto> find_all();

    // Adds a car to the orders list of the client
    Kunde save_auto(Auto car, Kunde client);

    // Changes the data about car1 with car2 from clients orderlist
    Kunde update_auto(Auto car1, Auto car2, Kunde& client);

    // Deletes a car from clients orderlist
    Kunde delete_auto(Auto car, Kunde& client);
    
    // Returns reference to the rental class
    Rental& get_rental();

    // Returns reference to the repository
    AutoInMemoryRepository& get_repository();

    // Sets Rental
    void set_rental(Rental _rental);

    // Returns the pointer to the object Sort Method
    Sort_Method* get_sort_method() const;

    // Sets the Sort Method
    void set_sort_method(Sort_Method* _method);
};

#endif /* AutoController_hpp */
