//
// Created by Таня Куликова on 26.09.2021.
//

#include "circle.h"
#include <stdio.h>
#include <math.h>

//------------------------------------------------------------------------------
// circle.cpp - contains functions for working with circle.
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Inputting the circle parameters.

void inputFromFile(circle &c, FILE *file_in) {
    fscanf(file_in, "%d", &c.center.x);
    fscanf(file_in, "%d", &c.center.y);
    fscanf(file_in, "%d", &c.radius);
}

// Random input of the circle parameters.

void randomInput(circle &c) {
    do {
        c.center.x = Random();
        c.center.y = Random();
        c.radius = Random();
    } while (c.radius <= 0);
}

//------------------------------------------------------------------------------
// Outputting the circle parameters.

void output(circle &c, FILE *file_out) {
    if (c.radius > 0) {
        fprintf(file_out, "It is Circle:\n");
        fprintf(file_out, "Center coordinates: x = ");
        fprintf(file_out, "%d", c.center.x);
        fprintf(file_out, " y = ");
        fprintf(file_out, "%d", c.center.y);
        fprintf(file_out, " Radius = ");
        fprintf(file_out, "%d", c.radius);
        fprintf(file_out, " Square = ");
        fprintf(file_out, "%f", square(c));
    } else {
        fprintf(file_out, "It is Circle:\n");
        fprintf(file_out, "There is an error. Radius can not be negative or zero.");
        fprintf(file_out, " Square = ");
        fprintf(file_out, "%f", square(c));
    }
}

//------------------------------------------------------------------------------
// Counting the circle square.

double square(circle &c) {
    if (c.radius > 0) {
        return M_PI * c.radius * c.radius;
    } else {
        return 0.0;
    }
}
