/*******

Author:         Recep Mehmet Akgül
Description:    Dynamic Array Management in C++,
                We are using malloc,realloc,free,getch and void functions in this project.
                We don't assign the variable for array just we show random place in ROM.
Date:           14.06.2019

*******/

#include <iostream>
#include <conio.h>

const char resizeArray = 'r';
const char listArray = 'l';
const char setArray = 's';
const char addValueArray = 'a';
const char avarageOfArray = 't';


void takeInputInKeyboard(char *c) {
        *c = getche();//We are taking for press the screen
}

int main() {
    char key = ' ';
    double *Array = new double[0];
    int sizeOfNewArray = 0;
    int changeOfSize;
    double value = 0;
    double total = 0;
    double avarage = 0;

    while(key != 'q') {
        takeInputInKeyboard(&key);
        switch (key) {

            case resizeArray:
                std::cout << std::endl;
                std::cout << "Enter your new array size" << std::endl;
                std::cin >> sizeOfNewArray;
                std::cout << std::endl;

                Array = (double *) realloc(Array, sizeOfNewArray * sizeof(double));

                for (int temp = 0; temp < sizeOfNewArray; ++temp) {
                    double i=0;
                    std::cin >> i;
                    Array[temp] = i;
                }

                break;

            case listArray:
                std::cout << "List Of Array" << std::endl;
                for (int temp = 0; temp < sizeOfNewArray; ++temp) {
                    std::cout << Array[temp] << std::endl;
                }
                break;

            case setArray:
                std::cout << "Which value you want change" << std::endl;
                std::cin >> changeOfSize;
                std::cout << "Enter the Value" << std::endl;
                std::cin >> value;

                Array[changeOfSize] = value;

                break;

            case addValueArray:
                for (int temp = 0; temp < sizeOfNewArray; ++temp) {
                   total += Array[temp];
                }

                std::cout << "Total: "<< total << std::endl;

                break;

            case avarageOfArray:
                avarage = total / sizeOfNewArray;
                std::cout << "Avarage:" << avarage << std::endl;

                break;
        }
        key = ' ';
    }

    free(Array);
    return  0;
}