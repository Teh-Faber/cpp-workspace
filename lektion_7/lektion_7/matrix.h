#pragma once

#include <iostream>
#include <vector>
#include <memory>

class Matrix{
private:
    std::vector<double> _data;
    int _rows;
    int _cols;

public:
    Matrix(int rows, int cols, double val = 0): _rows(rows), _cols(cols){
        for(int i=0; i < size; i++){ //Fill vector with val with matrix size
            _data.push_back(val);
        }
    }


    int size = _rows*_cols;


    int getRows(){
        return _rows;
    }


    int getCols(){
        return _cols;
    }


    void print(){ // print entire matrix in console
        for(int i=0; i < _rows; ++i){ // all rows
            for(int j=0; j < _cols; ++j){ // all cols
                std::cout << _data[i*_cols + j] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << std::endl;
    }


    double read(int r, int c){ // read value at position r,c
        return _data[r*_cols + c];
    }


    void set(int r, int c, double val){ // set value at position r,c
        _data[r*_cols + c] = val;
    }


    double& at(int r, int c){ // return reference to value at position r,c
        return _data[r*_cols + c];
    }


    Matrix add(Matrix& matrix){ // check size & return the elementwise sum of matrice
        Matrix res(_rows, _cols, 0);

        if(_rows != matrix._rows || _cols != matrix._cols) // if not equal in size return zeros
            return res;

        for(int i=0; i < size; ++i){ // sum all elements
            res._data[i] = _data[i] + matrix._data[i];
        }

        return res;
    }


    Matrix multiply(Matrix& matrix){
        Matrix res(_rows, matrix._cols, 0);
        double sum = 0;

        if(_cols != matrix._rows) // if not compatible return zeros
            return res;

        for(int r=0; r < _rows; ++r){ // each row in matrix A
            for(int c=0; c < matrix._cols; ++c){ // each col in matrix B
                for(int cr=0; cr < _cols; ++cr){ // each col in matrix A and row in matrix B
                    sum += read(r,cr)*matrix.read(cr,c); // multiply elementwise and sum products together
                }
                res.set(r, c, sum); // insert sum in result at correct place
                sum = 0; // reset sum
            }
        }
        return res;
    }


    void transpose(){
        Matrix temp(_cols,_rows);

        for(int i=0; i < size; i++){ // set _data from _rows = temp._cols & _cols = temp._rows
            temp.set(i%_cols, i/_cols, _data[i]); // i%_cols = temp._rows
        }

        // set equal to temp
        _data = temp._data;
        _rows = temp._rows;
        _cols = temp._cols;
    }


    std::shared_ptr<Matrix> add(std::shared_ptr<Matrix> matrix){ // overload add method to accept shared pointers
        return std::make_shared<Matrix>(add(*matrix)); // constructs a Matrix with the result on the Heap and returns shared pointer to object
    }


    std::shared_ptr<Matrix> multiply(std::shared_ptr<Matrix> matrix){ // overload multiply method to accept shared pointers
        return std::make_shared<Matrix>(multiply(*matrix)); // constructs a Matrix with the result on the Heap and returns shared pointer to object
    }


    double& operator()(int r, int c){ // overload "()" to call "at(r,c)"
        return at(r,c);
    }


    Matrix operator+(Matrix m){ // overload "+" to call "add"
        return add(m);
    }


    Matrix operator*(Matrix m){ // overload "*" to call "multiply"
        return multiply(m);
    }
};
