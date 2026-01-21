#include <bits/stdc++.h>
using namespace std;

int quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int a[], int i, int j);


int main(){
    int A[] = {5,3,8,4,6};
    int n = sizeof(A) / sizeof(A[0]);

    quicksort(A, 0, n-1);
    cout << "Sorted Array" << endl;
    for(int i=0; i<n; i++){
        cout << A[i] << endl;
    }

    return 0;
}

int quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high){

    int pi = low;
    int pivot = arr[pi];

    int too_big = low+1;
    int too_small = high;

    while (too_small > too_big) {
        while(too_big <= high && arr[too_big] <= pivot){
            too_big++;
        }
        while (too_small >= low && arr[too_small] > pivot){
        too_small--;
        }

        if(too_big < too_small){
        swap(arr, too_big, too_small);
        }



    }
     swap(arr, pi, too_small);
    return too_small;


 }

 void swap(int a[], int i, int j){
    int temp = a[i];
    a[i]= a[j];
    a[j] = temp;
}

