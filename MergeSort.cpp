#include <bits/stdc++.h>
using namespace std;

void Merge(int A[], int Left, int Center, int Right){

    int n1 = Center - Left + 1;
    int n2 = Right - Center;

    int L[n1+2];
    int R[n2+2];

    for(int i=1; i<=n1; i++){
        L[i] = A[Left+i-1];
    }

    for(int j=1; j<=n2; j++){
        R[j] = A[Center+j];
    }

    L[n1+1] = INT_MAX;
    R[n2+1] = INT_MAX;

    int i=1;
    int j=1;

    for(int k=Left; k<=Right; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(int A[], int Left, int Right)
{
    if (Left < Right)
    {
        int Center = (Left + Right) / 2;

        MergeSort(A, Left, Center);
        MergeSort(A, Center + 1, Right);

        Merge(A, Left, Center, Right);
    }
}

int main()
{
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    MergeSort(A, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}