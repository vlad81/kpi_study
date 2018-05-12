#pragma once
#include<stdlib.h>

typedef struct VECT {
     int elem;
     struct VECT* next;    
} vect;


int pop();

void push(int);

int is_full();

int is_empty();

int get_size();

vect* get_beg();
