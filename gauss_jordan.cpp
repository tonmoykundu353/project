#include<bits/stdc++.h>
using namespace std;
/*
3
0 1 2
1 2 3
3 1 1
*/
void printMatrix(vector<vector<double>> matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}
vector<vector<double>> findInverse(vector<vector<double>> matrix)
{
    int n = matrix.size();
    vector<vector<double>> augmented(n, vector<double>(2 * n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            augmented[i][j] = matrix[i][j];
            augmented[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int pivot_row = i;
        for (int j = i + 1; j < n; j++)
        {
            if (abs(augmented[j][i]) > abs(augmented[pivot_row][i]))
            {
                pivot_row = j;
            }
        }
        swap(augmented[i], augmented[pivot_row]);

        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            augmented[i][j] /= pivot;
        }

        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                double factor = augmented[j][i];
                for (int k = 0; k < 2 * n; k++)
                {
                    augmented[j][k] -= factor * augmented[i][k];
                }
            }
        }
    }
    vector<vector<double>> inverse(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inverse[i][j] = augmented[i][j + n];
        }
    }
    return inverse;
}

int main()
{
    int n;
    cout << "Enter the size of the square matrix: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<vector<double>> inverse = findInverse(matrix);

    cout << "Inverse Matrix:" << endl;
    printMatrix(inverse);

    return 0;
}

