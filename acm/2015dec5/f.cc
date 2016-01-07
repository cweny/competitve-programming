#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<algorithm>

#define pii pair<int,int>

using namespace std;

pii edges[201];
vector<int> graph[201];
//memo[i][j] longest path with parent i, exclude node j
int n,memo[201][201];

//depth of i, exclude j
int depth[201][201];

int getd(int node, int exc) {
    if(depth[node][exc] != -1) return depth[node][exc];
    
    int ans = 0;
    
    for(int e:graph[node]) {
        if(e==exc) continue;
        ans = max(ans, 1+getd(e,node));
    }
    
    return depth[node][exc] = ans;
}
int getdiam(int node, int exc)  {
    if(memo[node][exc] != -1) return memo[node][exc];
    int ans = 0;
    
    for(int e: graph[node]) {
        if(e==exc) continue;
        ans = max(ans, getdiam(e,node));
    }
    int maxd1=0, maxd2=0;
    
    for(int e:graph[node]) {
        if(e==exc) continue;
        int edepth = getd(e,node)+1;
        if(edepth>maxd1) {
            maxd2=maxd1;
            maxd1=edepth;
        } else if(edepth>maxd2) {
            maxd2=edepth;
        }
    }
    ans = max(ans, maxd1+maxd2);
    return memo[node][exc]=ans;
}



int main(void) {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges[i].first = u;
        edges[i].second = v;
    }
    memset(memo, -1, sizeof memo);
    memset(depth, -1, sizeof memo);
    
    int res=-1;
    
    for(int i=0; i<n-1; i++) {
        int u=edges[i].first, v=edges[i].second;
        res = max(res, getdiam(u,v)*getdiam(v,u));
    }
    cout << res << endl;
    return 0;
}