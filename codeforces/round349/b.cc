#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<ll> vec;
    ll M=-1;
    for(int i=0; i<n; i++) {
        ll x;
        cin >> x;
        vec.push_back(x);
        M= max(M,x);
    }
    ll t=M;
    for(ll x:vec) {
        if(x==M) continue;
        t-=x;
    }
    cout << t+1 << endl;
    return 0;
}