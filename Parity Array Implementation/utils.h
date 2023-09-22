#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
struct ParityArray{
    int even_idx;
    int odd_idx;
    int * intArr;
    int size;
};
typedef struct ParityArray ParityArray;

void init(ParityArray *pa);
void insert(ParityArray *pa, int element);
void print(ParityArray *pa);
void destruct(ParityArray *pa);
void dump(ParityArray *pa);

#endif