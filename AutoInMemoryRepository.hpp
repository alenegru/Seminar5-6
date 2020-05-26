//
//  AutoInMemoryRepository.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 25/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef AutoInMemoryRepository_hpp
#define AutoInMemoryRepository_hpp

#include <stdio.h>
#include "CrudRepo.h"
#include "Auto.h"
#include <vector>

class AutoInMemoryRepository : public CrudRepository<Auto> {
private:
    std::vector<Auto> autos_in_memory;  // Vector with all the possible cars to be booked/ordered
public:
    // Default constructor
    AutoInMemoryRepository();

    // Returns reference to the vector with cars
    std::vector<Auto>& get_autos_in_memory();

    // Searches for a car in the repository by ID
    Auto find_one(int id);

    // Returns the vector of cars
    std::vector<Auto> find_all();

    // Adds a car to the list if it doesn't exists
    Auto save(Auto entity);

    // Deletes a car from the list if it does exist
    Auto del(int id);

    // Updates the data of a car from the list
    Auto update(Auto entity);
};
#endif /* AutoInMemoryRepository_hpp */
