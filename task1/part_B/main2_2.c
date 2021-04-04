#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char child_stack[10000+1];

void print(const char * text){
    for(int i=0 ; i<1000 ;i++){
        printf("hello from %s\n",text);
        usleep(1000000);
    }
}
int child1(void * params){
    usleep(1000000);
    print("child1");
}
int child2(void * params){
    usleep(1000000);
    print("child2 ");
}
int child3(void * params){
    usleep(1000000);
    print("child3 ");
}

int main(){

    int result1 = clone(child1,child_stack+10000,CLONE_PARENT,0);
    int result2 = clone(child2,child_stack+10000,CLONE_PARENT,0);
    int result3 = clone(child3,child_stack+10000,CLONE_PARENT,0);

    printf("pid of child1 = %d \npid of child2 = %d \npid of child3 = %d \npid of parent = %ld \n--------------------\n",\
            result1, result2, result3, getpid());

    usleep(1000000);
    print("parent");

    return 0;

}