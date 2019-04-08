//
// Created by nubia on 4/7/2019.
//
#pragma once

class Matrix {
    //double* data;
    double* data_row;
    double* data_col;
    int dimension;

public:
    //Constructor creates a square Matrix of size dimention x dimention
    Matrix(int dimension) {
        this->dimension = dimension;
        //data = new double[dimension * dimension];
        data_col = new double[dimension * dimension];
        data_row = new double[dimension * dimension];
    }
    //Destructor
    ~Matrix(){
        //delete[] data;
        delete[] data_col;
        delete[] data_row;
    }

    //Set the value of an element
    void set(int col, int row, double v);

    //The value of an element
    double get(int col, int row);

    double get_row(int col, int row);

    double get_col(int col, int row);

    //Moves values of src into dest
    static void MOV(Matrix& dest, Matrix& src);

    //Multiply src1 & src2, store the result in dest
    static void MUL(Matrix& dest, Matrix& src1, Matrix& src2);
};
