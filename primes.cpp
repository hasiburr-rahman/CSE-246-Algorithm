#include <bits/stdc++.h>
using namespace std;

void prim(int start);

#define MAX 100
#define INF 9999
int adj[MAX][MAX];
int parent[MAX];
int key[MAX];
bool visited[MAX];
int n;

int main(){
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter Adjacecy Matrix (O for no edge)";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> adj[i][j];
        }
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;
    

    prim(start);

    cout << "\nMST edges:\n";
    int totalCost = 0;

    for(int i=0; i<n; i++){
        if(parent[i] != -1){
            cout << parent[i] << " - " << i << " : " << adj[i][parent[i]];
            totalCost+=adj[i][parent[i]];
        }
    }

    cout << "\nTotal Cost - " << totalCost << endl;
}


void prim(int start){
    for(int i=0; i<n; i++){
        key[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }

    key[start] = 0;
    parent[start] = -1;

    for(int count=0; count < n-1; count++){

        int min = INF, u;
        
        for(int v=0; v<n; v++){
            if(!visited[v] && key[v] < min){
                min = key[v];
                u = v;
            }
        }

        visited[u] = true;

        for(int v=0; v<n; v++){
            if(adj[u][v] && !visited[v] && adj[u][v] < key[v]){
                parent[v] = u;
                key[v] = adj[u][v];
            }
        }
    }
}