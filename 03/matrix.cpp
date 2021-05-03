#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "matrix.h"

 Row::Row(int *matrix, size_t columns): columns_(columns), row_(matrix)
    {
    };

    int& Row::operator [](size_t j)
    {
        if (j >= columns_) {
            throw std::out_of_range("Попытка выйти за пределы матрицы");
        }
        return row_[j];
    };

    const int& Row::operator [](size_t j) const
    {
        if (j >= columns_) {
            throw std::out_of_range("Попытка выйти за пределы матрицы");
        }
        return row_[j];
    };

    Matrix::Matrix(size_t rows, size_t columns): rows_(rows), columns_(columns)
    {
        matrix_ = new int32_t*[rows_];
        for (size_t i = 0; i < rows_; i++) {
            matrix_[i] = new int32_t[columns_];
        }
    };

    Matrix::Matrix(const Matrix &m): rows_(m.getRows()), columns_(m.getColumns())
    {
        matrix_ = new int32_t*[rows_];
        for (size_t i = 0; i < rows_; i++) {
            matrix_[i] = new int32_t[columns_];
        }
        for (size_t i = 0; i < rows_; i++) {
            for (size_t j = 0; j < columns_; j++) {
                matrix_[i][j] = m[i][j];
            }
        }
    };

    Row Matrix::operator [](size_t i)
    {
        if (i >= rows_) {
            throw std::out_of_range("Попытка выйти за пределы матрицы");
        }
        Row row(matrix_[i], columns_);
        return row;
    };

    const Row Matrix::operator [](size_t i) const
    {
        if (i >= rows_) {
            throw std::out_of_range("Попытка выйти за пределы матрицы");
        }
        Row row(matrix_[i], columns_);
        return row;
    };

    size_t Matrix::getRows() const
    {
        return rows_;
    };

    size_t Matrix::getColumns() const
    {
        return columns_;
    };

    Matrix& Matrix::operator =(const Matrix m)
    {
        if (m.getRows() != rows_ || m.getColumns() != columns_) {
            for (size_t i = 0; i < rows_; i++) {
                delete[] matrix_[i];
            }
            delete[] matrix_;
            rows_ = m.getRows();
            columns_ = m.getColumns();
            matrix_ = new int *[rows_];
            for (size_t i = 0; i < rows_; i++) {
                matrix_[i] = new int[columns_];
            }
        }
        for (size_t i = 0; i < rows_; i++) {
            for (size_t j = 0; j < columns_; j++) {
                matrix_[i][j] = m[i][j];
            }
        }
        return *this;
    };

    Matrix& Matrix::operator *=(int a)
    {
        for (size_t i = 0; i < rows_; i++) {
            for (size_t j = 0; j < columns_; j++) {
                matrix_[i][j] *= a;
            }
        }
        return *this;
    };

    Matrix Matrix::operator +(Matrix &m) const
    {
        if (m.getRows() != rows_ || m.getColumns() != columns_) {
            throw std::out_of_range("Операция сложения: не совпадают размеры матриц");
        }
        Matrix res(rows_, columns_);
        for (size_t i = 0; i < rows_; i++) {
            for (size_t j = 0; j < columns_; j++) {
                res[i][j] = matrix_[i][j] + m[i][j];
            }
        }
        return res;
    };

    bool Matrix::operator ==(Matrix &m) const
    {
        if (m.getRows() != rows_ || m.getColumns() != columns_) {
            return false;
        }
        for (size_t i = 0; i < rows_; i++) {
            for (size_t j = 0; j < columns_; j++) {
                if (matrix_[i][j] != m[i][j]) {
                    return false;
                }
            }
        }
        return true;
    };

    bool Matrix::operator !=(Matrix &m) const
    {
        if (m.getRows() != rows_ || m.getColumns() != columns_) {
            return true;
        }
        for (size_t i = 0; i < rows_; i++) {
            for (size_t j = 0; j < columns_; j++) {
                if (matrix_[i][j] != m[i][j]) {
                    return true;
                }
            }
        }
        return false;
    };

    Matrix::~Matrix()
    {
        for (size_t i = 0; i < rows_; i++) {
            delete [] matrix_[i];
        }
        delete [] matrix_;
    };


std::ostream &operator <<(std::ostream &os, Matrix &m)
{
    for (size_t i = 0; i < m.getRows(); i++) {
        for (size_t j = 0; j < m.getColumns() - 1; j++) {
            os << std::setw(7) << m[i][j] << ' ';
        }
        os << std::setw(7) << m[i][m.getColumns() - 1] << std::endl;
    }
    return os;
};