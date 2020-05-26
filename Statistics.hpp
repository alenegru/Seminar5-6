//
//  Statistics.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 26/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef Statistics_hpp
#define Statistics_hpp

#include <stdio.h>
#include "rental.h"
#include "Reservation.hpp"
#include <vector>

class Statistics{
public:
    // Returns the car with most reservations made
    Auto most_popular_auto(std::vector<Reservation> orders);

    // Returns the average of all the reservations number of days
    int average_rent_days(std::vector<Reservation> orders);
};

#endif /* Statistics_hpp */
