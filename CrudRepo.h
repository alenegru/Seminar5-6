//
//  Header.h
//  seminarul3
//
//  Created by Alexandra Negru on 27/04/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include "Auto.h"
#include <vector>
using namespace std;

template <class E>

class CrudRepository {
public:
    virtual E findOne(int id) = 0;

    virtual vector <E> findAll() = 0;

    virtual E save(E entity) = 0;
     
    virtual E del(int id) = 0;

    virtual E update(E entity, string marke) = 0;

    virtual ~CrudRepository() {};
};

#endif /* Header_h */
