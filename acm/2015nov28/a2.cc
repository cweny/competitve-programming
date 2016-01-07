#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#define ll long long

using namespace std;

const int infinity = 10000000;
int n;
int cost[16][16];
ll memo[1<<16][16];
string strings[16];
string path[16][16];

int compute_cost(string a, string b, int i, int j) {
  int ans = infinity;
  int blen=b.size();
  for (int i=1; i<min(blen,(int)a.size()); i++) {
    string f = a.substr(a.size()-i);
    string s = b.substr(0,i);
    if(s == f)
      ans = min(ans,blen-i);
  }
  //check this
  path[i][j] = a.substr(b.size()-ans);
  return ans;
}


ll dp(int mask, int prev ){
  if (mask == 0) return 0;
  if (memo[mask][prev] != -1) return memo[mask][prev];
  ll res = infinity;
  for (int i = 1; i <=n; i++) {
    if ((mask & (1<<i)) ==0) continue;
    //    cout << cost[prev][i] << " " << prev << " " <<  i<<endl;
    res = min(res, (cost[prev][i] + dp((mask - (1<<i)), i)));
    if ( 
  }
  memo[mask][prev] = res;
  return res;
}



int main() {
  int t; cin >> t;
  while(t--) {
    cin >> n;
    strings[0]="";
    for(int i=1; i<=n; i++) {
      cin >> strings[i];
    }
    memset(memo,-1, sizeof memo);
    for (int i=1; i<=n; i++) {
      //cost[0][i]=strings[i].size();
      cost[0][i]=0;
    }
    for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {
	cost[i][j] = compute_cost(strings[i], strings[j],i , j);
	cost[j][i] = compute_cost(strings[j], strings[i], j, i);
	//	cout << cost[i][j] << " " << cost[j][i] << endl;
      }
    }
  
    cout << dp((1<<(n+1)) - 2, 0) << endl;
  }
}

