#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char child_stack[10000+1];

int child1(void * params){
    char* args[2]={"./fork",NULL};
    execvp(args[0],args);
    
}
int child2(void * params){
    char* args[2]={"./clone",NULL};
    execvp(args[0],args);
   
}
int child3(void * params){
   char* args[2]={"./deamon",NULL};
    execvp(args[0],args);
}

int main (){
    int result1 = clone(child1,child_stack+10000,CLONE_PARENT,0);
    int result2 = clone(child2,child_stack+10000,CLONE_PARENT,0);
    int result3 = clone(child3,child_stack+10000,CLONE_PARENT,0);
    return 0;
}