
#include <iostream>
#include <algorithm>
#include<time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int N, M, i, j;
    cout << "Enter n: ";
    cin >> N;
    cout << "\nEnter m: ";
    cin >> M;
    int** arr = NULL;

    arr = new int* [N];
    
    for (i = 0; i < N; ++i)
        arr[i] = new int[M];
    
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < M; ++j)
        {
            arr[i][j] = rand() % 20;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {

        reverse(arr[i], arr[i] + M);
    }

    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < M; ++j)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    for (i = 0; i < N; ++i)
        delete[] arr[i];

    delete[] arr;

    return 0;
}