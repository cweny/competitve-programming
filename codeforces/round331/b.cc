#include<iostream>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;


int main(void) {
  int n; cin>>n;
  vector<ll> v(n);
  for(int i=0; i<n; i++) {
	ll t;cin>>t;
	v[i]=t;
	
  }
  ll curr=v[0];
  ll ans=abs(v[0]);
  for(int i=1; i<n; i++) {
	ans += abs(v[i]-curr);
	curr = v[i];
  }
  cout << ans << endl;
}