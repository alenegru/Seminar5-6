//
//  Repository.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 27/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef Repository_hpp
#define Repository_hpp

#include <stdio.h>
#include <vector>
#include "CrudRepo.h"
#include "rental.h"

using namespace std;

class Repo: public CrudRepository<Auto> {
public:

    Rental rental;
    Repo();
    Repo(Rental r);
    
    Auto findOne(int id);

    vector <Auto> findAll();

    Auto save(Auto new_car);

    Auto del(int id);

    Auto update(Auto car, string marke);

};
#endif /* Repository_hpp */
