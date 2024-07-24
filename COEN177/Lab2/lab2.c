/*  # Name: Jason Serrano
    # Date: 1/19/24 (the day you have lab)
    # Title: Lab2 – Programming in C and the use of system calls 
    # Description: This program computes ... <you should
    # complete an appropriate description here.> */



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
}
