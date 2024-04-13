#include <stdio.h>
#include "../include/headerA3.h"

void sortCarId(struct car **headLL) {
    // If the list is empty or has only one node, it's already sorted
    if (*headLL == NULL || (*headLL)->nextCar == NULL) {
        return;
    }

    // Variable to keep track of whether any nodes were swapped in the last pass
    int swapped;
    struct car *ptr1;
    struct car *lptr = NULL;

    do {
        // Start each pass with no swaps made
        swapped = 0;

        // Starts at the beginning of the list
        ptr1 = *headLL;

        // Traverse the list until the end or until the last node swapped in the previous pass
        while (ptr1->nextCar != lptr) {
            // If the current node's carId is greater than the next node's carId, swap them
            if (ptr1->carId > ptr1->nextCar->carId) {
                struct car *temp = ptr1;
                ptr1 = ptr1->nextCar;
                temp->nextCar = ptr1->nextCar;
                ptr1->nextCar = temp;
                // If the first node was swapped, update the head of the list
                if (lptr == NULL) {
                    *headLL = ptr1;
                }
                // Indicate that a swap was made
                swapped = 1;
            }

            // Move to the next node
            ptr1 = ptr1->nextCar;
        }
        // The last node checked in this pass will be the end point for the next pass
        lptr = ptr1;
    } while (swapped); // Repeat if any swaps were made
}