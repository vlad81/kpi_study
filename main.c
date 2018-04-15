#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include "thread.h"


int main () {

     pthread_t thread_id_1;
     pthread_t thread_id_2;
     pthread_t thread_id_3;
     pthread_t thread_id_4;
     pthread_t thread_id_5;
     pthread_t thread_id_6;
     
     pthread_create(&thread_id_1,NULL,&thread_1_func,NULL);
     pthread_create(&thread_id_2,NULL,&thread_2_func,NULL);
     pthread_create(&thread_id_3,NULL,&thread_3_func,NULL);
     pthread_create(&thread_id_4,NULL,&thread_4_func,NULL);
     pthread_create(&thread_id_5,NULL,&thread_5_func,NULL);
     pthread_create(&thread_id_6,NULL,&thread_6_func,NULL);

     return 0;
}
