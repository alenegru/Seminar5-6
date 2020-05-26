//
//  AutoInMemoryRepository.cpp
//  seminarul3
//
//  Created by Alexandra Negru on 25/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "AutoInMemoryRepository.hpp"
#define NULL_AUTO Auto()

AutoInMemoryRepository::AutoInMemoryRepository() {

}

std::vector<Auto>& AutoInMemoryRepository::get_autos_in_memory() {
    return autos_in_memory;
}

Auto AutoInMemoryRepository::find_one(int id) {
    // Searches the car by ID
    for (size_t i = 0; i < autos_in_memory.size(); i++)
        if (autos_in_memory[i].getId() == id)
            return autos_in_memory[i];

    return NULL_AUTO;
}

std::vector<Auto> AutoInMemoryRepository::find_all() {
    return autos_in_memory;
}

Auto AutoInMemoryRepository::save(Auto entity) {
    bool already_exists = false;
    
    // Checks if the car already exists in the repository
    for (size_t i = 0; i < autos_in_memory.size(); i++)
        if (autos_in_memory[i].getId() == entity.getId()) {
            already_exists = true;
            break;
        }
    
    // If not, adds it to the list with cars
    if (already_exists == false)
        autos_in_memory.push_back(entity);
    return entity;
}


Auto AutoInMemoryRepository::del(int id) {
    // Checks if the car exists in the repository
    for (size_t i = 0; i < autos_in_memory.size(); i++)
        if (autos_in_memory[i].getId() == id) {  // If found, car will be deleted and returned
            Auto aux = autos_in_memory[i];
            autos_in_memory.erase(autos_in_memory.begin() + i);
            return aux;
        }

    return NULL_AUTO;
}


Auto AutoInMemoryRepository::update(Auto entity) {
    // Checks if the car exists in the repository
    for (size_t i = 0; i < autos_in_memory.size(); i++)
        if (autos_in_memory[i].getId() == entity.getId()) {  // If found, sets the old car to the new one
            autos_in_memory[i] = entity;
            return NULL_AUTO;
        }
    return entity;
}
