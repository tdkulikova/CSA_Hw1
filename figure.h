//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_FIGURE_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_FIGURE_H
#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// figure.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

//------------------------------------------------------------------------------
// The struct, which describes all figures.

struct figure {


    // Values of key for every figure.

    enum key {
        RECTANGLE,
        TRIANGLE,
        CIRClE
    };

    // The key.

    key key;

    // The enum of the figure colors.

    enum color {
        RED = 1,
        ORANGE,
        YELLOW,
        GREEN,
        CYAN,
        BLUE,
        PURPLE
    };
    color color;

    union {
        rectangle rect;
        triangle tr;
        circle circ;
    };
};

// Inputting the parameters of the figure.

figure *input(FILE *file_in);

// Inputting the color of the figure.

void inputColor(figure *figure, int color);

// Random input of the figure.

figure *randomInput();

// Output the figure to the file.

void output(figure &figure, FILE *file_out);

// Defining the color of the figure and outputting it.

void outputColor(figure &figure, FILE *file_out);

// Counting the square of the figure.

double square(figure &figure);

#endif

#endif
