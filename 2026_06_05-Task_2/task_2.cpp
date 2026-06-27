#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void easy();
void medium();
void hard();

int main()
{
    easy(); // CHANGE THE FUNCTION NAME TO easy(), medium(), hard()
    return 0;
}

// EASY QUESTION : SORT THE MATRIX
void easy()
{
    int n;
    cout << "Enter matrix size: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    vector<int> arr;

    cout << "Enter matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
            arr.push_back(matrix[i][j]);
        }
    }

    sort(arr.begin(), arr.end());

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = arr[k++];
        }
    }

    cout << "\nSorted Matrix\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";

        cout << endl;
    }
}

// MEDIUM QUESTION : ROTATE THE MATRIX BY 180
void medium()
{
    int n;

    cout << "Enter matrix size: ";
    cin >> n;

    int matrix[100][100];
    int result[100][100];

    cout << "Enter matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[n - 1 - i][n - 1 - j] = matrix[i][j];
        }
    }

    cout << "\nRotated Matrix\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";

        cout << endl;
    }
}

// HARD QUESTION : FIND A SPECIFIC PAIR IN MATRIX
void hard()
{
    int n;

    cout << "Enter matrix size: ";
    cin >> n;

    int matrix[100][100];

    cout << "Enter matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    int maxDiff = INT_MIN;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = i + 1; k < n; k++)
            {
                for (int l = j + 1; l < n; l++)
                {
                    if (matrix[k][l] - matrix[i][j] > maxDiff)
                    {
                        maxDiff = matrix[k][l] - matrix[i][j];
                    }
                }
            }
        }
    }

    cout << "Maximum Difference = " << maxDiff << endl;
}
