#include <stdio.h>
#include <locale.h>
#include "../include/headerA3.h"

int lookForCarId(struct car *headLL, int key) {
    struct car *temp = headLL; //make a temp pointer
    int count = 1;  //set count to 1

    if (headLL == NULL) {   //Checks if the linked list is empty
        printf("The linked list is empty\n");   //Prints the message
        return 0;
    }

    setlocale(LC_NUMERIC, "");

    while (temp != NULL) {  //If the LL is not empty
        if (temp->carId == key) { // Check if the carId matches the key
            //prints the car info
            printf("========================================\n");
            printf("Car id: %d\n", temp->carId);
            printf("Model: %s\n", temp->model);
            printf("Type: %s\n", temp->type);
            printf("Price: CDN $%'.2f\n", temp->price);
            printf("Year of Manufacture: %d\n", temp->year);
            printf("========================================\n");
            return count; // Return the position of the car
        }
        temp = temp->nextCar;
        count++;
    }
    return -1; // Return -1 if the car is not found
}