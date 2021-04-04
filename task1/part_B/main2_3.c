#include <sys/types.h> 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(){

    // create child that will be the deamon 
    pid_t pid = fork();

    if(pid==0){

        // move to root dir 
        chdir("/");

        // move the child to another session 
        setsid();

        printf("starting deamon\n");

        // close the output chanels
        close(stdout);
        close(stdin);
        close(stderr);

        // open log
        openlog("myDeamon",LOG_PID,LOG_DAEMON);
        // generate a log message
        syslog(LOG_NOTICE,"deamon started");
        usleep(3000000);
        syslog(LOG_NOTICE,"working...");
        usleep(3000000);
        syslog(LOG_NOTICE,"deamon finished");
        closelog();
    }else{
        printf("deamon pid %d\n",pid);
        usleep(3000000);
    }

    return 0;
}
