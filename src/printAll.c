#include <stdio.h>
#include <locale.h>
#include "../include/headerA3.h"

void printAll(struct car *headLL) {

    if (headLL == NULL) {   //Checks if the LL is empty
        printf("No cars found\n"); //Prints the message
        return;
    }

    struct car *ptr = headLL; //Creates a pointer
    int carNumber = 1;  //Sets the car number to 1

    /*https://stackoverflow.com/questions/1449805/how-to-format-a-number-using-comma-as-thousands-separator-in-c*/
    setlocale(LC_NUMERIC, "");

    while (ptr != NULL) { //If the LL is not empty
        printf("Car #%d\n", carNumber++); //Prints the car number
        //Prints the car info
        printf("========================================\n");
        printf("Car ID: %d\n", ptr->carId);
        printf("Model: %s\n", ptr->model);
        printf("Type: %s\n", ptr->type);
        printf("Price: CDN $%'.2f\n", ptr->price);
        printf("Year of Manufacture: %d\n", ptr->year);
        printf("========================================\n");
        ptr = ptr->nextCar;
    }
}