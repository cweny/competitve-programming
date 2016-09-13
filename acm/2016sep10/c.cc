#include<iostream>

#define ll long long

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Extended GCD
////////////////////////////////////////////////////////////////////////////////
// Find x,y such that ax + by = d = gcd(a,b)
// * a^-1 (mod m): if (egcd(a,m,x,y) == 1) return (x+m)%m; else ERROR;
ll egcd(ll a, ll b, ll& x, ll &y) {
  if (!b) {x = 1; y = 0; return a;}//to ensure d>=0: x=sgn(a);y=0;return abs(a);
  ll d = egcd(b, a%b, y, x); y -= x * (a/b); return d; 
    
}

////////////////////////////////////////////////////////////////////////////////
// Extended GCD in canonical form
////////////////////////////////////////////////////////////////////////////////
// Assuming a != 0, find smallest y >= 0 such that ax + by = c (if possible)
bool canon_egcd(ll a, ll b, ll c, ll& x, ll& y) {
  ll d = egcd(a, b, x, y), z = abs(a/d); if (c%d) return false;
  y = (y*(c/d)%z + z)%z, x = (c - b*y)/a; return true; }
  
int main(void) {
    int T; cin >> T;
    while(T--) {
        ll k,c; cin >> k >> c;
        ll x,y;
        if(canon_egcd(c,-k,1,x,y)) {
            cout << x << endl; 
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    
    return 0;
}