//
// Created by Таня Куликова on 26.09.2021.
//

//------------------------------------------------------------------------------
// rectangle.cpp - contains functions for working with the rectangle.
//------------------------------------------------------------------------------

#include "rectangle.h"
#include <stdio.h>


//------------------------------------------------------------------------------
// Inputting of the rectangle parameters.

void inputFromFile(rectangle &r, FILE *file_in) {
    fscanf(file_in, "%d", &r.left_up.x);
    fscanf(file_in, "%d", &r.left_up.y);
    fscanf(file_in, "%d", &r.right_down.x);
    fscanf(file_in, "%d", &r.right_down.y);
}

//------------------------------------------------------------------------------
// Random inputting of the rectangle parameters.

void randomInput(rectangle &r) {
    do {
        r.left_up.x = Random();
        r.left_up.y = Random();
        r.right_down.x = Random();
        r.right_down.y = Random();
    } while (r.left_up.x == r.right_down.x || r.left_up.y == r.right_down.y);
}

//------------------------------------------------------------------------------
// Outputting of the rectangle parameters.

void output(rectangle &r, FILE *file_out) {
    if (r.right_down.x != r.left_up.x && r.right_down.y != r.left_up.y) {
        fprintf(file_out, "It is Rectangle:\nA = ");
        fprintf(file_out, "%d", abs(r.left_up.y - r.right_down.y));
        fprintf(file_out, " B = ");
        fprintf(file_out, "%d", abs(r.right_down.x - r.left_up.x));
        fprintf(file_out, " Square = ");
        fprintf(file_out, "%f", square(r));
    } else {
        fprintf(file_out, "It is Rectangle:\n");
        fprintf(file_out, "Something wrong with rectangle coordinates! ");
        fprintf(file_out, " Square = ");
        fprintf(file_out, "%f", square(r));
    }
}

//------------------------------------------------------------------------------
// Counting the rectangle square.

double square(rectangle &r) {
    return abs(r.left_up.y - r.right_down.y) * abs(r.right_down.x - r.left_up.x);
}
