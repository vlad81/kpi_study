#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
//#include "vector.h"
//#include "at_struct.h"


pthread_t thread_id_1;
pthread_t thread_id_2;
pthread_t thread_id_3;
pthread_t thread_id_4;
pthread_t thread_id_5;
pthread_t thread_id_6;


sem_t sem1,sem2;

FILE *f;

void* thread_1_func();
void* thread_2_func();
void* thread_3_func();
void* thread_4_func();
void* thread_5_func();
void* thread_6_func();
