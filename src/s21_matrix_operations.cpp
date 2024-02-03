#include "s21_matrix_oop.hpp"

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept
{
    if (!size_check(other)) return false;

    for (int i = 0; i < rows_; i++)
    {
        for (int j = 0; j < cols_; j++)
        {
            if (!float_compare(matrix_[i][j], other.matrix_[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other)
{
    if (!size_check(other))
        throw std::invalid_argument("Incorrect matrix size");

    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other)
{
    if (!size_check(other))
        throw std::invalid_argument("Incorrect matrix size");

    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            matrix_[i][j] -= other.matrix_[i][j];
        }
    }
}

void S21Matrix::MulNumber(const double num) noexcept
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            matrix_[i][j] *= num;
        }
    }
}

int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result)
{
    if ((common_check(A) || common_check(B))) return INCOR_MATR;
    if ((A->columns != B->rows)) return CALC_ER;
    int error = s21_create_matrix(A->rows, B->columns, result);
    if (error == CORRECT)
    {
        for (int i = 0; i < result->rows; ++i)
        {
            for (int j = 0; j < result->columns; ++j)
            {
                result->matrix[i][j] = 0;
                for (int k = 0; k < A->columns; k++)
                {
                    result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
                }
            }
        }
    }
    return error;
}
