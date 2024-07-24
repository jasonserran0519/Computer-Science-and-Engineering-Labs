/*# Name: Jason Serrano
# Date: 2/16/24  (the day you have lab)
# Title: Lab5 – Synchronization using semaphores, Lock and condition variables 
# Description: Producer and Consumer thorudgh the use of Semaphores
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> 
#include <semaphore.h> 
#include <stdlib.h>

#define N 10 // number of buffers

//Initialize semaphores
sem_t mutex; 
sem_t full;
sem_t empty;

int buffer[N];
int in = 0; 
int out = 0;

//Producer Function
void* producer(void* arg){
    do{
        int number;
        sleep (1);

        //pick random between 1 and 10
        number = rand() % 10;

        sem_wait(&empty);
        sem_wait(&mutex);

        //puts number in buffer for the consumer
        buffer[in] = number; 

        //The mod N in both and Out keeps the program from having race issues where the amount in is greater than out
        in = (in +1) % N;
        printf("Produced Number: %d\n", number);

        sem_post(&mutex);
        sem_post(&full);
    }while (1);
}

void* consumer(void * arg){
    do{
        int number;

        //waits to see if the semaphore is full
        sem_wait(&full); 
        sem_wait(&mutex);

        number = buffer[out];
        out = (out + 1) % N;
        printf("Consumer Number: %d\n", number);

        //after consumer prints out number, it declares that the semaphore is ready to use.
        sem_post(&mutex);
        sem_post(&empty);
        sleep(2);
    }while(1);

        
}

int main() { 
pthread_t t_producer, t_consumer;
int flag = 0;

//initiallize empty, full, and mutex
sem_init(&empty, 0,N);
sem_init(&full, 0, 0);
sem_init(&mutex, 0, 1);



//creates threads for the producer and consumer until the flag goes off
if (flag == 0){


    pthread_create(&t_producer, NULL, producer, NULL);
    pthread_create(&t_consumer, NULL, consumer, NULL);

    pthread_join(t_producer, NULL);
    pthread_join(t_consumer,NULL);
    flag = 1;
}

//destroys semaphores. 
sem_destroy(&empty);
sem_destroy(&full);
sem_destroy(&mutex);

return 0; 
} 