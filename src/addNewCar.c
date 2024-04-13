#include <stdio.h>
#include <locale.h>
#include "../include/headerA3.h"

void addNewCar (struct car ** headLL){
    
    struct car newCar;  //create a newCar
    int sum = 0;    //initialize sum
    int lenghtCarType = 0;  //initialize lenghtCarType

    printf("Enter a car model: ");  //asks the user to enter a model
    scanf("%s", &newCar.model); //scans the model

    printf("Enter the car type: "); //asks the user to enter car type
    scanf("%s", &newCar.type);  //scans the type

    printf("Enter its year of manufacture: ");  //asks the user to enter the year
    scanf("%d", &newCar.year);  //scans the year

    printf("Enter its price: CDN $");   //asks the user to enter the price
    scanf("%lf", &newCar.price);    //scans the price

    struct car *newNode = (struct car *)malloc(sizeof(struct car)); //memory allocation 

    strcpy(newNode->model, newCar.model);   //string newCar.model is copied to newNode->model
    strcpy(newNode->type, newCar.type); //string newCar.type is copied to newNode->type
    newNode->year = newCar.year;    //reassign the year to newCar.year
    newNode->price = newCar.price;  //reassign the price to newCar.price

    // Update the linked list
    newNode->nextCar = *headLL;
    *headLL = newNode;

    //iterates over each character until reached NULL
    for (int i = 0; newCar.model[i] != '\0'; i++) {
        //adds the ASCII value
        sum += newCar.model[i];
    }
    
    //find the lenght of the car model
    lenghtCarType = strlen(newCar.type);
    
    newNode->carId = sum + lenghtCarType;

    setlocale(LC_NUMERIC, "");

    for(int i = 0; i < 50; i++){
        printf("=");
    }
    //print the car details
    printf("\nCar model: %s\n", newNode->model);
    printf("Car type: %s\n", newNode->type);
    printf("Year of manufacture: %d\n", newNode->year);
    printf("Price: CDN $%'.2f\n", newNode->price);
    printf("Your computer-generated carId is %d\n", newNode->carId);
    
    for(int i = 0; i < 50; i++){
        printf("=");
    }
    printf("\n");
}
