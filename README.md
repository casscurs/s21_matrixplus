# s21_matrix+

Implementation of the s21_matrix_oop.h library.

## Introduction

In this project, the matrix library is implemented using an object-oriented approach, allowing for defined operations represented both as methods and standard operators such as +, -, *.

## Chapter I

### Information

#### C++ and C

C++ is a programming language based on C, allowing for an object-oriented approach. C++ syntax rules are derived from C, enabling most C code to be copied into C++ programs and compiled successfully. C++ primarily adds or modifies capabilities for the programmer.

#### An example of a matrix class in C++

```cpp
class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to matrix memory

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        void SumMatrix(const S21Matrix& other); 
        // Other methods..
}
```
## A reminder of matrix basics
A matrix is a rectangular table of numbers arranged in rows and columns. Operations are performed based on matrix dimensions and element indices.

## Matrix operations
Operations to be implemented in the library:

| Operation | Description | Exceptional situations |
| --------- | ----------- | ---------------------- |
| `bool EqMatrix(const S21Matrix& other)` | Checks matrices for equality. |  |
| `void SumMatrix(const S21Matrix& other)` | Adds another matrix. | Different matrix dimensions. |
| `void SubMatrix(const S21Matrix& other)` | Subtracts another matrix. | Different matrix dimensions. |
| `void MulNumber(const double num)` | Multiplies matrix by a number. |  |
| `void MulMatrix(const S21Matrix& other)` | Multiplies by another matrix. | Incompatible matrix dimensions. |
| `S21Matrix Transpose()` | Creates transposed matrix. |  |
| `S21Matrix CalcComplements()` | Calculates algebraic addition matrix. | Matrix not square. |
| `double Determinant()` | Calculates determinant. | Matrix not square. |
| `S21Matrix InverseMatrix()` | Calculates inverse matrix. | Determinant is 0. |

## Constructors and destructors
Methods:

- `S21Matrix()`: Default constructor.
- `S21Matrix(int rows, int cols)`: Parametrized constructor.
- `S21Matrix(const S21Matrix& other)`: Copy constructor.
- `S21Matrix(S21Matrix&& other)`: Move constructor.
- `~S21Matrix()`: Destructor.

## Operator overloading
Operators to be overloaded:

| Operator | Description | Exceptional situations |
| -------- | ----------- | ---------------------- |
| `+`      | Addition of matrices. | Different dimensions. |
| `-`      | Subtraction of matrices. | Different dimensions. |
| `*`      | Matrix multiplication or multiplication by number. | Incompatible dimensions. |
| `==`     | Checks for equality. |  |
| `=`      | Assignment of values. |  |
| `+=`     | Addition assignment. | Different dimensions. |
| `-=`     | Subtraction assignment. | Different dimensions. |
| `*=`     | Multiplication assignment. | Incompatible dimensions. |
| `(int i, int j)` | Indexation by matrix elements. | Index out of bounds. |

## Chapter II

### Part 1. Implementation of the s21_matrix_oop.h library functions
- Developed in C++17 standard using gcc compiler;
- Code located in src folder;
- Follow Google style guide;
- Implement S21Matrix class with specified operations;
- Use `matrix_`, `rows_`, and `cols_` fields as private;
- Implement accessor and mutator for private fields;
- Implement as static library (with s21_matrix_oop.h header file);
- Overload operators as specified;
- Ensure full coverage of library functions with GTest unit-tests;
- Provide Makefile for building library and tests (with targets all, clean, test, s21_matrix_oop.a).
