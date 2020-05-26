//
//  Reservation.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 26/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef Reservation_hpp
#define Reservation_hpp

#include <stdio.h>
#include "kunde.h"
#include "Auto.h"

class Reservation {
private:
    Kunde client;
    Auto car;
    int days;
    int status;
    
public:
    // Default constructor, does nothing
    Reservation();

    // Constructor with parameter, initalizes all attributes
    Reservation(Kunde, Auto, int);

    // Destructor, nothing to be destroyed manually
    ~Reservation();

    // Returns the client
    Kunde getClient();

    // Returns the car
    Auto getCar();

    // Returns the number of days
    int getDays();

    // Returns the status of the order
    int getStatus() const;

    // Sets the client to a new one
    void setClient(Kunde);

    // Sets the car to e new one
    void setCar(Auto);
    
    // Sets the numbers of day to a new one
    void setDays(int);

    // Sets the status of an order
    void setStatus(int);

    // Overloading Comparsion Operators
    friend bool operator == (const Reservation& r1, const Reservation& r2);
    friend bool operator != (const Reservation& r1, const Reservation& r2);

    // Prints details about the a Reservierung
    virtual std::string toString() const;
};

#endif /* Reservation_hpp */
