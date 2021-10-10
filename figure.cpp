//
// Created by Таня Куликова on 26.09.2021.
//

#include "figure.h"
//------------------------------------------------------------------------------
// figure.cpp - contains functions for working with the base figure.
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Inputting the base figure parameters.

figure *input(FILE *file_in) {
    figure *fig;
    int figure_key = 0;
    fscanf(file_in, "%d", &figure_key);
    switch (figure_key) {
        case 1:
            fig = new figure;
            fig->key = figure::RECTANGLE;
            inputFromFile(fig->rect, file_in);
            int color;
            fscanf(file_in, "%d", &color);
            inputColor(fig, color);
            return fig;
        case 2:
            fig = new figure;
            fig->key = figure::TRIANGLE;
            inputFromFile(fig->tr, file_in);
            fscanf(file_in, "%d", &color);
            inputColor(fig, color);
            return fig;
        case 3:
            fig = new figure;
            fig->key = figure::CIRClE;
            inputFromFile(fig->circ, file_in);
            fscanf(file_in, "%d", &color);
            inputColor(fig, color);
            return fig;
        default:
            printf("Something wrong in the file. Incorrect figure.");
            exit(0);
    }
}

// --------------------------------------------------------------------------
// Random input of the base figure.

void inputColor(figure *fig, int color) {
    if (color == 1)
        fig->color = figure::RED;
    else if (color == 2)
        fig->color = figure::ORANGE;
    else if (color == 3)
        fig->color = figure::YELLOW;
    else if (color == 4)
        fig->color = figure::GREEN;
    else if (color == 5)
        fig->color = figure::CYAN;
    else if (color == 6)
        fig->color = figure::BLUE;
    else if (color == 7)
        fig->color = figure::PURPLE;
}

//------------------------------------------------------------------------
// Forming a random figure.

figure *randomInput() {
    figure *fig;
    int figure_key = rand() % 3 + 1;
    int color = rand() % 6 + 1;
    switch (figure_key) {
        case 1:
            fig = new figure;
            fig->key = figure::RECTANGLE;
            randomInput(fig->rect);
            inputColor(fig, color);
            return fig;
        case 2:
            fig = new figure;
            fig->key = figure::TRIANGLE;
            randomInput(fig->tr);
            inputColor(fig, color);
            return fig;
        case 3:
            fig = new figure;
            fig->key = figure::CIRClE;
            randomInput(fig->circ);
            inputColor(fig, color);
            return fig;
        default:
            return nullptr;
    }
}

//------------------------------------------------------------------------------
// Outputting of the base figure parameters.

void output(figure &fig, FILE *file_out) {
    switch (fig.key) {
        case figure::RECTANGLE:
            output(fig.rect, file_out);
            outputColor(fig, file_out);
            break;
        case figure::TRIANGLE:
            output(fig.tr, file_out);
            outputColor(fig, file_out);
            break;
        case figure::CIRClE:
            output(fig.circ, file_out);
            outputColor(fig, file_out);
            break;
        default:
            printf("Incorrect figure!");
    }
}

// -------------------------------------------------------------------------------
// Outputting the figure color.

void outputColor(figure &fig, FILE *file_out) {
    if (fig.color == figure::BLUE)
        fprintf(file_out, " Color = BLUE");
    if (fig.color == figure::CYAN)
        fprintf(file_out, " Color = CYAN");
    if (fig.color == figure::GREEN)
        fprintf(file_out, " Color = GREEN");
    if (fig.color == figure::PURPLE)
        fprintf(file_out, " Color = PURPLE");
    if (fig.color == figure::YELLOW)
        fprintf(file_out, " Color = YELLOW");
    if (fig.color == figure::ORANGE)
        fprintf(file_out, " Color = ORANGE");
    if (fig.color == figure::RED)
        fprintf(file_out, " Color = RED");
    fprintf(file_out, "\n");
}

//------------------------------------------------------------------------------
// Counting the figure square.

double square(figure &fig) {
    switch (fig.key) {
        case figure::RECTANGLE:
            return square(fig.rect);
        case figure::TRIANGLE:
            return square(fig.tr);
        case figure::CIRClE:
            return square(fig.circ);
        default:
            return 0.0;
    }
}
