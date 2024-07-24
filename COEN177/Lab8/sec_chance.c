#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {//to 
    int pageno;
    int second_chance;
} ref_page;


int main(int argc, char *argv[]){
	int CACHE_SIZE = atoi(argv[1]); // Size of Cache passed by user
    ref_page cache[CACHE_SIZE]; // Cache that stores pages
    char pageCache[100]; // Cache that holds the input from test file
    int i; 
    int cache_value =0;
    int totalFaults = 0; // keeps track of the total page faults
    int total_requests = 0;
    bool flag;

    
    for (i = 0; i < CACHE_SIZE; i++){//initialise cache array  
         cache[i].pageno = -1;
         cache[i].second_chance = 0; 
    }

    while (fgets(pageCache, 100, stdin)){
    	int page_num = atoi(pageCache); // Stores number read from file as an in
        flag = false;
        total_requests++;
        for(i = 0; i < CACHE_SIZE; i++) {                           // Loop through array
            if(cache[i].pageno == page_num) {                   // If we find the number in array
                cache[i].second_chance = 1;                     // Set that second_chance to 1
                flag = true;                                      // And we found the number
                break;
            }
            if(i == CACHE_SIZE-1)                                   // If we didn't find and array full
                flag = false;                                      // Set found bit to 1
        }
        if(flag == false) {                                             // If we didn't find
           // printf("Page %d caused a fault\n", page_num);
            while(cache[cache_value].second_chance !=0){
                cache[cache_value].second_chance = 0;
                cache_value = (cache_value +1) % CACHE_SIZE;
            }
            printf("%d\n", page_num);

            cache[cache_value].pageno = page_num;
            //cache[cache_value].second_chance = 1; 
            cache_value = (cache_value +1) % CACHE_SIZE;
            totalFaults ++;
        }
    }
    double hitrate = (total_requests - totalFaults) / (double)total_requests;
    double miss = 1 -hitrate;
   // printf("%f missrate\n", miss);
    //printf("%d Total Page Faults, %d Total Requests \n", totalFaults);
    // printf("%d Total hitrate", hitrate);
    return 0;



}
