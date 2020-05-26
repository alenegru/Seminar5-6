//
//  BubbleSort.hpp
//  seminarul3
//
//  Created by Alexandra Negru on 26/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#ifndef BubbleSort_hpp
#define BubbleSort_hpp

#include <stdio.h>
#include "SortMethod.h"

class BubbleSort : public Sort_Method {
public:
    // Sorts the list of cars with bubble-sort in lexicographic order
    void sort_autos(std::vector <Auto>& autos);
};
#endif /* BubbleSort_hpp */
