#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;


int main(void) {
    freopen("positive.in","r",stdin);
    freopen("positive.out","w",stdout);
    int n; cin >>n;
    int ans = 0;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        ans += x;
    }
    cout << max(0,ans) << endl;
    return 0;
}