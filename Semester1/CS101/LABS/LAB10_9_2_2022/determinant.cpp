#include <iostream>
using namespace std;

void Cofactor(long long A[][5], long long temp[][5], int r, int c, int n)
{
    int a = 0;
    int b = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i != r && j != c)
            {
                temp[a][b] = A[i][j];
                b = b + 1;

                if (b == n)
                {
                    b = 0;
                    a = a + 1;
                }
            }
        }
    }
}

long long Determinant(long long A[][5], int N) // Always Specify Number of Columns.
{                                              // While calculating Determinant for matrices of order nXn , where n>2, we can't directly calculate determinants, we
                                               // We Need to Calculate CoFactors,(Smaller,n-1Xn-1 matrices).this n-1Xn-1 matrcies will need a temp MAtrix, where we can store it's contents.
                                               // We will then use this temp matrix and recursively call it to find Determinant.
    long long Det = 0;
    long long temp[5][5];

    if (N == 1)
    {
        return A[0][0];
    }
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            Cofactor(A, temp, 0, i, N - 1);
            Det = Det + A[0][i] * (Determinant(temp, N - 1));
        }
        else
        {
            Cofactor(A, temp, 0, i, N - 1);
            Det = Det - A[0][i] * (Determinant(temp, N - 1));
        }
    }

    return (Det);
}

int main()
{

    int n;
    cin >> n;

    long long arr[5][5];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << Determinant(arr, n) << endl;
}