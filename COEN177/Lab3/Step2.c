/*  # Name: Jason Serrano
    # Date: 2/01/24 (the day you have lab)
    # Title: Lab3 – Pthreads and IPC 
    # Description: This program computes ... <you should
    # complete an appropriate description here.> */




/*Sample C program for Lab assignment 3*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
// main
int main(int argc,char *argv[]){
    int fds[2];
    char buff[60];
    int count;
    int i;
    pipe(fds);
    
    if (fork()==0){
        printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
        close(fds[0]);
        dup2(fds[1],1);
    
        execlp("ls", "ls", 0);
        //close(fds[1]);
        exit(0);
    }

    else if(fork()==0){
        printf("\nReader on the downstream end of the pipe \n");
        close(fds[1]);
        
        dup2(fds[0], 0);
       // close(fds[0]);
        while((count=read(fds[0],buff,60))>0){
           for(i=0;i<count;i++){
               write(1,buff+i,1);                       // and write to screen from buffer
               write(1," ",1);
           }
           printf("\n");
       }
       exit(0); 
        
        exit(0);
    }
    else{
        close(fds[0]);
        close(fds[1]);
        wait(0);
        wait(0);
    }
    return 0;
}