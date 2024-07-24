/* # Name: Jason Serrano
# Date: 2/16/24  (the day you have lab)
# Title: Lab5 – Synchronization using semaphores, Lock and condition variables 
# Description: This file documents all of the observations for the Lab5 experiments
*/ 

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

#define NTHREADS 10
pthread_t threads[NTHREADS];
pthread_mutex_t mutex;

void* go(void* arg) {
  pthread_mutex_lock(&mutex); //entry section
  printf("Thread %d Entered Critical Section..\n", (int)(size_t)arg); //critical section
  sleep(1);
  pthread_mutex_unlock(&mutex); //exit section
  return (NULL);
}

int main() {
  pthread_mutex_init(&mutex, NULL); // Initialize the mutex
  int i;
  for (i = 0; i < NTHREADS; i++)  
    pthread_create(&threads[i], NULL, go, (void *)i);
  for (i = 0; i < NTHREADS; i++) {
    pthread_join(threads[i],NULL);
    printf("\t\t\tThread %d returned \n", i);
  }
  printf("Main thread done.\n");
  pthread_mutex_destroy(&mutex); // Destroy the mutex
  return 0;
}
	
