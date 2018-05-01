#ifndef VECTOR_H
#define VECTOR_H

struct {
     int elem;
     struct * next;     
}vect;

vect* beg = NULL;

int* pop();

void push(int*);

int is_full();

int is_empty();

#endif
