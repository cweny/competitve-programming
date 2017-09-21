#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

#define int long long
#define inf 10000000000000 

using namespace std;


int arr[500][500], adj[500][500];
// vector<int> adj[500];
int n;

struct edge{
    int i,j,c;
    edge() {}
    edge(int i, int j, int c) : i(i), j(j), c(c) { }
};

bool comp(const edge &a, const edge &b) {
    return a.c < b.c;
}

int dist[500];
int parent[500];

struct cmp {
    bool operator()(const int& u, const int& v) {
        if ( dist[u] == dist[v] ) return u < v;
        else return dist[u] < dist[v];
    }
};
int dijkstra( int s , int d) {
    for ( int i=0; i<=n; i++ ) dist[i] = inf;
    for ( int i=0; i<=n; i++ ) parent[i] = -1;
    dist[s] = 0;
    set<int, cmp> q;
    q.insert(s);
    while ( !q.empty() ) {
        int v = *q.begin();
        q.erase(q.begin());
        for ( int u=0; u<n; u++ ) {
            if(adj[v][u] <= 0) continue;
        // for ( each edge e = (v, u) leaving v ) {
            int d = dist[v] + adj[v][u];
            if ( d < dist[u] ) {
                q.erase(u);
                dist[u] = d;
                q.insert(u);
                parent[u] = v;
            }
        }
    }
    return dist[d];
}

#undef int
int main() {
#define int long long
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<edge> vec;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            vec.push_back(edge(i,j,arr[i][j]));
        }
    }
    sort(vec.begin(), vec.end(), comp);
    for(edge e: vec) {
        if(e.c == 0) continue;
        int dij = dijkstra(e.i, e.j);
        if(dij > e.c) {
            if(adj[e.i][e.j] != 0) {
                cout << -1 << endl;
                return 0;
            }
            adj[e.i][e.j] = e.c;
        } else if(dij < e.c) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }
    
    // cout << dijkstra(0,1) << endl;
}