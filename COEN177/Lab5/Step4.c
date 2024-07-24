
//# Name: Jason Serrano
//# Date: 2/17/24
//# Title: Lab5 - Synchronization using semaphores, lock, and condition variables
//# Description:  Producer and Consumer with conditon variables


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10 // Size of the buffer


int buffer[SIZE];
int count = 0; // number of items in the buffer


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c_full = PTHREAD_COND_INITIALIZER;
pthread_cond_t c_empty = PTHREAD_COND_INITIALIZER;


void* producer(void* arg) {
    while (1) {
        
        int number = rand() % 10; // producing a random item
        sleep(1); 

        pthread_mutex_lock(&mutex);

        // wait until buffer isnt full
        while (count == SIZE) {
            pthread_cond_wait(&c_empty, &mutex);
        }

        //add the item to buffer
        buffer[count] = number;
        count++;
        printf("Produced: %d\n", number);

        // signal to consumer that the buffer is not empty
        pthread_cond_signal(&c_full);

        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        // wait until buffer isnt empty
        while (count == 0) {
            pthread_cond_wait(&c_full, &mutex);
        }

        //remove an item from the buffer
        int number = buffer[count-1];
        count--;
        printf("Consumed: %d\n", number);
        // signal to the producer that the buffer is not full
        pthread_cond_signal(&c_empty);
        pthread_mutex_unlock(&mutex);
        sleep(1); 
    }
    return NULL;
}

int main() {
    pthread_t t_producer, t_consumer;

    //create producer and consumer threads
    pthread_create(&t_producer, NULL, producer, NULL);
    pthread_create(&t_consumer, NULL, consumer, NULL);

    //wait for the threads to finish
    pthread_join(t_producer, NULL);
    pthread_join(t_consumer, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&c_full);
    pthread_cond_destroy(&c_empty);

    return 0;
}