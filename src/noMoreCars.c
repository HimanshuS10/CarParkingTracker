#include <stdio.h>
#include "../include/headerA3.h"

void noMoreCars(a3Car **headLL) {
    char userChoice; 
    printf("Are you sure you want to remove all car data (enter y for yes, n for no): "); //Asks the user if they want to remove all car data
    scanf(" %c", &userChoice);  //Scans the user input

    while (userChoice != 'y' && userChoice != 'n') { //If the user input is not 'y' or 'n'
        printf("Invalid input. Please enter 'y' for yes or 'n' for no: "); // It will ask the user again to enter 'y' or 'n'
        scanf(" %c", &userChoice);
    }

    if (userChoice == 'y') { //If the user input is 'y'
        struct car *temp; //Cretaes a temporary pointer

        while (*headLL != NULL) { // While the linked list is not empty
            temp = *headLL;
            *headLL = (*headLL)->nextCar;
            free(temp); //Frees the memory
        }

        printf("All removed. Linked list is now empty.\n"); //Prints the message
    }
    else if (userChoice == 'n') { //If the user input is 'n'
        printf("No cars were removed.\n"); //Prints the message
    }
}