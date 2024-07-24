/*  # Name: Jason Serrano
    # Date: 1/19/24 (the day you have lab)
    # Title: Lab2 – Programming in C and the use of system calls 
    # Description: This program creates 7 total processes



/*Sample C program for Lab assignment 1*/
#include <stdio.h> /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h> /* fork */
#include <stdlib.h> /* atoi */
#include <errno.h> /* errno */
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t kid1, kid2;
    pid_t gkid1, gkid2, gkid3, gkid4;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");

    (kid1 = fork()) && (kid2 = fork());  // creates two children 

    if (kid1 == -1 || kid2 == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    
    if (kid1 == 0){
        //child process 1
        printf("child process1 has printed,  PID: %d Parent ID: %d\n" , getpid(), getppid());
        
        (gkid1 = fork()) && (gkid2 = fork());
        // creates grandchild process for child process 1 
        if (gkid1 == -1 || gkid2 == -1) {
         fprintf(stderr, "can't fork gkids, error %d\n", errno);
        }

        if(gkid1 ==0){
            printf("\t Grandchild1 is good, PID: %d Parent ID: %d\n" , getpid(), getppid());
            exit(EXIT_SUCCESS);

            usleep(n);
        }
        if (gkid2 ==0){
            printf(" \t Grandchild 2 is good, PID: %d Parent ID: %d\n" , getpid(), getppid());
            exit(EXIT_SUCCESS);

            usleep(n);
        }
        wait(NULL);
        exit(EXIT_SUCCESS);

        usleep(n);

    }

     
    else if (kid2 == 0){
        //child process 2 
        printf("Child process2 has printed, PID: %d Parent ID: %d\n" , getpid(), getppid());
        
        (gkid3 = fork()) && (gkid4 = fork());
        // creates grandchild process for child process 1 
        
        if (gkid3 == -1 || gkid4 == -1) {
         fprintf(stderr, "can't fork gkids, error %d\n", errno);
        }

        if(gkid3 ==0){
            printf("\t Grandchild3 is good PID: %d Parent ID: %d\n" , getpid(), getppid());
            exit(EXIT_SUCCESS);

            usleep(n);
        }
        if (gkid4 ==0){
            printf("\t Grandchild 4 is good PID: %d Parent ID: %d\n" , getpid(), getppid());
            exit(EXIT_SUCCESS);

            usleep(n);
        }
        wait(NULL);
        exit(EXIT_SUCCESS);
        usleep(n);
    }
    else{
        //Parent process
        wait(NULL);
        printf(" \t \t \t Parent process is good PID: %d\n" , getpid());
        
        usleep(n);
    }
    return 0;
}
    
