bin/carBase: src/mainA3.o src/addNewCar.o src/printOne.o src/printAll.o src/lookForCarId.o src/lookForCarModelType.o src/sortCarId.o src/loadCarData.o src/countCars.o src/noMoreCars.o src/oneLessCar.o
	gcc -Wall -std=c99 src/mainA3.o src/addNewCar.o src/printOne.o src/printAll.o src/lookForCarId.o src/lookForCarModelType.o src/sortCarId.o src/loadCarData.o src/countCars.o src/noMoreCars.o src/oneLessCar.o include/headerA3.h -o ./bin/carBase

mainA3.o: src/mainA3.c include/headerA3.h
	gcc -Wall -std=c99 -c src/mainA3.c 

addNewCar.o: src/addNewCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/addNewCar.c 

printOne.o: src/printOne.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printOne.c 

printAll.o: src/printAll.c include/headerA3.h
	gcc -Wall -std=c99 -c src/printAll.c 

lookForCarId.o: src/lookForCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarId.c 

lookForCarModelType.o: src/lookForCarModelType.c include/headerA3.h
	gcc -Wall -std=c99 -c src/lookForCarModelType.c 

sortCarId.o: src/sortCarId.c include/headerA3.h
	gcc -Wall -std=c99 -c src/sortCarId.c 

loadCarData.o: src/loadCarData.c include/headerA3.h
	gcc -Wall -std=c99 -c src/loadCarData.c 

countCars.o: src/countCars.c include/headerA3.h
	gcc -Wall -std=c99 -c src/countCars.c 

noMoreCars.o: src/noMoreCars.c include/headerA3.h
	gcc -Wall -std=c99 -c src/noMoreCars.c 

oneLessCar.o: src/oneLessCar.c include/headerA3.h
	gcc -Wall -std=c99 -c src/oneLessCar.c

clean:
	rm src/*.o bin/carBase
