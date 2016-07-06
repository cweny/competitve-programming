#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100005;
int n,m;

vector<int> adj[N], bucket[3];
int lab[N], dep[N], ans;

void init() {
    bucket[1].clear(); bucket[2].clear();
    for(int i=1; i<=n; i++) {
        dep[i]=0;
    }
    
    for(int i=1; i<=n; i++) {
        for(int x:adj[i]) {
            dep[x]++;
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(dep[i] == 0) {
            bucket[lab[i]].push_back(i);
        }
    }
}

void compute(int buck) {
    
    while(!bucket[buck].empty()) {
        int x = bucket[buck].back();
        bucket[buck].pop_back();
        for(int v: adj[x]) {
            dep[v]--;
            if(dep[v] == 0) {
                bucket[lab[v]].push_back(v);
            }
        }
    }
    
    int nex = buck == 1? 2:1;
    if(!bucket[nex].empty()) {
        ans++;
        compute(nex);
    }
}


int main(void) {
    int T; cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i=1; i<=n; i++) {
            adj[i].clear();
        }
        
        for(int i=1; i<=n; i++) cin >> lab[i];
        for(int i=0; i<m; i++) {
            int u,v; cin >> u >> v;
            adj[u].push_back(v);
        }
        ans = 0;
        init();
        compute(1);
        int tmp = ans;
        ans = 0;
        init();
        compute(2);
        cout << min(tmp, ans) << endl;
    }
    return 0;
}