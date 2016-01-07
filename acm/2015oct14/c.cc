#include<iostream>
#include<map>
#include<string>
#include<cmath>

#define ll long long
#define ld long double

using namespace std;
struct coord {
    ll x,y,z;
};

int V;
map<string,int> id;
map<int,string> rid;
ld fw[65][65];
ld g[65][65];
coord pos[65];
ld dist(int i, int j) {
    ll dx=pos[i].x-pos[j].x;
    ll dy=pos[i].y-pos[j].y;
    ll dz=pos[i].z-pos[j].z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}
void fwarshall() {
    int i, j, k;
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            fw[i][j] = g[i][j];
 
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (fw[i][k] + fw[k][j] < fw[i][j])
                    fw[i][j] = fw[i][k] + fw[k][j];
            }
        }
    }
}
int main(void) {
    int T;cin>>T;int ca=0;
    while(T--) {
        
        cerr << endl<< "Case " << ++ca << ":" << endl;
        cout <<"Case " << ca << ":" << endl;
        cin>>V;
        id.clear(); rid.clear();
        for( int i=0; i<V; i++ ) {
            string str; cin>>str;
            ll x,y,z; cin>>x>>y>>z;
            id[str]=i;
            rid[i]=str;
            pos[i].x=x; pos[i].y=y; pos[i].z=z;
        }
        
        for( int i=0; i<V; i++)
            for( int j=0; j<V; j++ )
                g[i][j] = dist(i,j);
        
        
        for( int i=0; i<V; i++) {
            for( int j=0; j<V; j++ )
                cerr << g[i][j] << " ";
            cerr << endl;
        }
        
        
        int w; cin>>w;
        for( int i=0; i<w; i++ ) {
            
            string from,to; cin>>from>>to;
            cerr << "clearing " <<from<<" to " << to << endl;
            g[id[from]][id[to]]=0;
        }
        
        cerr << endl;
        for( int i=0; i<V; i++) {
            for( int j=0; j<V; j++ )
                cerr << g[i][j] << " ";
            cerr << endl;
        }
        
        
        fwarshall();
        
        int q; cin>>q;
        for( int i=0;i<q;i++ ) {
            string from,to; cin>>from>>to;
            cout << "The distance from " << from << " to " << to << " is " << int(fw[id[from]][id[to]]+0.5) << " parsecs." << endl;
        }
    }
}