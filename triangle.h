//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_TRIANGLE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_TRIANGLE_H

#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - this is the header for describing the triangle.
//------------------------------------------------------------------------------

#include <fstream>

using namespace std;

# include "random.h"
# include "coordinates.h"

//------------------------------------------------------------------------------
// The struct with triangle parameters (coordinates of each angle).



struct triangle {
    point a;
    point b;
    point c;
};

// Inputting parameters from file.

void inputFromFile(triangle &triangle, FILE *file_in);

// Random input of the triangle parameters.

void randomInput(triangle &triangle);

// Output to the file.

void output(triangle &triangle, FILE* file_out);

// Counting the triangle square.

double square(triangle &triangle);

#endif

#endif
