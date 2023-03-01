#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "get.h"

void printMonitors (monitor_t** monitors, int* n);

//Task 0 - создание массива структур
void arrayCreation (monitor_t** monitors, int* n) {
    *monitors = malloc ((*n) * sizeof(monitor_t));
    if (*monitors == NULL) {
        printf("Allocation failed.");
        exit(0);
    }
}

//Task 1 - инициализация элемента/элементов структуры
void monitorFilling (monitor_t** monitors, int* n, int i) {
    char* tempChar = calloc (1, 1);

    printf("\nSelect monitor type:\n"
           "\t1. Gaming\n"
           "\t2. Home/Office\n"
           "\t3. Professional\n"
           "\t4. Other(portable, modular, for CCTV cameras and etc.)\n");
    printf(">>> ");
    int tempInt = getintMinMax(1,4);
    (*monitors)[i].monitorType = tempInt;

    printf("Producer: ");
    gets(tempChar);
    (*monitors)[i].producer = malloc(strlen(tempChar) + 1);
    strcpy((*monitors)[i].producer, tempChar);

    printf("Refresh Rate: ");
    tempInt = getintMin(0);
    (*monitors)[i].refreshRate = tempInt;

    printf("Screen Size: ");
    float tempFloat = getfloatMin(0);
    (*monitors)[i].screenSize = tempFloat;

    printf("Resolution(width, height):\n");
    printf(">>> ");
    tempInt = getintMin(0);
    (*monitors)[i].resolution[0] = tempInt;
    printf(">>> ");
    tempInt = getintMin(0);
    (*monitors)[i].resolution[1] = tempInt;

    printf("Price: ");
    double tempDouble = getdoubleMin(0);
    (*monitors)[i].price = tempDouble;
    
    free(tempChar);
}

void addMonitors (monitor_t** monitors, int* n) {
    printf("\n\033[1;34mHow much you want to add?\033[0m\n");
    int temp = *n;
    int num = getintMin(1);
    (*n) += num;
    *monitors = realloc(*monitors, (*n) * sizeof(monitor_t));
    int i = (*n) - 1;
    for(int i = temp; i < *n; i++)
        monitorFilling(monitors, n, i);
}

void addMonitors1st (monitor_t** monitors, int* n) {
    for(int i = 0; i < *n; i++)
        monitorFilling(monitors, n, i);
}

//Task 2 - удаление элемента структуры
void deletingMonitor (monitor_t** monitors, int* n) {
    if((*n) == 0) printf("Your list is blank.\n");
    else {
        printf("Enter the element number you want to delete.");
        int pos = getintMinMax(1, *n);
        for (int i = pos; i < (*n) - 1; i++) {
            (*monitors)[i] = (*monitors)[i + 1];
        }
        free((*monitors)[(*n) - 1].producer);
        (*n)--;
        *monitors = realloc (*monitors, (*n) * sizeof(monitor_t));
    }
}

//Task 3 - сортировка по двум полям одновременно
//Comparison
int compareMonitorType (monitor_t* first, monitor_t* second) {
    if (first->monitorType < second->monitorType) return -1;
    else if (first->monitorType > second->monitorType) return 1;
    return 0;
}  

int compareProducer (monitor_t* first, monitor_t* second) {
    if (strcmp(first->producer, second->producer) < 0) return -1;
    else if (strcmp(first->producer, second->producer) > 0) return 1;
}

int compareRefreshRate (monitor_t* first, monitor_t* second) {
    if (first->refreshRate < second->refreshRate) return -1;
    else if (first->refreshRate > second->refreshRate) return 1;
    return 0;
}

int compareScreenSize (monitor_t* first, monitor_t* second) {
    if (first->screenSize < second->screenSize) return -1;
    else if (first->screenSize > second->screenSize) return 1;
    return 0;
}

int compareResolution (monitor_t* first, monitor_t* second) {
    if ((first->resolution[0] * first->resolution[1]) < (second->resolution[0] * second->resolution[1])) return -1;
    else if ((first->resolution[0] * first->resolution[1]) > (second->resolution[0] * second->resolution[1])) return 1;
    return 0;
}

int comparePrice (monitor_t* first, monitor_t* second) {
    if (first->price < second->price) return -1;
    else if (first->price > second->price) return 1;
    return 0;
}

//General comparison
int compare (monitor_t* first, monitor_t* second, int field) {
    int result = 0;
    switch (field) {
    case 1:
        result = compareMonitorType(first, second);
        break;
    case 2:
        result = compareProducer(first, second);
        break;
    case 3:
        result = compareRefreshRate(first, second);
        break;
    case 4:
        result = compareScreenSize(first, second);
        break;
    case 5:
        result = compareResolution(first, second);
        break;
    case 6:
        result = comparePrice(first, second);
    }
    return result;
}

//Insertion Sort
void insertionSort (monitor_t* monitors, int n, int firstField, int secondField) {
 	for (int i = 1; i < n; i++) {
        monitor_t temp = monitors[i];
        int pos = i - 1;
        while (pos >= 0 && compare(&monitors[pos], &temp, firstField) > 0 && compare(&monitors[pos], &temp, secondField) >= 0) {
            monitors[pos + 1] = monitors[pos];
            pos--;
        }
        monitors[pos + 1] = temp;
    }
}

void sortByTwo (monitor_t** monitors, int* n) {
    printf("\nSort by two. Choose two options: \n"
           "\t1. Monitor type\n"
           "\t2. Producer\n"
           "\t3. Refresh Rate\n"
           "\t4. Screen Size\n"
           "\t5. Resolution\n"
           "\t6. Price\n");
    printf("\nFirst: ");
    int firstField = getintMinMax(1, 6);
    printf("\nSecond: ");
    int secondField = getintMinMax(1, 6);
    insertionSort(*monitors, *n, firstField, secondField);
    printMonitors(monitors, n);
}

//Task 4 - вывод на экран
void printMonitors (monitor_t** monitors, int* n) {
    if((*n) == 0) printf("\nThere is no elements in your list.\n");
    else {
        printf("\n*========================================================================*\n");
        for (int i = 0; i < (*n); i++) {
            printf(" %d#\n", i + 1);
            printf(" Monitor type: ");
            switch ((*monitors)[i].monitorType) {
                case 1:
                    printf("Gaming\n");
                    break;
                case 2:
                    printf("Home/Office\n");
                    break;
                case 3:
                    printf("Professional\n");
                    break;
                case 4:
                    printf("Other(portable, modular, for CCTV cameras and etc.)\n");
            }
            printf(" Producer: %s\n", (*monitors)[i].producer);
            printf(" Refresh Rate: %dHz\n", (*monitors)[i].refreshRate);
            printf(" Screen Size: %.1f\"\n", (*monitors)[i].screenSize);
            printf(" Resolution: %dx%d\n", (*monitors)[i].resolution[0], (*monitors)[i].resolution[1]);
            printf(" Price: %.2lf BYN\n", (*monitors)[i].price);
            printf("*========================================================================*\n");
        }
        printf("The number of elements is %d\nEnd.\n\n", *n);
    }
}