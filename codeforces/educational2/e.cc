#include<iostream>
#include<vector>
#include<algorithm>
#include<map>


using namespace std;

int colors[100100], mx[100100], n;
long long sum[100100], ans[100100];
vector<int> g[100100];
map<int,int> colmap[100100];

void merge(int a, int b) {
    if(colmap[a].size() < colmap[b].size()) {
        swap(colmap[a],colmap[b]);
        int tmp = sum[a];
        sum[a] = sum[b];
        sum[b] = tmp;
        
        tmp = mx[a];
        mx[a] = mx[b];
        mx[b] = tmp;
    }
    for(auto x : colmap[b]) {
        int color = x.first;
        int nums = x.second;
        colmap[a][color] += nums;
        if(colmap[a][color] > mx[a]) {
            mx[a] = colmap[a][color];
            sum[a] = color;
        } else if (colmap[a][color] == mx[a]) {
            sum[a] += color;
        }
    }
}

void dfs(int node, int par) {
    for(int e:g[node]) {
        if(e != par) {
            dfs(e,node);
            merge(node,e);
            // colmap[e].clear();
        }
    }
    // colmap[node][colors[node]] += 1;
    // if (colmap[node][colors[node]] > mx[node]) {
    //     sum[node] = colors[node];
    //     mx[node]=colmap[node][colors[node]];
    // } else if (colmap[node][colors[node]] == mx[node] ) {
    //     sum[node] += colors[node];
    // }
    
    ans[node] = sum[node];
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> colors[i];
    }
    int u,v;
    for(int i=1; i<=n-1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        mx[i] = 1;
        sum[i] = colors[i];
        colmap[i][colors[i]] = 1;
    }
    dfs(1, -1);
    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }cout << endl;
    return 0;
}
