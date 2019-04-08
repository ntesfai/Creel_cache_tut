#include <iostream>
#include <ctime>
#include "Matrix.h"

void Matrix::set(int col, int row, double v){
    //data[col + row * dimension] = v;
    data_row[row + col * dimension] = v;
    data_col[col + row * dimension] = v;
}

/*double Matrix::get(int col, int row) {
    return data[col + row * dimension];
}*/

double Matrix::get_row(int col, int row) {
    return data_row[row + col * dimension];
}

double Matrix::get_col(int col, int row) {
    return data_col[col + row * dimension];
}

void Matrix::MOV(Matrix& dest, Matrix& src) {
    for(int i = 0; i < dest.dimension * dest.dimension; i++) {
        //dest.data[i] = src.data[i];
        dest.data_col[i] = src.data_col[i];
        dest.data_row[i] = src.data_row[i];
    }
}

void Matrix::MUL(Matrix &dest, Matrix &src1, Matrix &src2) {
    int dim = dest.dimension;
    Matrix *tmp = new Matrix(dest.dimension);

    int blockSize = 200;

    for (int row = 0; row < dim; row += blockSize) {
        for (int col = 0; col < dim; col += blockSize) {

            for(int block_row = row; block_row < row + blockSize; block_row++) {
                for(int block_col = col; block_col < col + blockSize; block_col++) {
                    double result = 0.0;

                    //Compute dot product
                    for (int dot = 0; dot < dim; dot++) {
                        //result += src1.get(dot, row) * src2.get(col, dot);
                        //result += src1.get_col(dot, row) * src2.get_row(col, dot);
                        result += src1.get_col(dot, block_row) * src2.get_row(block_col, dot);
                    }
                    //tmp->set(col, row, result);
                    tmp->set(block_col, block_row, result);
                }
            }
        }
    }
    //Move tmp into dest
    Matrix::MOV(dest, *tmp);
    delete tmp;
}
