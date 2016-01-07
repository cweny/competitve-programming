#include<iostream>

#define ll long long

using namespace std;


int main(void) {
    ll n; cin >> n;
    if(n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = (n-2)/2;
    
    if(n%4 == 0)
        ans--;
    cout << ans/2 << endl;
    
    return 0;
}