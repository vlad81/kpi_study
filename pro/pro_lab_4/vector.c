#include"vector.h"

vect* stack = NULL;

int minSize = 0;
int maxSize = 100;
int size = 0;

vect* get_beg() {
     return stack;
}

int pop(){
     if(size > minSize){
          size--;
          vect* buf = stack;
          stack = stack->next;
          int a = buf->elem;
          return a;
     }

     return -1;
}

void push(int el){
     if(size < maxSize){
          if(stack != NULL){
               vect* ptr = (vect*)malloc(sizeof(vect));
               ptr->elem = el;
               ptr->next = stack;
               stack = ptr;
               size++;
          }
          else{
               stack=(vect*)malloc(sizeof(vect));
               stack->elem = el;
               stack->next = NULL;
               size++;
          }
     }    
}

int is_full(){
     if(size == 100)
          return 1;
     return 0;
}

int is_empty(){
     if(size == 0)
          return 1;
     return 0;
}

int get_size(){
     return size;
}
