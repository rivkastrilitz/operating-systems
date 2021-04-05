#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char child_stack[10000+1];

int child1(void * params){
    char* args[2]={"./main2_1",NULL};
    execvp(args[0],args);
    
}
int child2(void * params){
    char* args[2]={"./main2_2",NULL};
    execvp(args[0],args);
   
}
int child3(void * params){
   char* args[2]={"./main2_3",NULL};
    execvp(args[0],args);
}

int main (){
    printf("main p %d\n",getpid());
    printf("main ppid---------------- %d",getppid());
    int result1 = clone(child1,child_stack+10000,0,0);
    int result2 = clone(child2,child_stack+10000,0,0);
    int result3 = clone(child3,child_stack+10000,0,0);
    usleep(30000000);
    return 0;
}