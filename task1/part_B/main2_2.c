#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char child_stack[10000+1];

void print(const char * text){

    for(int i=0 ; i<1000 ;i++){
        printf("hello from %s pid is %ld \n",text,getpid());
        usleep(1000000);

    }
}
int child(void * params){
    print("child_thread");
}

int main(){

    int result = clone(child,child_stack+10000,CLONE_PARENT,0);
    printf("clone result = %d  pid is %ld \n",result,getpid());
    print("parent");
    return 0;

}