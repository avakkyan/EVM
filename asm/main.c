#include "sort.h"

#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <stdio.h>

void test();

void taskSort() {
    int data[1000];
    int size = 0;
    int i;
    FILE* F = fopen("in1.txt", "r");
    assert(F != NULL);
    while (fscanf(F, "%d", &data[size]) == 1) {
        ++size;
    }
    fclose(F);

    sort(data, size);

    F = fopen("out1.txt", "w");
    assert(F != NULL);
    for (i = 0; i < size; ++i) {
        fprintf(F, "%d ", data[i]);
    }
    fclose(F);
}

void taskMax10()
{
    int data[1000];
    int maxVals[10];
    int size = 0;
    int i;
    FILE* F = fopen("in2.txt", "r");
    assert(F != NULL);
    while (fscanf(F, "%d", &data[size]) == 1) {
        ++size;
    }
    fclose(F);

    findMax10(data, size, maxVals);

    F = fopen("out2.txt", "w");
    assert(F != NULL);
    for (i = 0; i < 10; ++i) {
        fprintf(F, "%d ", maxVals[i]);
    }
    fclose(F);
}

int main() {
    test();
    taskSort();
    taskMax10();
    return 0;
}