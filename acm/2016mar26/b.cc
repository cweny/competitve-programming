#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>

#define pii pair<int,int>
using namespace std;

int n,m;
vector<int> g[10005];
map<pii,int> id;
map<pii,int> vert_count;
vector<pii> res;

bool visited[10005];
int disc[10005];
int low[10005];
int parent[10005];

void bridgeUtil(int u)
{
    static int time = 0;
 
    // Mark the current node as visited
    visited[u] = true;
 
    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;
 
    // Go through all vertices aadjacent to this
    for (int v:g[u])
    {
        
 
        // If v is not visited yet, then recur for it
        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v);
 
            // Check if the subtree rooted with v has a 
            // connection to one of the ancestors of u
            low[u]  = min(low[u], low[v]);
 
            // If the lowest vertex reachable from subtree 
            // under v is  below u in DFS tree, then u-v 
            // is a bridge
            if (low[v] > disc[u])
              res.push_back({u,v});
        }
 
        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
 
// DFS based function to find all bridges. It uses recursive 
// function bridgeUtil()
void bridge()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = 0;
        visited[i] = false;
        disc[i] = 0;
        low[i] = 0;
    }
 
    // Call the recursive helper function to find Bridges
    // in DFS tree rooted with vertex 'i'
    for (int i = 1; i <= n; i++)
        if (visited[i] == false)
            bridgeUtil(i);
}

int main(void) {
    freopen("bridges.in","r",stdin);
    freopen("bridges.out","w",stdout);
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v; cin >> u >> v;
        int a,b; a=min(u,v); b=max(u,v);
        vert_count[{a,b}]++;
        if(id.find({a,b}) == id.end()) {
            id[{a,b}] = i+1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    bridge();
    // for(auto x: id) {
    //     cout << x.second << "  " << x.first.first << " " <<x.first.second << vert_count[{x.first.first,x.first.second}]<< endl;
    // }
    vector<int> idres;
    for(auto x:res) {
        int a,b;
        a=min(x.first, x.second);
        b=max(x.first, x.second);
        if(vert_count[{a,b}] <= 1) {
            idres.push_back(id[{a,b}]);
        }
    }
    sort(idres.begin(), idres.end());
    
    cout << idres.size() << endl;
    for(int x:idres) {
        cout << x << " ";
    }
    return 0;
}