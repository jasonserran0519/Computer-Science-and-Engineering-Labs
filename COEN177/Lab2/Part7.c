/*  # Name: Jason Serrano
    # Date: 1/26/24 (the day you have lab)
    # Title: Lab2 – Programming in C and the use of system calls 
    # Description: This program computes creates a parent and child process where the child process prints out everything in the directory



/*Sample C program for Lab assignment 1*/
#include <stdio.h> /* printf, stderr */
#include <sys/types.h> /* pid_t */
#include <unistd.h> /* fork */
#include <stdlib.h> /* atoi */
#include <errno.h> /* errno */
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
    pid_t pid;
    int i, n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    if (pid){
        // Parent process
        wait(NULL);
        printf("Child Complete \n");
        exit(0);
        
        }
        else{
        // Child process
        execlp("/bin/ls", "ls", NULL);    // prints out everything in the directory
        printf("execlp");
        printf ("exit failed \n");   // will print if exelp fails 
        
        
    }
    return 0;
}
