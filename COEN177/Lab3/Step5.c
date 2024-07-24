
/*  # Name: Jason Serrano
    # Date: 2/01/24 (the day you have lab)
    # Title: Lab3 – Pthreads and IPC 
    # Description: This program computes the consumer and producer problem 
    */ 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

#define SIZE 50
// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[SIZE];
   pipe(fds);
   
   if (fork()==0){
    //Child Process, handles the reading
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       close(fds[1]);
       
       int NumRead;
       while (NumRead = read(fds[0], buff, SIZE >0)){
        printf ("Consumer: %s\n", buff);
       }
       close(fds[0]);
       exit(0);
   }
   else{    
    //Parent Process, Handles the writing 
      int i; 

      close(fds[0]);
      char *strg[] = {"Operating", "Systems", "Lab", "3"};
      for (i =0; strg[i] != NULL; i++){
        write(fds[1], strg[i], strlen(strg[i]));
        sleep(1);
      }
      close(fds[1]);
      wait(NULL);
   }
return 0;
}