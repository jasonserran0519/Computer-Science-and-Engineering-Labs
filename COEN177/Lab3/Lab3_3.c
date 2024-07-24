/**************************
*       COEN177: Threads  *
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10
pthread_t threads[NTHREADS];

int main() {
    int i;
    int *values[NTHREADS];
    for (i = 0; i < NTHREADS; i++){ 
        values[i] = malloc(sizeof(int));
        *values[i] = i;
        pthread_create(&threads[i], NULL, go, values[i]);
    }
    for (i = 0; i < NTHREADS; i++) {
	    printf("Thread %d returned\n", i);
        pthread_join(threads[i],NULL);
        free(values[i]);
    }
    printf("Main thread done.\n");
    printf("%d",i);
    return 0;
}
void *go(void *arg) {
 printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), *(int *)arg);
 return 0;
}


