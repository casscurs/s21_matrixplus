#include "s21_matrix_oop.hpp"

/* Конструктор по умолчанию */
S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr){};

/* Параметризованный конструктор */
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols)
{
    if (rows_ < 0 || cols_ < 0)
    {
        throw std::invalid_argument("Incorrect matrix size");
    }
    this->initMatrix();
};

/* Конструктор копирования */
S21Matrix::S21Matrix(const S21Matrix& other) noexcept
    : S21Matrix(other.rows_, other.cols_)
{
    std::cout << "aboba";
    this->cpyMatrix(other);
};

/* Конструктор перемещения */
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_)
{
    other.rows_ = 0;
    int* a;
    other.cols_ = 0;
    other.matrix_ = nullptr;
};

/* Деструктор */
S21Matrix::~S21Matrix() noexcept { freeMatrix(); };

int main(void)
{
    S21Matrix s1(5, 5);
    //   int k = 0;
    //   for (int i = 0; i != 5; ++i) {
    //     for (int j = 0; j != 5; ++j) {
    //       s1.matrix_[i][j] = ++k;
    //     }
    //   }

    S21Matrix s2(5, 5);
    //   int m = 25;
    //   for (int i = 0; i != 5; ++i) {
    //     for (int j = 0; j != 5; ++j) {
    //       s2.matrix_[i][j] = --m;
    //     }
    //   }
    //   s1.printMatrix();
    //   std::cout << "\n";
    //   s2.printMatrix();

    s1 = s2;
    //   std::cout << "\n";
    //   s1.printMatrix();
    return 0;
}
