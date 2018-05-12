#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include "thread.h"


int main () {

     f = fopen("test.txt","wt");

     sem_init(&sem1,0,1);
     sem_init(&sem2,0,1);

       int thread1_number=1;
       int thread2_number=2;
       int thread3_number=3;xf
       int thread4_number=4;
       int thread5_number=5;
       int thread6_number=6;
     
     pthread_create(&thread_id_1,NULL,&thread_1_func,(void*)&thread1_number);
     pthread_create(&thread_id_2,NULL,&thread_2_func,(void*)&thread2_number);
     pthread_create(&thread_id_3,NULL,&thread_3_func,(void*)&thread3_number);
     pthread_create(&thread_id_4,NULL,&thread_4_func,(void*)&thread4_number);
     pthread_create(&thread_id_5,NULL,&thread_5_func,(void*)&thread5_number);
     pthread_create(&thread_id_6,NULL,&thread_6_func,(void*)&thread6_number);

     pthread_join(thread_id_1,NULL);
     pthread_join(thread_id_2,NULL);
     pthread_join(thread_id_3,NULL);
     pthread_join(thread_id_4,NULL);
     pthread_join(thread_id_5,NULL);
     pthread_join(thread_id_6,NULL);

        printf("All threads stopped !!!\n");
     
     return 0;
}
