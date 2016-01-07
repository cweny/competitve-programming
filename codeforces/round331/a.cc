#include<iostream>
#include<algorithm>
#include<utility>
#include<cmath>
#define ll long long
#define pii pair<ll,ll>


using namespace std;
ll dist2(pii a, pii b) {
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
int main(void) {
  int n; cin>> n;
  
  vector<pii> v;
  for(int i=0; i<n; i++) {
	int x,y; cin>>x>>y;
	pii t; t.first=x; t.second=y;
	v.push_back(t);
  }
  if(n<=1) {
	cout << -1 << endl;
	return 0;
  }
  if(n==2) {
		// cout <<  ((v[0].first-v[1].first)*(v[0].first-v[1].first)+(v[0].second-v[1].second)*(v[0].second-v[1].second))/2.0<< endl;
		// return 0;
		if(v[0].first==v[1].first || v[1].second==v[0].second) {
		  cout<<-1<<endl;
		  return 0;
		} else {
		  int ans=abs(v[0].first-v[1].first)*abs(v[0].second-v[1].second);
		  cout<<ans<<endl;
		  return 0;
		}
  }
  if(n>=3) {
		pii a=v[0], b=v[1], c=v[2];
		if(dist2(a,b)+dist2(a,c) == dist2(c,b)) {
				cout << (int)sqrt( dist2(c,a)*dist2(a,b) ) << endl;
		} else if(dist2(b,a)+dist2(b,c) == dist2(a,c)) {
			cout << (int)sqrt( dist2(b,a)*dist2(c,b) ) << endl;
		} else if(dist2(c,a)+dist2(c,b) == dist2(a,b)) {
			cout << (int)sqrt( dist2(c,a)*dist2(c,b) ) << endl;
		} else {
			cout << -1 << endl;
		}
		return 0;
  }
  cout << abs(v[0].first-v[3].first)*abs(v[0].second-v[3].second) << endl;
}