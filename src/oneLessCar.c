#include <stdio.h>
#include "../include/headerA3.h"

void oneLessCar(a3Car ** headLL, int whichOne) {
    if (*headLL == NULL) {
        // If the list is empty, nothing to remove
        return;
    }

    struct car *temp = *headLL;
    if (whichOne == 1) {
        // If the first car is to be removed
        *headLL = temp->nextCar; // Change head
        free(temp); // Free the old head
        return;
    }

    // Find the previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < whichOne - 1; i++) {
        temp = temp->nextCar;
    }

    // If position is more than the number of nodes
    if (temp == NULL || temp->nextCar == NULL) {
        return;
    }

    // Node temp->nextCar is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct car *next = temp->nextCar->nextCar;

    // Unlink the node from linked list
    free(temp->nextCar); // Free memory
    temp->nextCar = next; // Unlink the deleted node from list
}
