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

  private:
    /* Вспомогательные функции*/
    void freeMatrix();
    void cpyMatrix(const S21Matrix& other);
    void initMatrix();
    void swap(S21Matrix& other);
    bool float_compare(double a, double b);
    bool size_check(const S21Matrix& other);
};

//----
#define CORRECT 0
/* Ошибка, некорректная матрица */
#define INCOR_MATR 1
/* Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя
   провести вычисления и т.д.) */
#define CALC_ER 2

#define SUCCESS 1
#define FAILURE 0

/* Main functions */
// int s21_create_matrix(int rows, int columns, matrix_t* result);
// void s21_remove_matrix(matrix_t* A);
// int s21_eq_matrix(matrix_t* A, matrix_t* B);
// int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
// int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);
/* Help functions */
int size_check(matrix_t* A, matrix_t* B);
void swap(double* A, double* B);
void find_minor(int i, int j, matrix_t A, matrix_t* buf);
void Bareiss_algorith(matrix_t buf, double* result);
