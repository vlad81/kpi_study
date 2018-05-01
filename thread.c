#include"thread.h"
#include <stdio.h>

void* thread_1_func(){

     int i = 0;
     //sem_wait(&sem1);
     //sem_wait(&sem2);
     while (i < 10) {
          // sem_post(&sem1);
          printf("1");
          i++;
     }

     // return NULL;
}

void* thread_2_func(){
/*
     int i = 0;
     sem_wait(&sem2);
     sem_wait(&sem1);
     while (i < 10) {
          sem_post(&sem2);
          printf("1");
          i++;
          }*/
          
     // return NULL;
}

void* thread_3_func(){

}

void* thread_4_func(){

}

void* thread_5_func(){

}

void* thread_6_func(){

}
