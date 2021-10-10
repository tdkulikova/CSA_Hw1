//
// Created by Таня Куликова on 26.09.2021.
//


#include "triangle.h"
#include <stdio.h>
#include <math.h>

//------------------------------------------------------------------------------
// triangle.cpp - contains functions for working with triangle.
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Inputting the parameters of the triangle.

void inputFromFile(triangle &t, FILE *file_in) {
    fscanf(file_in, "%d", &t.a.x);
    fscanf(file_in, "%d", &t.a.y);
    fscanf(file_in, "%d", &t.b.x);
    fscanf(file_in, "%d", &t.b.y);
    fscanf(file_in, "%d", &t.c.x);
    fscanf(file_in, "%d", &t.c.y);
}

//------------------------------------------------------------------------------
// Random inputting of the triangle parameters.

void randomInput(triangle &t) {
    double A;
    double B;
    double C;
    do {
        t.a.x = Random();
        t.a.y = Random();
        t.b.x = Random();
        t.b.y = Random();
        t.c.x = Random();
        t.c.y = Random();
        A = sqrt(pow(t.b.x - t.a.x, 2) + pow(t.b.y - t.a.y, 2));
        B = sqrt(pow(t.c.x - t.b.x, 2) + pow(t.c.y - t.b.y, 2));
        C = sqrt(pow(t.c.x - t.a.x, 2) + pow(t.c.y - t.a.y, 2));

    } while ((C >= (A + B))
             || (A >= (B + C))
             || (B >= (C + A)));
}

//------------------------------------------------------------------------------
// Outputting of the triangle parameters.

void output(triangle &t, FILE *file_out) {
    double A = sqrt(pow(t.b.x - t.a.x, 2) + pow(t.b.y - t.a.y, 2));
    double B = sqrt(pow(t.c.x - t.b.x, 2) + pow(t.c.y - t.b.y, 2));
    double C = sqrt(pow(t.c.x - t.a.x, 2) + pow(t.c.y - t.a.y, 2));
    if (A < B + C && B < A + C && C < A + B) {
        fprintf(file_out, "It is Triangle:\nA = ");
        fprintf(file_out, "%f", A);
        fprintf(file_out, " B = ");
        fprintf(file_out, "%f", B);
        fprintf(file_out, " C = ");
        fprintf(file_out, "%f", C);
        fprintf(file_out, " Square = ");
        fprintf(file_out, "%f", square(t));
    } else {
        fprintf(file_out, "It is Triangle:\n");
        fprintf(file_out, "Something wrong with triangle coordinates! ");
        fprintf(file_out, " Square = ");
        fprintf(file_out, "%f", 0.0);
    }
}

//------------------------------------------------------------------------------
// Counting the triangle square.

double square(triangle &t) {
    double A = sqrt(pow(t.b.x - t.a.x, 2) + pow(t.b.y - t.a.y, 2));
    double B = sqrt(pow(t.c.x - t.b.x, 2) + pow(t.c.y - t.b.y, 2));
    double C = sqrt(pow(t.c.x - t.a.x, 2) + pow(t.c.y - t.a.y, 2));
    if (A < B + C && B < A + C && C < A + B) {
        return 0.5 * abs(t.a.x * (t.b.y - t.c.y) + t.b.x * (t.c.y - t.a.y) + t.c.x * (t.a.y - t.b.y));
    } else {
        return 0.0;
    }
}
