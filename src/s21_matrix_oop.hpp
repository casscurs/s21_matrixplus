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

    /* Acessors and Mutators */
    int get_rows();
    int get_cols();
    void set_rows(int otherRows);
    void set_cols(int otherCols);

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
    double Determinant() const;
    S21Matrix InverseMatrix();

  private:
    /* Вспомогательные функции*/
    void freeMatrix();
    void cpyMatrix(const S21Matrix& other);
    void initMatrix();
    void swap(S21Matrix& other);
    bool float_compare(double a, double b);
    bool size_check(const S21Matrix& other);
    double Bareiss_algorith(const S21Matrix& buf);
    void find_minor(int i, int j, const S21Matrix& A, S21Matrix& buf);
};

//+ - * == = += -= *= (int i, int j)
// accessor и mutator