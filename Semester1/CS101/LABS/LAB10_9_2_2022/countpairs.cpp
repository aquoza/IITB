#include <iostream>
using namespace std;

long countpairs(long long *arr, long long n, long long l, long long r)
{

    long long totpairs = 0;

    for (long long i = l; i <= r; i++)
    {
        long long ui = n - 1;
        long long rand = 0;
        for (long long li = 0; li <= ui; rand++)
        {
            if ((arr[li] + arr[ui] == i) && (li != ui))
            {
                totpairs = totpairs + 1;
                li = li + 1;
                ui = ui - 1;
            }
            else if (arr[li] + arr[ui] > i)
            {
                ui = ui - 1;
            }
            else
            {
                li = li + 1;
            }
        }
    }
    return totpairs;
}

int main()
{

    long long n;
    cin >> n;

    long long l, r;
    cin >> l;
    cin >> r;

    long long arr[n];

    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << countpairs(arr, n, l, r) << endl;
}