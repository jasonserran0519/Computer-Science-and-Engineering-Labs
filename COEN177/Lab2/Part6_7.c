/*  # Name: Jason Serrano
    # Date: 1/26/24 (the day you have lab)
    # Title: Lab2 – Programming in C and the use of system calls 
    # Description: This program creates two threads that each have an output of 100 items



/*Sample C program for Lab assignment 1*/
#include <stdio.h> /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h> /* fork */
#include <stdlib.h> /* atoi */
#include <errno.h> /* errno */
#include <pthread.h> // thread library 
/* main function with command-line arguments to pass */


void *threads(void *n){
    //Unique function for the child thread
    int i;
    int x = *((int *)n);
    for (i=0;i<100;i++) {
            printf("child thread %d \n",i);
            usleep(x);
    }
    return;
}


int main(int argc, char *argv[]) {
    
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n creating thread...\n");
    pthread_t thread;
   
    if (pthread_create(&thread, NULL, *threads, (void *)&n) != 0) {
        fprintf(stderr, "can't thread, error %d\n", errno);
    }

   // pthread_create(&thread, NULL, *threads, &n);

    //pthread_join(thread, NULL);

    for (i=0;i<100;i++) {
        printf("\t \t \t Parent thread %d \n",i);
        usleep(n);
        //pthread_join(thread, NULL);
    }

    pthread_join(thread, NULL);
    return 0;
}




  
  
  
  /*  if (thread == 0){
        // Parent process
            for (i=0;i<100;i++) {
            printf("\t \t \t Parent Process %d \n",i);
            usleep(n);
            }
        }
        else{
        // Child process
            for (i=0;i<100;i++) {
            printf("Child process %d\n",i);
            usleep(n);
            }   
    } 
return 0;
} */
