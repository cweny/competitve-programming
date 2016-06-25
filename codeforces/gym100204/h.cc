#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define int long long
#define pii pair<int, int>
using namespace std;

int N,M,S;

struct subset {
    int p,r;
};
struct edge {
    int w,u,v,index;
    bool operator<(const edge& e) const{
        return w>e.w;
    }
};
subset n[50005];
vector< edge > edges;
int find(int x) {
    if(n[x].p!=x) {
        n[x].p=find(n[x].p);
    }
    return n[x].p;
}

void link(int u, int v) {
    if(n[u].r > n[v].r) {
        n[v].p=u;
    } else {
        n[u].p=v;
        if(n[u].r==n[v].r) {
            n[u].r++;
        }
    }
}
void sunion(int u, int v) {
    link(find(u),find(v));
}

#undef int
int main(void) {
#define int long long
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("oil.in", "r", stdin);
	freopen("oil.out", "w", stdout);
    int cash;
    cin >> N >> M >> cash;

    for(int i=0; i<M; i++ ){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({w,u,v,i+1});
    }
    sort(edges.begin(),edges.end());
    for(int i=0; i<=N; i++) {
        n[i].p=i;
        n[i].r=0;
    }
    
    int total=0;
    vector<edge> vec;
    for(edge e:edges) {
        if(find(e.u)!=find(e.v)) {
            total+=e.w;
            sunion(e.u,e.v);
        } else {
	    vec.push_back(e);
	}
    }
    int sz = vec.size();
    vector<int> vans;
    for(int i=sz-1; i>=0; i--) {
	if(cash < vec[i].w) break;
	cash -= vec[i].w;
	vans.push_back(vec[i].index);
    }
    sort(vans.begin(), vans.end());
    cout << vans.size() << endl;
    for( int x:vans ) {
	cout << x << " ";
    }cout << endl;
}
