#include <unistd.h>
#include <stdio.h>

void print(const char * text){
    for(int i=0; i<20; i++){
        printf("hello from %s\n",text);
        usleep(1000000);
    }
}

int main(){
    print("friend chiled");
    return 0;
}