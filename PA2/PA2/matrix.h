#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>

using namespace std;

class Matrix{
private:
    vector<double> _data;
    int _rows;
    int _cols;

public:
    Matrix(int rows, int cols, double val = 0): _rows(rows), _cols(cols){
        for(int i=0; i < size(); i++){ // fill vector with val with matrix size
            _data.push_back(val);
        }
    }

    int size(){return _rows*_cols;}

    int getRows(){return _rows;}

    int getCols(){return _cols;}


    virtual void print(){ // print entire matrix in console
        for(int i=0; i < _rows; ++i){ // all rows
            for(int j=0; j < _cols; ++j){ // all cols
                cout << _data[i*_cols + j] << "\t";
            }
            cout << "\n";
        }
        cout << endl;
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

        // if not equal in size throw error
        if(_rows != matrix._rows || _cols != matrix._cols) throw invalid_argument("Matrices are not equal in size");

        for(int i=0; i < size(); ++i){ // sum all elements
            res._data[i] = _data[i] + matrix._data[i];
        }

        return res;
    }


    Matrix multiply(Matrix& matrix){
        Matrix res(_rows, matrix._cols, 0);
        double sum = 0;

        // if not compatible throw error
        if(_cols != matrix._rows) throw invalid_argument("Matrices are not compatible");

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


    virtual void transpose(){
        Matrix temp(_cols,_rows);

        for(int i=0; i < size(); i++){ // set _data from _rows = temp._cols & _cols = temp._rows
            temp.set(i%_cols, i/_cols, _data[i]); // i%_cols = temp._rows
        }

        // set equal to temp
        _data = temp._data;
        _rows = temp._rows;
        _cols = temp._cols;
    }


    shared_ptr<Matrix> add(shared_ptr<Matrix> matrix){ // overload add method to accept shared pointers
        return make_shared<Matrix>(add(*matrix)); // constructs a Matrix of the result on the Heap and returns shared pointer to object
    }


    shared_ptr<Matrix> multiply(shared_ptr<Matrix> matrix){ // overload multiply method to accept shared pointers
        return make_shared<Matrix>(multiply(*matrix)); // constructs a Matrix of the result on the Heap and returns shared pointer to object
    }


    double& operator()(int r, int c){return at(r,c);} // overload "()" to call "at(r,c)"


    Matrix operator+(Matrix m){return add(m);} // overload "+" to call "add"


    Matrix operator*(Matrix m){return multiply(m);} // overload "*" to call "multiply"

};
