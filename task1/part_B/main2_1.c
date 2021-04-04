#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 

void  print(const char* text){
  
    for(int i=0;i<20;i++){
        printf("hello from % s\n",text);
        usleep(1000000);
    }

}
int main(){

pid_t pid = fork();

// if creating child succeeded ceate another child
if(pid==0){
    pid_t pid = fork();

    if(pid == 0){
        char* args[2]={"./friend",NULL};
        execvp(args[0],args);
    }else{
        print("child");
    }
}else{
    print("parent");
}

return 0;

}