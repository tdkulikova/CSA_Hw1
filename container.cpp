//
// Created by Таня Куликова on 26.09.2021.
//

#include "container.h"


//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Container initialization.

void initialization(container &cont, int size) {
    cont.len = 0;
    for (int i = 0; i < size; ++i) {
        cont.container[i] = new figure;
    }
}

//------------------------------------------------------------------------------
// Clearing the containers from the elements.

void clear(container &cont) {
    for (int i = 0; i < cont.len; ++i) {
        delete cont.container[i];
    }
    cont.len = 0;
}

//------------------------------------------------------------------------------
// Inputting figures from the file to the container.

void input(container &cont, int size, FILE **file_in) {
    while (cont.len < size) {
        cont.container[cont.len] = input(*file_in);
        if (cont.container[cont.len] != nullptr) {
            ++cont.len;
        }
    }
}

//------------------------------------------------------------------------------
// Input of the random figures to the container.

void randomInput(container &cont, int size) {
    while (cont.len < size) {
        if ((cont.container[cont.len] = randomInput()) != nullptr) {
            ++cont.len;
        }
    }
}

//------------------------------------------------------------------------------
// Output of the container figures.

void output(container &cont, FILE *file_out) {
    fprintf(file_out, "Container contains ");
    fprintf(file_out, "%d", cont.len);
    fprintf(file_out, " elements.\n");
    for (int i = 0; i < cont.len; ++i) {
        output(*cont.container[i], file_out);
    }
}

//--------------------------------------------------------------------------------------------
// Function for searching the position, where to insert the element when sorting the container.

int binarySearch(container &cont, figure *fig, int left, int right) {
    if (right <= left) {
        return (square(*fig) < square(*cont.container[left]) ? (left + 1) : left);
    }
    int middle = (left + right) / 2;
    if (square(*fig) == square(*cont.container[middle])) {
        return middle + 1;
    }
    if (square(*fig) < square(*cont.container[middle])) {
        return binarySearch(cont, fig, middle + 1, right);
    }
    return binarySearch(cont, fig, left, middle - 1);
}

// -------------------------------------------------------------------------------------------
// Function for sorting the container by descending order.

void binarySort(container &cont, int size) {
    int i, position, right_bound;
    figure *selected_figure;
    for (i = 1; i < size; ++i) {
        right_bound = i - 1;
        selected_figure = cont.container[i];

        // Searching for the position where selected figure should be inserted.

        position = binarySearch(cont, selected_figure, 0, right_bound);

        // Move all elements after location to create space for inserting the element.

        while (right_bound >= position) {
            cont.container[right_bound + 1] = cont.container[right_bound];
            --right_bound;
        }
        cont.container[right_bound + 1] = selected_figure;
    }
}
