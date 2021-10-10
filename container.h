//
// Created by Таня Куликова on 26.09.2021.
//

#ifndef COMPUTER_SYSTEM_ARCHITECTURE_HW1_CONTAINER_H
#define COMPUTER_SYSTEM_ARCHITECTURE_HW1_CONTAINER_H

#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - contains the special data structure for storing figures.
//------------------------------------------------------------------------------

#include "figure.h"

//------------------------------------------------------------------------------
// The primitive container - one-dimensional array.

struct container {

    // The maximum size of the container.

    static const int max_size = 10000;

    // The current size of the container.

    int len;

    figure *container[max_size];
};

// Initialization of the container.

void initialization(container &container, int n);

// Clearing the elements of the container.

void clear(container &container);

// Input of the container elements.

void input(container &container, int n, FILE **fin);

// Random input of the container elements.

void randomInput(container &container, int size);

// Output of the container elements to the file.

void output(container &container, FILE *f_out);

// Sorting the elements of container by descending order, according to the square.

void binarySort(container &container, int n);

#endif

#endif
