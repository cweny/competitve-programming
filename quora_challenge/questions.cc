#include<iostream>
#include<vector>
#include<unordered_map>
#include<iomanip>

using namespace std;

int const inf = 100000000;
vector<int> graph[100001];
int n, cost[100001];
//relExpected[i]: relative expected value of node i, with node 1 as parent
//absExpected[i]: Expected value of starting at node i
double relExpected[100001], absExpected[100001];

void dfsRelExpected(int node, int parent) {
    int children = graph[node].size();
    if(parent>0) children--;
    double probability = 1.0/children;
    double res = cost[node];
    for(int v:graph[node]) {
        if(v==parent) continue;
        dfsRelExpected(v,node);
        res += probability*relExpected[v];
    }
    relExpected[node] = res;
}

void dfsAbsExpected(int node, int parent, int parentChildren) {
    int children = graph[node].size();
    double probability = 1.0/children;
    double res = cost[node];
    for(int v:graph[node]) {
        if(v == parent) {
            double tmp = parentChildren;
            if(parentChildren == 1) {
                res += probability*cost[parent];
            } else {
                res += probability*(  (absExpected[parent]-(relExpected[node]/tmp)-cost[parent])*(tmp/(tmp-1))+cost[parent]  );
            }
        } else {
            res += probability*relExpected[v];
        }
    }
    absExpected[node] = res;
    for(int v:graph[node]) {
        if(v!=parent) {
            dfsAbsExpected(v,node,children);
        }
    }
}

int main(void) {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> cost[i];
    }
    for(int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfsRelExpected(1,0);
    dfsAbsExpected(1,0,0);
    double ans = inf;
    int idx=0;
    for(int i=1; i<=n; i++) {
        double tmp = absExpected[i];
        if(tmp < ans) {
            ans = tmp;
            idx = i;
        }
    }
    cout << idx << endl;
    return 0;
}