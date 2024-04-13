#include <stdio.h>
#include "../include/headerA3.h"

int countCars (a3Car * headLL){
    struct car *temp = headLL;  //make a temp pointer
    int count = 0;  //sets the count to 0

    if (headLL == NULL) {   //checks if the linked list is empty
        printf("The linked list is empty\n"); //prints the message
        return 0; 
    }

    while (temp != NULL) {  //if the linked is not empty
        temp = temp->nextCar;   //move to the next car
        count++;    //increment the count
    }
    return count; // Return the number of cars in the linked list
}
