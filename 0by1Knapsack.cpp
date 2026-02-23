#include<bits/stdc++.h>
using namespace std;

void knapsack(int weights[], int values[], int n, int capacity);

int main() {
    int n;
    cout << "Enter number of elements : ";
    cin >> n;

    int weights[n];
    int values[n];

    cout << "Enter Weights - ";
    for(int i=0; i<n; i++){
        cin >> weights[i];
    }

    cout << "weights - ";
    for(int i=0; i<n; i++){
        cout << weights[i] << " ";
    }
    cout<<endl;

    cout << "Enter Values - ";
    for(int i=0; i<n; i++){
        cin >> values[i];
    }

    cout << "Values - ";
    for(int i=0; i<n; i++){
        cout << values[i] << " ";
    }
    cout<<endl;

    cout << "Enter the container size - ";
    int size;
    cin >> size;

    knapsack(weights, values, n, size);

    return 0;
}

void knapsack(int weights[], int values[], int n, int capacity){

    int table[n+1][capacity+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=capacity; j++){
            if(i==0 || j==0){
                table[i][j] = 0;
            } else if(weights[i-1] <= j){
                table[i][j] = max(values[i-1] + table[i-1][j-weights[i-1]], table[i-1][j]);
            } else {
                table[i][j] = table[i-1][j];
            }
        }
    }

    cout << "The Table - " << endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=capacity; j++){
            cout << table[i][j] <<" ";
        }
    }

    int res = table[n][capacity];
    cout << "Maximum value - " << res << endl;

    int z = capacity;
    cout << "Element used - " << endl;

    for(int i=n; i>0 && res>0; i--){
        if(res != table[i-1][z]){
            cout<<i<<" ";
            res -= values[i-1];
            z -= weights[i-1];
        }
    }
}
