#include <conio.h>
#include "menu.c"

int main () {
    monitor_t* monitors;
    printf("\n\033[1;34mFirstly your list of monitors is blank, so you should add some. How much you want to add?\033[0m\n");
    int n = 0;
    while(n == 0){
        n = getintMin(0);
        if (n == 0) {
            printf("\n\033[1;31mYou have to add at least 1 monitor. \033[0m");
            printf("\033[1;34mPress Esc if you want exit(Enter if continue).\033[0m\n");
            if(_getch() == 27) {
                printf("Ending...\n");
                break;
            }
            rewind(stdin);
        }
        printf("Continue...\n");
    }
    if (n > 0){
        arrayCreation(&monitors, &n);
        addMonitors1st(&monitors, &n);
        menu(&monitors, &n);
        free(monitors);
    }
    system("pause");
    return 0;
}