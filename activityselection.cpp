#include<bits/stdc++.h>
using namespace std;

void Sort(int start[], int finish[], int n);
void ActivitySelection(int start[], int finish[], int n);

int main(){

    int n;
    cout<<"Enter number of activities: ";
    cin>>n;

    int start[n], finish[n];

    cout<<"Enter start times:\n";
    for(int i=0;i<n;i++){
        cin>>start[i];
    }

    cout<<"Enter finish times:\n";
    for(int i=0;i<n;i++){
        cin>>finish[i];
    }

    Sort(start, finish, n);
    ActivitySelection(start, finish, n);

    return 0;
}

void Sort(int start[], int finish[], int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(finish[j] > finish[j+1]){
                swap(finish[j], finish[j+1]);
                swap(start[j], start[j+1]);
            }
        }
    }
}

void ActivitySelection(int start[], int finish[], int n){

    cout<<"\nSelected Activities:\n";

    int j = 0;
    cout<<"Activity "<<j+1<<" ("<<start[j]<<","<<finish[j]<<")"<<endl;

    for(int i=1;i<n;i++){
        if(start[i] >= finish[j]){
            cout<<"Activity "<<i+1<<" ("<<start[i]<<","<<finish[i]<<")"<<endl;
            j = i;
        }
    }
}
