#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int memo[1<<20],g[25][25],n;
bool seen[1<<20];

void print(int x ) {
    string s;
    for(int i=0; i<n; i++) {
        if(x&1) {
            s = "1" + s;
        } else {
            s = "0" + s;
        }
        x = (x>>1);
    }
    cout << s << endl;
}

void dp(int bm) {
    if(seen[bm]) return;
    seen[bm] = true;
    for(int i=0; i<n; i++) {
        int nbm = bm | (1<<i);
        if(seen[nbm] || bm&(1<<i)) continue;
        int sum = 0;
        for(int j=0; j<n; j++) {
            
            if(bm & (1<<j)) continue;
            sum += g[i][j];
        }
        
        if(sum>0) {
            memo[nbm] = 1;
            dp(nbm);
        }
        
    }
}

int main(void) {
    int T; cin >> T;
    while(T--) {
        cin >> n;
        memset(memo, 0, sizeof memo);
        memset(seen, 0, sizeof seen);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> g[i][j];
            }
        }
        memo[0] = 1;
        dp(0);
        
        int mask = (1<<n)-1;
        bool flag = false;
        for(int i = 0; i<n; i++) {
            if(memo[(mask^(1<<i))] > 0) {
                flag = true;
                cout << i+1 << " ";
            }
        }
        if(flag) {
            cout << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}