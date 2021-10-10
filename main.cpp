//------------------------------------------------------------------------------
// main.cpp - contains the main function
//------------------------------------------------------------------------------

#include <stdio.h>
#include "container.h"
#include <time.h>

void output(container &container, FILE *file_out, int size);


//------------------------------------------------------------------------------
// The main function.

int main() {
    unsigned int start_time =  clock();
    FILE* file_in = fopen("tests\\tests.txt", "r");
    int size = 10001;
    container cont{};
    FILE *file_out;
    file_out = fopen("tests\\output.txt", "w");
    int command_number;
    printf("1 - input from file\n");
    printf("2 - random input\n");
    printf("Choose the way of data input:\n");
    scanf("%d", &command_number);
    if (command_number == 2) {
        printf("Input the seed for generation\n");
        int seed;
        scanf("%d",&seed);
        srand(seed);
        size = rand() % 10001;
        initialization(cont, size);
        randomInput(cont, size);
        output(cont, file_out, size);
    } else if (command_number == 1) {
        while (!feof(file_in)) {
            fscanf(file_in, "%d", &size);
            if ((size < 0) || (size > 10000)) {
                fprintf(file_out, "incorrect number of figures = ");
                fprintf(file_out, "%d", size);
                printf("Set 0 < number <= 10000\n");
                return 3;
            }
            initialization(cont, size);
            input(cont, size, &file_in);
            output(cont, file_out, size);
            fprintf(file_out, "\n");
        }
    } else {
        printf("Incorrect command!");
    }
    fclose(file_in);
    fclose(file_out);
    unsigned int end_time =  clock();
    unsigned int time=end_time-start_time;
    printf("Time: ");
    printf("%d", time);
    printf(" ms");
    return 0;
}


void output(container &c, FILE *file_out, int size) {
    output(c, file_out);
    binarySort(c, size);
    fprintf(file_out, "\n");
    fprintf(file_out, "Sorted container:\n");
    for (int i = 0; i < size; ++i) {
        switch (c.container[i]->key) {
            case figure::RECTANGLE:
                output(c.container[i]->rect, file_out);
                outputColor(*c.container[i], file_out);
                break;
            case figure::TRIANGLE:
                output(c.container[i]->tr, file_out);
                outputColor(*c.container[i], file_out);
                break;
            case figure::CIRClE:
                output(c.container[i]->circ, file_out);
                outputColor(*c.container[i], file_out);
                break;
        }
    }
    clear(c);
}