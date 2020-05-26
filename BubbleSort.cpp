//
//  BubbleSort.cpp
//  seminarul3
//
//  Created by Alexandra Negru on 26/05/2020.
//  Copyright © 2020 Alexandra Negru. All rights reserved.
//

#include "BubbleSort.hpp"
#include "Auto.h"
#include <iostream>

void BubbleSort::sort_autos(std::vector <Auto>& autos) {
    // Sorts the list of cars from the repository lexicographic with Bubblesort
    std::string copy1, copy2;
    for (size_t i = 0; i < autos.size() - 1; i++)
        // Last i elements are already in place
        for (size_t j = 0; j < autos.size() - i - 1; j++) {
            // Make all character from Brand string Uppercase
            copy1 = autos[j].getMarke();
            copy2 = autos[j + 1].getMarke();
            for (auto& c : copy1) c = toupper(c);
            for (auto& c : copy2) c = toupper(c);

            // Compares brands, both brands are now Uppercase
            if (copy1 > copy2) {
                Auto aux = autos[j];
                autos[j] = autos[j + 1];
                autos[j + 1] = aux;
            }
        }
}
