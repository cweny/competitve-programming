#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<stdlib.h> 
#include<algorithm>

#define pii pair<int, int>

using namespace std;

char kb[3][10] = {
    {'q','w','e','r','t','y','u','i','o','p'},
    {'a','s','d','f','g','h','j','k','l','\0'},
    {'z','x','c','v','b','n','m','\0' , '\0', '\0'}
};

pii pos[500];

struct st{
    string str;
    int cost;
};
bool comp(st a, st b) { 
    if(a.cost == b.cost) {
        if(a.str.compare(b.str) < 0 || a.str.compare(b.str) == 0) {
            return true;
        }
        return false;
    }
    return a.cost < b.cost;
    
}
int main(void) {
    int T; cin >> T;
    
    while(T--) {
        string s; cin >> s;
        int n; cin >> n;
        vector<string> ss;
        for(int i=0; i<n; i++) {
            string x; cin >> x;
            ss.push_back(x);
        }
        
        for(int i=0; i<3; i++) {
            for(int j=0; j<10; j++) {
                if(kb[i][j] >= 'a' && kb[i][j] <= 'z') {
                    pos[ (int)kb[i][j] ] = {i,j};
                }
            }
        }
        
        vector<st> vans;
        
        for(string xx: ss) {
            int cost = 0;
            for(int i=0; i<xx.size(); i++) {
                cost += abs( pos[xx[i]].second - pos[s[i]].second ) + abs( pos[xx[i]].first - pos[s[i]].first );
            }
            st y; y.str = xx;
            y.cost = cost;
            vans.push_back(y);
        }
        sort(vans.begin(), vans.end(), comp);
        for(st x : vans) {
            cout << x.str << " " << x.cost << endl;
        }
    }
    
    return 0;
}