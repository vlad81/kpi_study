#include"thread.h"
#include"vector.h"
#include"at_struct.h"



pthread_mutex_t 	mut = PTHREAD_MUTEX_INITIALIZER;

pthread_mutex_t 	mut_s = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t  	cond_not_empty = PTHREAD_COND_INITIALIZER;

pthread_cond_t  	cond_not_full  = PTHREAD_COND_INITIALIZER;

pthread_cond_t  	sig_21  = PTHREAD_COND_INITIALIZER;


//full sync with p4
void* thread_1_func(int* arg){

     at_1 = 1;
     at_1 = __sync_fetch_and_sub (&at_1,1);
     fprintf(f,"Modification of at_1 : %d\n",at_1);
     
     at_4 = 4;
     fprintf(f,"Modification of at_4 : %d\n",__sync_fetch_and_sub (&at_4,1));
     
     while(1){
     ////////////////full sync with p4(semaphore)////////////
          fprintf(f,"thread_1_func opens semaphore sem2 for the thread_4_func\n");

          sem_post(&sem2);
          fprintf(f,"Semaphore sem2 is opened!\n");

          fprintf(f,"thread_1_func waits for the opening of the semaphore sem1\n");

          sem_wait(&sem1);

          fprintf(f,"thread_1_func works after semaphore sem1\n");
          ////////////////////////////////////////////////////////

           pthread_mutex_lock(&mut_s);
          pthread_cond_broadcast (&sig_21);
          pthread_mutex_unlock(&mut_s);

          fprintf(f,"thread_1_func send sig_21\n");
          
          at_2 = 2;
          fprintf(f,"Before modification at_2 = %d\n",at_2);
          fprintf(f,"Modification of at_2 : %d\n",__sync_sub_and_fetch (&at_2, 1));
          fprintf(f,"After modification at_2 = %d\n",at_2);

           at_5 = 5;
           fprintf(f,"Before modification at_5 = %li\n",at_5);
           at_5 = __sync_sub_and_fetch (&at_5, 3);
           fprintf(f,"After modification at_5 = %li\n",at_5);
                         
     }
     
     return NULL;
}

//producer for cr1
void* thread_2_func(int* arg){

     int num = *(int*)arg;
      
     while (1) {

          fprintf(f,"thread_2_func wait sig_21\n");
 pthread_mutex_lock(&mut_s);
          pthread_cond_wait (&sig_21,&mut_s);
          pthread_mutex_unlock(&mut_s);

          fprintf(f,"thread_2_func woks after getting sig_21\n");
           __sync_fetch_and_and (&at_1, 2);
          fprintf(f,"Modification of at_1 : %d\n",__sync_fetch_and_and (&at_1, 2));
          
          
          pthread_mutex_lock (&mut);



          while (is_full()) {
               pthread_cond_wait (&cond_not_full, &mut);
          }

          push(at_1);



          fprintf(f,"Producer thread%d: element %d CREATED; current queue length = %d;\n",

                 num,get_beg()->elem,get_size());

          pthread_mutex_unlock (&mut);

          pthread_cond_broadcast (&cond_not_empty);

     }


     fprintf(f,"Producer thread%d  stopped !!!\n",num);


     return NULL;

}

//consumer for cr1
void* thread_3_func(int* arg){

     int num = *(int*)arg;

     int curr_elem;
    
     while (1) {
          
          pthread_mutex_lock (&mut);

          while (is_empty()) {
               pthread_cond_wait (&cond_not_empty, &mut);
          }


          curr_elem = pop();

          fprintf(f,"Consumer thread%d: element %d TAKEN; current queue length = %d;\n",
                 num,curr_elem,get_size());


          pthread_mutex_unlock (&mut);

          pthread_cond_broadcast (&cond_not_full);

     }

     fprintf(f,"Consumer thread%d  stopped !!!\n",num);

     return NULL;
}

//full sync with p1
void* thread_4_func(int* arg){

     at_7 = 7;
     __sync_and_and_fetch (&at_7, 7);
     fprintf(f,"Modification of at_7 : %li\n",__sync_and_and_fetch (&at_7, 7));
     while(1){
     ///////////////////////full sync with p1(semaphore)////
     fprintf(f,"\nthread_4_func opens semaphore sem1 for the thread_1_func\n");

     sem_post(&sem1);

     fprintf(f,"Semaphore sem1 is opened!\n");

     fprintf(f,"thread_4_func waits for the opening of the semaphore sem2\n");

     sem_wait(&sem2);

     fprintf(f,"\nthread_4_func works after semaphore sem2\n");
     /////////////////////////////////////////////////////////

      pthread_mutex_lock(&mut_s);
     pthread_cond_broadcast (&sig_21);
     pthread_mutex_unlock(&mut_s);
     
     fprintf(f,"thread_4_func send sig_21\n");

     at_3 = 3;
     fprintf(f,"Before modification at_3 = %u\n",at_3);
     __sync_fetch_and_xor (&at_3, 2);
     fprintf(f,"Modification of at_3 : %u\n",__sync_fetch_and_xor (&at_3, 2));
     fprintf(f,"After modification at_3 = %u\n",at_3);

     at_8 = 8;
     fprintf(f,"Before modification at_8 = %li\n",at_8);
     __sync_sub_and_fetch (&at_8, 3);
     fprintf(f,"Modification of at_8 : %li\n",__sync_sub_and_fetch (&at_8, 3));
      fprintf(f,"After modification at_8 = %li\n",at_8);
     }
     return NULL;
     
}

//producer for cr1
void* thread_5_func(int* arg){
     int num = *(int*)arg;
     //pthread_mutex_lock(&mut_s);
     while (1) {

          fprintf(f,"thread_5_func wait sig_21\n");
     
          pthread_mutex_lock(&mut_s);
           pthread_cond_wait (&sig_21,&mut_s);
           pthread_mutex_unlock(&mut_s);

          fprintf(f,"thread_5_func woks after getting sig_21\n");

          __sync_fetch_and_and (&at_6, 2);
          fprintf(f,"T5 : mication of at_6 : %li\n",__sync_fetch_and_and (&at_6, 2));
        
          pthread_mutex_lock (&mut);

          while (is_full()) {
               pthread_cond_wait (&cond_not_full, &mut);
          }

          push(at_2);

          fprintf(f,"Producer thread%d: element %d CREATED; current queue length = %d;\n",

                 num,get_beg()->elem,get_size());

          pthread_mutex_unlock (&mut);

          pthread_cond_broadcast (&cond_not_empty);

     }

     
     fprintf(f,"Producer thread%d  stopped !!!\n",num);


     return NULL;
}

//consumer for cr1
void* thread_6_func(int* arg){
     
     int num = *(int*)arg;

     int curr_elem;

     while (1) {
          
          pthread_mutex_lock (&mut);

          while (is_empty()) {
               pthread_cond_wait (&cond_not_empty, &mut);
          }


          curr_elem = pop();

          fprintf(f,"Consumer thread%d: element %d TAKEN; current queue length = %d;\n",
                 num,curr_elem,get_size());


          pthread_mutex_unlock (&mut);

          pthread_cond_broadcast (&cond_not_full);

     }

     fprintf(f,"Consumer thread%d  stopped !!!\n",num);

     return NULL;
}
