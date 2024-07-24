#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {//to 
    int pageno;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file
    int i; 
    int cache_value =0;
    int totalFaults = 0; // keeps track of the total page faults
    int total_requests = 0;

    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;

    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an in
        bool foundInCache = false;
        total_requests ++;
        for (i=0; i<CACHE_SIZE; i++){
            if (cache[i].pageno == page_num){
                foundInCache = true;
                break; //break out loop because found page_num in cache
            }
        }
        if (foundInCache == false){
            //You may print the page that caused the page fault
            printf("Page %d caused a fault\n", page_num); 
            cache[cache_value].pageno = page_num;
            totalFaults++;
            cache_value = (cache_value +1) % CACHE_SIZE; //Need to keep the value within the cacheSize
        }
      
    }

    double hitrate = (total_requests - totalFaults) / (double)total_requests;
    double miss = 1 -hitrate;
   // printf("%f missrate\n", miss);
    //printf("%d Total Page Faults, %d Total Requests \n ", totalFaults, total_requests);
    //printf("%f Total hitrate", hitrate);
    return 0;



}
