//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_CIRCLE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_CIRCLE_H
#ifndef __circle__
#define __circle__

//------------------------------------------------------------------------------
// circle.h - the header, which contains the description of the circle
//------------------------------------------------------------------------------



#include <stdio.h>
# include "random.h"
# include "coordinates.h"

// The struct with circle parameters.

struct circle {

    // Coordinates of the circle center.

    point center;

    // The radius.

    int radius;
};

// Input of circle parameters from the file.

void inputFromFile(circle &circle, FILE*file_in);

// Random input of the circle parameters.

void randomInput(circle &circle);

// Output to the file.

void output(circle &circle, FILE* file_out);

// Counting the square of the circle.

double square(circle &circle);

#endif

#endif

