#include "s21_matrix_oop.hpp"

void S21Matrix::freeMatrix()
{
    for (int i = 0; i != rows_; ++i)
    {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = nullptr;
}

void S21Matrix::cpyMatrix(const S21Matrix& other)
{
    for (int i = 0; i != other.rows_; ++i)
    {
        for (int j = 0; j != other.cols_; ++j)
        {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

void S21Matrix::initMatrix()
{
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; ++i)
    {
        try
        {
            matrix_[i] = new double[cols_]();
        }
        catch (const std::exception& ex)
        {
            for (int j = 0; j < i; ++j)
            {
                delete[] matrix_[j];
            }
            delete[] matrix_;
            throw ex;
        }
    }
}

void S21Matrix::swap(S21Matrix& other)
{
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
}

/* Вернет true, если числа равны, false - не равны */
bool S21Matrix::float_compare(double a, double b)
{
    return round(a * pow(10, 6)) == round(b * pow(10, 6)) ? true : false;
}

/* Вернет true, если размеры совпали */
bool S21Matrix::size_check(const S21Matrix& other)
{
    bool result = true;
    if (rows_ != other.rows_ || cols_ != other.cols_)
    {
        result = false;
    }
    return result;
}