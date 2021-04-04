#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char child_stack[10000+1];

void print(const char * text){

    for(int i=0 ; i<1000 ;i++){
        printf("hello from %s with pid - %ld \n",text, getpid());
        usleep(1000000);
    }
}
int child1(void * params){
    print("child_thread 1 ");
}
int child2(void * params){
    print("child_thread 2 ");
}

int main(){

    int result1 = clone(child1,child_stack+10000,CLONE_PARENT,0);
    int result2 = clone(child2,child_stack+10000,CLONE_PARENT,0);
    printf("clone result1 = %d \n",result1);
    printf("clone result2 = %d \n",result2);
    print("parent");

    return 0;

}