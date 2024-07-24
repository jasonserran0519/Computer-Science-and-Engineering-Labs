/*  # Name: Jason Serrano
    # Date: 2/09/24 (the day you have lab)
    # Title: Lab4 – Pthreads and IPC 
    # Description: This program multiplies two differnet matrix into one matrix using threads */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define N 80
#define M 80
#define L 80

void *go(void *arg);      
// Function used to multiply matrixA and MatrixB

pthread_t threads[N];

// Initialize each matri
double matrixA[N][M];
double matrixB[M][L];
double matrixC[N][L];

int main() {
    static int i;
    
    // Used to initialize the seed using CPU time
    srand(time(NULL));

    // For loops below are used to generate the random numbers foor each matrix 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            matrixA[i][j] = rand() % 10;
            printf(" %.2f ", matrixA[i][j]);
        }
        // prints the matrix
        printf("\n");
  
    }
    printf("\n");

   
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < L; j++) {
            matrixB[i][j] = rand() % 10;
            printf(" %.2f ", matrixB[i][j]);
        }
         // prints the matrix
        printf("\n");
    }

    printf("\n");
    
     // Create threads for each row i
    for(i = 0; i < N; i++)
        pthread_create(&threads[i], NULL, go, (void *)(size_t)i);
    
    // Wait for each thread to finish then closes
    for(i = 0; i < N; i++)
        pthread_join(threads[i], NULL);
    
    // After matrixC has been changed with go() , print each row and column
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < L; j++) {
            printf(" %.2f ", matrixC[i][j]);
        }
        printf("\n");
    }
}

void *go(void *arg) {
    size_t row = (size_t) arg;
    for(int j = 0; j < N; j++)
        for(int k = 0; k < L; k++)
            // Loop through matrixC 
            // multiplies matrixA and matrixB into matrixC
            matrixC[row][j] += matrixA[row][k]*matrixB[k][j];   
}