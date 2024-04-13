#include <stdio.h>
#include <locale.h>
#include "../include/headerA3.h"


void printOne(struct car * headLL, int whichOne) {
    struct car *temp = headLL; //make a temp pointer
    int count = 1; //set count to 1

    if (temp == NULL) {   //Checks if the LL is empty
        printf("No cars found\n"); //Prints the message
        return;
    }

    setlocale(LC_NUMERIC, "");

    while (temp != NULL) { //If the LL is not empty
        if (count == whichOne) { // Check if the carId matches the key
            
            for(int i = 0; i < 50; i++){
                printf("=");
            }
            //Prints the info of the car
            printf("\n");
            printf("Car id: %d\n", temp->carId);
            printf("Model: %s\n", temp->model);
            printf("Type: %s\n", temp->type);
            printf("Price: CDN $%'.2f\n", temp->price);
            printf("Year of Manufacture: %d\n", temp->year);
            for(int i = 0; i < 50; i++){
                printf("=");
            }
            printf("\n");
            return;
        }
        temp = temp->nextCar;
        count++;
    }
}
