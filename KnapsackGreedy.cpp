#include<bits/stdc++.h>
using namespace std;

void Sort(double w[], double v[], double avg[], int n);
void Knapsack(double w[], double v[], double avg[], int n, double size);

int main() {
    int n;
    cout <<"Enter Number of items - ?" << endl;
    cin>> n;

    double weight[n], value[n], avg[n];

    cout << "Enter weights m- " << endl;
    for(int i=0; i<n; i++){
        cout << i+1 << " - ";
        cin >> weight[i];
    }

    cout <<"Enter the values m- " << endl;
    for(int i=0; i<n; i++){
        cout << i+1 << " - ";
        cin >> value[i];
    }

    for(int i=0; i<n; i++){
        avg[i] = value[i]/weight[i];
    }

    Sort(weight, value, avg, n);

    double size;
    cout << "Enter the Size - ";
    cin >> size;

    Knapsack(weight, value, avg, n, size);

    return 0;
}

void Sort(double w[], double v[], double avg[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(avg[j] < avg[j+1]){
                swap(avg[j], avg[j+1]);
                swap(w[j], w[j+1]);
                swap(v[j], v[j+1]);
            }
        }
    }
}

void Knapsack(double w[], double v[], double avg[], int n, double size){
    double benefit = 0;
    double filled = 0;

    for(int i=0; i<n && filled<size; i++){
        double take = min(w[i], size-filled);
        benefit += take*avg[i];
        filled += take;
    }

    cout << "Maximum benefit - " << benefit << endl;

}