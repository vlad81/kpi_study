#include"vector.h"

int min_size = 0;
int max_size = 100;
int cur_size = 0;

int pop(){
     if(szie > 0){
          size--;
          vect* buf = beg;
          beg = beg->next;
          return buf->elem;
     }
     return -1;
}

void push(int* buf){
     if(size < 100){
          vect* ptr = (vect*)malloc(sizeof(vect));
          ptr->elem = *buf;
          ptr->next = beg;
          beg = ptr;
          size++;
     }    
}

int is_full(){
     if(size == 100)
          return 0;
     return 1;
}

int is_empty(){
     if(size == 0)
          return 0;
     return 1;
}
