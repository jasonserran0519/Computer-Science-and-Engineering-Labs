
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {     
        int pageno;
        int age;
} ref_page;

int main(int argc, char *argv[]) {
    int CACHE_SIZE=atoi(argv[1]);
    ref_page cache[CACHE_SIZE]; 
    char pageCache[100]; 
    int cache_I=0;
    int totalFaults=0; 
    int total_requests=0;
    int i, j, k, page_num, oldest;
    
    for(i=0; i<CACHE_SIZE; i++) {
        cache[i].pageno = -1;                                           // Initialize array with -1
        cache[i].age = 0;                                               // and ages of 0
    }

    while(fgets(pageCache, 100, stdin)) {
        page_num = atoi(pageCache);
        total_requests++;
        oldest = cache[i].age;                                          // Set temporary oldest
        for(i = 0; i < CACHE_SIZE; i++) {                                   // Loop through array
            if(cache[i].pageno == page_num) {                           // If we find in array already
                for(j = 0; j < CACHE_SIZE; j++) {                           
                    if(cache[j].age < cache[i].age)                     // Increment ages of all younger arrays
                        cache[j].age++;
                }
                cache[i].age = 0;                                       // Reset age of array to 0 once hit
                break;
            }

            else if(i == CACHE_SIZE-1) {                                    // If our array is full
                printf("Page %d caused a fault\n", page_num);           
                totalFaults++;  
                for(j = 0; j < CACHE_SIZE; j++) {                           // Increment age of all indices
                    cache[j].age++;
                }
                
                for(k = 0; k < CACHE_SIZE ; k++) {                          // Loop through array
                    if(oldest < cache[k].age){                          // If we have older index
                        oldest = cache[k].age;                          // set new oldest
                        cache_I = k;                                 // set index at k
                    }
                }
                cache[cache_I].pageno = page_num;
                cache[cache_I].age = 0;
            }
        }
    }
    double hitrate = (total_requests - totalFaults) / (double)total_requests;
    double miss = 1 -hitrate;
    //printf("%f missrate\n", miss);
    //printf("%d Total Page Faults with %d Total Page Requests\n", totalFaults, total_requests);
    //printf("LRU Hit rate = %f\n", hitrate);
    return 0;
}