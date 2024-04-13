#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/headerA3.h"

void loadCarData(struct car **headLL, char fileName[MAX_LENGTH]){
    FILE *file;                  // Declare a FILE pointer
    file = fopen(fileName, "r"); // Open the file in read mode

    if (file == NULL)
    {                                                 // Checks if the file is opened
        printf("Failed to open file %s\n", fileName); // Prints the message
        return;                                       // Returns
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        // Allocate memory for a new car struct
        struct car *newCar = malloc(sizeof(struct car));
        if (newCar == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        // Tokenize the line on commas
        char *token = strtok(line, ",");
        // If the first token is not NULL, assign it to the carId field and get the next token
        if (token != NULL)
        {
            newCar->carId = atoi(token);
            token = strtok(NULL, ",");
        }

        // If the next token is not NULL, assign it to the model field and get the next token
        if (token != NULL)
        {
            strcpy(newCar->model, token);
            token = strtok(NULL, ",");
        }

        // If the next token is not NULL, assign it to the type field and get the next token
        if (token != NULL)
        {
            strcpy(newCar->type, token);
            token = strtok(NULL, ",");
        }

        // If the next token is not NULL, assign it to the year field and get the next token
        if (token != NULL)
        {
            newCar->year = atoi(token);
            token = strtok(NULL, ",");
        }

        // If the next token is not NULL, assign it to the price field and get the next token
        if (token != NULL)
        {
            newCar->price = atof(token);
        }

        newCar->nextCar = *headLL;
        *headLL = newCar;
    }
    // closes the file
    fclose(file);
}
