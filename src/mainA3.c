#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/headerA3.h"

int main()
{

  int userChoice;
  struct car *headLL = NULL;
  headLL = (struct car *)malloc(sizeof(struct car));

  // Main main loop
  while (true)
  {
    // Prints the menu
    printf("1. Add data on a new car\n");
    printf("2. Load data on cars from a given text file\n");
    printf("3. Print data of all cars\n");
    printf("4. Print data of the nth car\n");
    printf("5. Search car data based on carId\n");
    printf("6. Search car data based on model and type\n");
    printf("7. Count the total number of cars in the list\n");
    printf("8. Sort the cars in the list based on carId\n");
    printf("9. Remove data of the nth car\n");
    printf("10. Remove all car data\n");
    printf("11. Exit\n");
    printf("Choose a menu option: ");
    scanf("%d", &userChoice);

    switch (userChoice)
    {

    case 1: // Task 1
      addNewCar(&headLL);
      break;
    case 2: // Task 2
      char fileName[MAX_LENGTH];
      strncpy(fileName, "inputfile.txt", MAX_LENGTH - 1);
      fileName[MAX_LENGTH - 1] = '\0';
      loadCarData(&headLL, fileName);
      break;

    case 3:             // Task 3
      printAll(headLL); // Function call
      break;

    case 4:                         // Task 4
      int position;                 // Declare a variable to store position
      printf("Enter a position: "); // Asks the user for the position
      scanf("%d", &position);       // reads the position

      while (position > countCars(headLL) || position < 1) // If the position is greater than the number of cars or less than 1
      {
        printf("Invalid position. Please enter a valid position: ");
        scanf("%d", &position);
      }

      printOne(headLL, position); // Function call
      break;

    case 5:                       // Task 5
      int key;                    // Declare a variable to carId
      printf("Enter a car ID: "); // Asks the user to enter a car ID
      scanf("%d", &key);          // reads the car ID
      lookForCarId(headLL, key);  // Function call
      break;

    case 6:                // Task 6
      char model[50];      // Declare a variable to store model
      char type[50];       // Declare a variable to store type
      char modelType[100]; // Declare a variable to store modelType

      printf("Enter the model and type (separated by a space): ");
      scanf("%s%s", model, type);

      strcpy(modelType, model); // Copy first name to fullName
      strcat(modelType, " ");   // Append a space
      strcat(modelType, type);  // Append last name

      lookForCarModelType(headLL, modelType);
      break;
    case 7: // Task 7
      printf("============================================\n");
      printf("Total number of cars = %d\n", countCars(headLL));
      printf("============================================\n");
      break;

    case 8: // Task 8
      sortCarId(&headLL);
      printf("Linked list sorted based on carId.\n");
      break;

      break;
    case 9: // Task 9
    {
      printf("============================================\n"); // Prints the message
      int numCars = countCars(headLL);                          // Get the number of cars
      printf("Currently there are %d cars.\n", numCars);        // Prints the message
      int n;
      do
      {
        printf("Which car do you wish to remove - enter a value between 1 and %d: ", numCars);
        scanf("%d", &n);
      } while (n < 1 || n > numCars);
      struct car *currentCar = headLL;

      for (int i = 1; i < n; i++)
      {
        currentCar = currentCar->nextCar;
      }

      // Remove the car
      oneLessCar(&headLL, n);
      printf("Car [Id: %d] removed.\n", currentCar->carId);
      printf("There are now %d cars remaining.\n", numCars - 1);
      printf("============================================\n");
    }
    break;

    case 10: // Task 10
      noMoreCars(&headLL);
      break;

    case 11: // Task 9
      printf("Exiting the program.\n");
      exit(0);

    default:
      printf("Invalid choice. Please enter a valid option.\n");
      break;
    }
  }
  return 0;
}