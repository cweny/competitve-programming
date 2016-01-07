#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
int p[100000], pr=31;
//string memo[1<<16], 
string strings[20];
unordered_map<string,string> memo;
bool seen[1<<16];
int n;

//a.size()<=b.size()
string get_min(string a, string b) {
  //if(b.find(a,0) != string::npos) {
    //return b;
  //}
  string m = a + b;
  if(m.compare(b+a) > 0)
    m = b+a;
  int sz = a.size();
  for(int i=1; i<sz; i++) {
    string f = a.substr(0,i);
    string s = b.substr(b.size()-i);
    string tmp;
    if(f==s ) {
      tmp = b.substr(0,b.size()-i) + s + a.substr(i);
      if(tmp.size() < m.size() || (m.compare( tmp )>0 && tmp.size() == m.size())) {
	m = tmp ;
      }
    }

    f = a.substr(i);
    s = b.substr(0, f.size());
    if(f==s) {
      tmp = a.substr(0,i) + s + b.substr(s.size());
      if(tmp.size() < m.size() || (m.compare( tmp )>0 && tmp.size() == m.size())) {
	m = tmp ;
      }
    }
  }
  
  return m;
}

string get_min2( string a, string b ) {
  vector<ll> hasha(a.size()+5), hashb(a.size()+5);
  
  for(unsigned i=0; i<a.size(); i++) {
    hasha[i+1] = pr * hasha[i] + a[i];
  }
  for(unsigned i=0; i<b.size(); i++) {
    hashb[i+1] = pr * hashb[i] + b[i];
  }
  
  for(unsigned i=0; i<a.size(); i++) {
    
  }
  
  return "";
}

string dp(string bm) {
  if(memo.count(bm) > 0) return memo[bm];
  string m = "";
  for(int i=0; i<n; i++) {
    if(bm[i]=='1') {
      bm[i] = '0';
      string tmp = dp(bm);
      bm[i] = '1';
      
      if(tmp.size() < strings[i].size()) {
	m=get_min(tmp,strings[i]);
      } else {
	m=get_min(strings[i],tmp);
      }
    }
  }
  memo[bm] = m;
  return memo[bm];
}

int main(void) {
  ios_base::sync_with_stdio(0);
  p[0] = 1;
  for(int i=1; i<100000; i++) {
    p[i] = p[i-1]*pr;
  }
  bool flag = false;
  int t,ca=0; cin >> t;
  while(t--) {
    
    memo.clear();
    cin >> n;
    string tmp = "";
    for(int i=0; i<n; i++) {
      string str; cin >> str;
      strings[i] = str;
      tmp += "1";
    }

    
    if(flag)
        cout << "\n";
    flag = true;
    cout << "Scenario #" << ++ca << ":" << endl;
    cout << dp(tmp) << endl;
    // for(auto elem : memo) {
    //   cout << elem.first << " " << elem.second << endl;
    // }
  }
  return 0;
}
