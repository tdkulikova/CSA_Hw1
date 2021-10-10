//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_RECTANGLE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_RECTANGLE_H
#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - the header, which contains the description of the rectangle
//------------------------------------------------------------------------------

#include<stdio.h>
# include "random.h"
#include "coordinates.h"

// The struct with rectangle parameters.

struct rectangle {

    // Coordinates of the upside left point and the downside right point.

    point left_up;
    point right_down;
};

// Input of rectangle parameters from the file.

void inputFromFile(rectangle &rect,FILE* file_in);

// Random input of the rectangle parameters.

void randomInput(rectangle &rectangle);

// Output to the file.

void output(rectangle &rectangle, FILE*file_out);

// Counting the square of the rectangle.

double square(rectangle &rectangle);

#endif

#endif
