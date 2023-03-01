#include "tasks.h"

//monitor_t* monitors, int n
int menu (monitor_t** monitors, int* n) {
    void (*tasks[])(monitor_t**, int*) = {addMonitors, deletingMonitor, sortByTwo, printMonitors};
    while (1) {
        // if(*n == 0) printf("There is no elements in your list.\n"); 
        printf("Select task: \n"
               "\t1. Add a monitor\n"
               "\t2. Delete a monitor\n"
               "\t3. Sort monitors by two options\n"
               "\t4. Print monitors\n"
               "\tClose programm - 0\n\n");
        int choice = getintMinMax(0, 4);
        if (choice == 0){
            printf("The program has ended.\n");   
            system("pause");
            exit(1);
        }
        else {
            tasks[choice - 1](monitors, n);
            printf("\n");
        }
    }
}