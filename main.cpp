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


int main() {
    char key = ' ';
    double *Array = new double[0];
    int sizeOfNewArray = 0;
    int changeOfSize;
    double value = 0;
    double total = 0;
    double avarage = 0;

    std::cout << "For Resize  : 'r' " << std::endl;
    std::cout << "For List    : 'l' " << std::endl;
    std::cout << "For Set     : 's' " << std::endl;
    std::cout << "For Summary : 'a' " << std::endl;
    std::cout << "For Avarage : 't' " << std::endl;

    while(key != 'q') {
        std::cout << "Command > ";
        std::cin>>key;

        switch (key) {

            case resizeArray:
                std::cout << std::endl;
                std::cout << "Current Array Size: "<<sizeOfNewArray << std::endl;
                std::cout << "Enter your new array size" << std::endl;
                std::cin >> sizeOfNewArray;
                std::cout << std::endl;


                Array = (double *) realloc(Array, sizeOfNewArray * sizeof(double));

                for (int temp = 0; temp < sizeOfNewArray; ++temp) {
                    double i=0;
                    std::cout << temp+1 << " Number :  ";
                    std::cin >> i;
                    Array[temp] = i;
                }

                break;

            case listArray:
                std::cout << std::endl;
                std::cout << "List Of Array" << std::endl;
                for (int temp = 0; temp < sizeOfNewArray; ++temp) {
                    std::cout << temp+1 << " Number : ";
                    std::cout << Array[temp] << std::endl;
                }
                break;

            case setArray:
                std::cout << "Which value you want change   ";
                std::cin >> changeOfSize;
                std::cout << "Enter the Value  ";
                std::cin >> value;

                Array[changeOfSize] = value;

                break;

            case addValueArray:
                std::cout << std::endl;
                for (int temp = 0; temp < sizeOfNewArray; ++temp) {
                   total += Array[temp];
                }

                std::cout << "Total: "<< total << std::endl;
                total=0;
                break;

            case avarageOfArray:
                std::cout << std::endl;
                for (int temp = 0; temp < sizeOfNewArray; ++temp) {
                    total += Array[temp];
                }
                avarage = total / sizeOfNewArray;
                std::cout << "Avarage:  " << avarage << std::endl;
                total=0;
                break;
        }
        key = ' ';
    }

    free(Array);
    return  0;
}