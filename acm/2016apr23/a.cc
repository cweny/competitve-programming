#include<iostream>
#include<unordered_set>
#include<vector>
#include<set>

#define ll long long

using namespace std;

unordered_set<ll> sq;
vector<ll> cubes;

int main(void) {
    for(int i=1; i<500; i++) {
        cubes.push_back(i*i*i);
    }
    for(int i=1; i<10005; i++) {
        sq.insert(i*i);
    }
    ll a,b; cin >> a >> b;
    ll ans = 0;
    for(ll x: cubes) {
        if(x>=a && x<=b) {
            if(sq.count(x) >0) {
                ans ++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}