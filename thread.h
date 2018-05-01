#ifndef THREAD_H
#define THREAD_H
#include <semaphore.h>
//#include "vector.h"
//#include "at_struct.h"

sem_t sem1,sem2;

void* thread_1_func();
void* thread_2_func();
void* thread_3_func();
void* thread_4_func();
void* thread_5_func();
void* thread_6_func();

#endif
