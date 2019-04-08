//
// Created by nubia on 4/7/2019.
//
#include <iostream>
#include <ctime>
#include "Matrix.h"

int main() {
    std::cout.precision(6);

    //Declare some matricies
    int dimension = 1000;
    Matrix* a = new Matrix(dimension);
    Matrix* b = new Matrix(dimension);
    Matrix* c = new Matrix(dimension); //result

    //Init matricies with random values:
    for(int row = 0; row < dimension; row++) {
        for(int col = 0; col < dimension; col++) {
            //random values from 0.0 to 1.0
            double va = (double)rand() / (double)RAND_MAX;
            double vb = (double)rand() / (double)RAND_MAX;
            a -> set(col, row, va);
            b -> set(col, row, vb);
        }
    }

    //for loop multiplies matrix a & b, stores result in matrix c.
    for(int run = 0; run < 10; run++) {
        long start_time = clock();
        Matrix::MUL(*c,  *a, *b);
        long finish_time = clock();
        std::cout << "Product operation time: " << (finish_time - start_time) << std::endl;
    }

    std::cout << "Operation Output: " << std::endl;
    for(int row = 0; row < 10; row++) {
        for(int col = 0; col < 10; col++) {
            std::cout << " " << c -> get_col(col, row);
            //std::cout << " " << c -> get(col, row);
        }
        std::cout << std::endl;
    }
    std::cout << "All Done!" << std::endl;
    std::cin.get();
    return 0;
}
