#include<bits/stdc++.h>
using namespace std;

void BFS(int s);
void printPath(int s, int v);

#define MAX 100
int adj[MAX][MAX];
int color[MAX];
int d[MAX];
int parent[MAX];
int n;

int main() {
    int e;
    cout << "Enter the number of vertex: ";
    cin >> n;

    cout << "Enter the number of edge: ";
    cin >> e;

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            adj[i][j] = 0;

    for(int i=0; i<e; i++){
        int u, v;
        cout << "Enter connected nodes: ";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    BFS(start);

    cout << "\nVertex\tDist\tPrev\n";
    for(int i=0; i<n; i++){
        cout << i << "\t" << d[i] << "\t" << parent[i] << endl;
    }

    int destination;
    cout << "\nEnter destination vertex to show path from " << start << ": ";
    cin >> destination;

    if(destination >= 0 && destination < n){
        cout << "Shortest Path: ";
        printPath(start, destination);
        cout << endl;
    }
    else{
        cout << "Invalid destination." << endl;
    }

    return 0;
}

void BFS(int s){
    queue<int> Q;

    for(int i=0; i<n; i++){
        color[i] = 0;   // white
        d[i] = -1;      // infinity
        parent[i] = -1; // NIL
    }

    color[s] = 1; // gray
    d[s] = 0;
    Q.push(s);

    cout << "\nBFS Traversal Order: ";
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        cout << u << " ";

        for(int v=0; v<n; v++){
            if(adj[u][v] == 1 && color[v] == 0){
                color[v] = 1;
                d[v] = d[u]+1;
                parent[v] = u;
                Q.push(v);
            }
        }
        color[u] = 2; // black
    }
    cout << endl;
}

void printPath(int s, int v){
    if(v == s)
        cout << s << " ";
    else if(parent[v] == -1)
        cout << "No path from " << s << " to " << v << " exists.";
    else{
        printPath(s, parent[v]);
        cout << v << " ";
    }
}