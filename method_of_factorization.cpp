#include <iostream>
using namespace std;
#define MAX_SIZE 100

/*
3
2 3 1
1 2 3
3 1 2
*/
void printMatrix(double mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void luDecomposition(double A[MAX_SIZE][MAX_SIZE], double L[MAX_SIZE][MAX_SIZE], double U[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;

        for (int k = i; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }

        for (int k = i + 1; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L[k][j] * U[j][i];
            }
            L[k][i] = (A[k][i] - sum) / U[i][i];
        }
    }
}

int main() {
    int n;

    cout << "Enter the size of the square matrix: ";
    cin >> n;

    double A[MAX_SIZE][MAX_SIZE];
    double L[MAX_SIZE][MAX_SIZE] = {0};
    double U[MAX_SIZE][MAX_SIZE] = {0};

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    luDecomposition(A, L, U, n);

    cout << "Lower Triangular Matrix (L):" << endl;
    printMatrix(L, n);

    cout << "\nUpper Triangular Matrix (U):" << endl;
    printMatrix(U, n);

    return 0;
}


/*
Sure, here's a description of the C++ code that performs LU decomposition using 2D arrays:

1. **Constants and Headers**:
    - `const int MAX_SIZE = 100;`: This constant defines the maximum size for the square matrix and is used to declare the maximum dimensions of the 2D arrays.
    - `#include <iostream>`: This line includes the standard input/output stream header, which allows you to use functions like `cout` and `cin` for input and output.

2. **Function `printMatrix`**:
    - This function takes a 2D array `mat` and its size `n` as parameters.
    - It is used to print a 2D matrix to the console, formatted with tab separation.

3. **Function `luDecomposition`**:
    - This function performs the LU decomposition of a square matrix A into lower triangular matrix L and upper triangular matrix U.
    - It takes the following parameters:
        - `double A[MAX_SIZE][MAX_SIZE]`: The input square matrix.
        - `double L[MAX_SIZE][MAX_SIZE]`: The lower triangular matrix (initialized to all zeros).
        - `double U[MAX_SIZE][MAX_SIZE]`: The upper triangular matrix (initialized to all zeros).
        - `int n`: The size of the square matrix.
    - The function iterates through the rows of the matrix to calculate the L and U matrices.
    - Inside the loop:
        - It initializes the diagonal elements of L to 1.
        - It calculates the elements of U using Gaussian elimination.
        - It calculates the elements of L below the diagonal based on the U matrix.

4. **Main Function `main`**:
    - It starts by taking the size of the square matrix as input from the user.
    - It declares 2D arrays `A`, `L`, and `U` to hold the input matrix, lower triangular matrix, and upper triangular matrix, respectively.
    - It prompts the user to input the elements of the matrix.
    - It then calls the `luDecomposition` function to perform LU decomposition.
    - Finally, it prints the lower triangular matrix (L) and upper triangular matrix (U) to the console using the `printMatrix` function.

This program allows you to input a square matrix, performs LU decomposition, and displays the results in the form of the lower and upper triangular matrices.
*/
/*
#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void printMatrix(double mat[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void luDecomposition(double A[MAX_SIZE][MAX_SIZE], double L[MAX_SIZE][MAX_SIZE], double U[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;
        for (int k = i; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L[i][j] * U[j][k];
            }
            U[i][k] = A[i][k] - sum;
        }
        for (int k = i + 1; k < n; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L[k][j] * U[j][i];
            }
            L[k][i] = (A[k][i] - sum) / U[i][i];
        }
    }
}

void solveEquations(double L[MAX_SIZE][MAX_SIZE], double U[MAX_SIZE][MAX_SIZE], double b[MAX_SIZE], double x[MAX_SIZE], int n) {
    // Solve Ly = b for y (forward substitution)
    double y[MAX_SIZE] = {0};
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    // Solve Ux = y for x (backward substitution)
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += U[i][j] * x[j];
        }
        x[i] = (y[i] - sum) / U[i][i];
    }
}

int main() {
    int n;

    cout << "Enter the size of the square matrix: ";
    cin >> n;

    double A[MAX_SIZE][MAX_SIZE];
    double L[MAX_SIZE][MAX_SIZE] = {0};
    double U[MAX_SIZE][MAX_SIZE] = {0};
    double b[MAX_SIZE];
    double x[MAX_SIZE];

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter the right-hand side vector (b):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    luDecomposition(A, L, U, n);
    solveEquations(L, U, b, x, n);

    cout << "Solution vector (x):" << endl;
    for (int i = 0; i < n; i++) {
        cout << x[i] << "\t";
    }

    return 0;
}

*/
