#include<stdio.h>
#include <dlfcn.h>


int main(){
    void(*hello_ariel)();
    int b=1;
     void *handle =dlopen("./libHello.so",RTLD_LAZY);
 
    if(!handle){
        b=0;
        
    }else{
        hello_ariel=(void*)dlsym(handle,"hello_ariel");
        if(!hello_ariel)
            b=0;    
    }

    if(b){
        hello_ariel();
        dlclose(handle); 
    }else
        printf("lib didnt load");

       
    return 0;

    
    
}