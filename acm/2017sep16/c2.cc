#include<iostream>

using namespace std;

int arr[500][500], adj[500][500], dist[500][500];
// vector<int> adj[500];
int n,V;
void fw() {
    int i,j,k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = arr[i][j];
 
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

int main() {
    cin >> n;
    V=n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    fw();
    //  for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout << dist[i][j] << " ";
    //     } cout << endl;
    // }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           if(arr[i][j] != dist[i][j]) {
               cout << -1 << endl;
               return 0;
           }  
        } 
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cout << arr[i][j] << " ";
        } cout << endl;
    }
}