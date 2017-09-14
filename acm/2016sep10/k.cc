#include<iostream>
#include<vector>

#define pii pair<int,int>

using namespace std;

// struct edge {
//     int cost, node;  
// };

int n,m,l,air;
vector<pii> adj[10000];
int ls[10];
int res[10][10000];

int main(void) {
    int T; cin >> T;
    
    while(T--) {
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            int u,v,c; cin >> u >> v >> c;
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        cin >> l;
        for(int i=0; i<l; i++) cin >> ls[i];
        cin >> air;
        
    }
    
    return 0;
} 