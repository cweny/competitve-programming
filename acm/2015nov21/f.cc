#include<iostream>
#include<vector>
#include<cstring>
#include<string>

#define ll long long
using namespace std;

int n,k,total;
vector<ll> m[50005];
ll memo[50005][505];
bool seen[50005];

void dfs(int node, int par) {
  if(seen[node]) return;
  seen[node]=true;
  for(int e:m[node]) {
    if(e==par) continue;
    memo[node][1]++;
    dfs(e, node);
    for(int i=1; i<k; i++) {
      memo[node][i+1] += memo[e][i];
    }
  }
}

void dfsthrough(int node, int par) {
  if(seen[node]) return;
  seen[node]=true;
  for(int e:m[node]) {
    if(e==par) continue;
    dfsthrough(e, node);
  }
  ll tmp = 0;
  for(int e:m[node]) {
    if(e==par) continue;
    for(int x=1; x<k; x++) {
      tmp += memo[e][x-1] * (memo[node][k-x]-memo[e][k-x-1]);
    }
  }
  //cout << tmp << endl;
  total += tmp/2;
}

int main(void) {
  string s; cin >> s;
  cout << "sizeof string: " << s.size() << endl;
  int bal = 0;
  for(unsigned i=0; i<s.size(); i++) {
    if(s[i] == '4')
      bal--;
    else if(s[i] == '7')
      bal++;
    else
      cout << "error";
  }
  cout << "bal: " << bal << endl;
  return 0;
  cin >> n >> k;
  for( int i=0; i<n-1; i++) {
    int u,v; cin >> u >> v;
    m[u].push_back(v);
    m[v].push_back(u);
  }
  memset(memo, 0, sizeof memo);
  memset(seen, 0, sizeof seen);
  for(int i=1; i<=n; i++)
    memo[i][0]=1;
  dfs(1,-1);
  memset(seen, 0, sizeof seen);
  total=0;
  dfsthrough(1,-1);
  for(int i=1; i<=n; i++) {
    total += memo[i][k];
  }
  cout << total << endl;
  return 0;
}
