#include <exception>
#include <iostream>

class S21Matrix
{
  private:
    int rows_, cols_;
    double** matrix_;

  public:
    /* Конструкторы и деструктор*/
    S21Matrix() noexcept;
    explicit S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other) noexcept;
    S21Matrix(S21Matrix&& other) noexcept;
    ~S21Matrix() noexcept;

    /* Операторы */
    S21Matrix& operator=(S21Matrix other);

    /* Операции*/
    bool EqMatrix(const S21Matrix& other) noexcept;
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();

  private:
    /* Вспомогательные функции*/
    void freeMatrix();
    void cpyMatrix(const S21Matrix& other);
    void initMatrix();
    void swap(S21Matrix& other);
    bool float_compare(double a, double b);
    bool size_check(const S21Matrix& other);
    double Bareiss_algorith(S21Matrix& buf);
    void find_minor(int i, int j, const S21Matrix& A, S21Matrix& buf);
};

/* Main functions */
// int s21_create_matrix(int rows, int columns, matrix_t* result);
// void s21_remove_matrix(matrix_t* A);
// int s21_eq_matrix(matrix_t* A, matrix_t* B);
// int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// int s21_mult_number(matrix_t* A, double number, matrix_t* result);
// int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// int s21_transpose(matrix_t* A, matrix_t* result);
// int s21_calc_complements(matrix_t* A, matrix_t* result);
// int s21_determinant(matrix_t* A, double* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);
