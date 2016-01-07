#include<iostream>
#include<set>
#include<vector>
#include<iomanip>

using namespace std;

struct edge {
    int to;
    double cost;
};

vector<edge> graph[101];
int n,m;
double dist[101];

struct cmp {
    bool operator()(const int& u, const int& v) {
        if ( dist[u] == dist[v] ) return u > v;
        else return dist[u] > dist[v];
    }
};
void dijkstra( int s ) {
    for ( int i=0; i<=n; i++ ) dist[i] = -1;
    dist[s] = 1.0;
    set<int, cmp> q;
    q.insert(s);
    while ( !q.empty() ) {
        int v = *q.begin();
        q.erase(q.begin());
        for ( edge e : graph[v] ) {
            //cout << e.to << endl;
            int u = e.to;
            double d = dist[v] * e.cost;
            //cout << d << endl;
            if ( d > dist[u] ) {
                q.erase(u);
                dist[u] = d;
                q.insert(u);
                // parent[u] = v;
            }
        }
    }
}
int main(void) {
    while(cin >> n) {
        if(n==0) break;
        for(int i=0; i<=n; i++) {
            graph[i].clear();
        }
        cout << fixed << setprecision(6);
        cin >> m;
        for(int i=0; i<m; i++) {
            int u,v,p; cin >> u >> v >> p;
            graph[u].push_back({v,p/100.0});
            graph[v].push_back({u,p/100.0});
        }
        dijkstra(1);
        cout << dist[n]*100 << " percent" <<endl;
    }
    return 0;
}