#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;

int x[100005];
int y[100005];
int arr[100000];


#undef int
int main(void) {
#define int long long
    int T; cin >> T;
    bool flag = false;
    while(T--) {
        if(flag) cout << endl;
        flag=true;
        memset(x,-1, sizeof x);
        int n,m; cin >> n >> m;
        for(int i=0; i<n; i++) {
            cin >>arr[i];
            if(x[arr[i]] == -1) {
                x[arr[i]]=i;
            }
            y[arr[i]]=i;
        }
        int ans = 0, prev;
        
        if(y[1]<x[2]) {
            ans += abs(x[1]-y[2]);
            prev = y[2];
        } else {
            ans += abs(y[1]-x[2]);
            prev = x[2];
        }
        
        for(int i=3; i<=m; i++) {
            // cout << x[i] << " " << y[i] << endl;
            if(abs(prev-x[i])>abs(prev-y[i])) {
                
                ans += abs(prev-x[i]);
                prev = x[i];
            } else {
                ans += abs(prev-y[i]);
                prev = y[i];
            }
        }
        if(m==1) {
            cout << 0;
        } else {
            cout << ans;
        }
    }
    
    return 0;
}