//
//  SortMethod.h
//  seminarul3
//
//  Created by Alexandra Negru on 26/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef SortMethod_h
#define SortMethod_h
#include <vector>
#include "Auto.h"

enum class Sort_Method_Type {
    Library_Sort, Bubble_Sort
};

class Sort_Method {
public:
    static Sort_Method* Create(Sort_Method_Type type);
    virtual void sort_authos(std::vector <Auto>& autos) = 0;
};

#endif /* SortMethod_h */
