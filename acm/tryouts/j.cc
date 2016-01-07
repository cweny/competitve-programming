#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>

using namespace std;

map<string, vector<string> > m;
set<string> vis;
vector<string> path;
bool dfs(string start, string end) {
  //return false;
  if(start.compare(end)==0) return true;
  vis.insert(start);
  for(unsigned i=0;i<m[start].size();i++) {
	if(vis.find(m[start][i])==vis.end() ) {
	  if(dfs(m[start][i],end)) {
		path.push_back(m[start][i]);
		return true;
	  }
	}
  }
  return false;
}

int main(void) {
  int t;cin>>t;
  while(t--) {
	string s,line,str; cin>>s;
	getline(cin,line);
	//cout << s << endl;
	/*
	cout << "---------------" <<endl;
	cout << "start: " << s << endl;
	*/
	stringstream ss; ss<<line;
		while(ss>>str) {
		  //cout << "processing: " << str<< endl;
		 
		  m[s].push_back(str);
		  m[str].push_back(s);
		  /*
		   cout << "elements in" << s << ": ";
		  for(string l:m[s]) {
		  	cout << l << " ";
		  } cout << endl;
		  cout << "elements in" << str<< ": ";
		  for(string l:m[str]) {
		  	cout << l << " ";
		  } cout << endl;
		  cout << endl << endl;
		  */
		}
  }
  
  
  string start,end; cin>>start>>end;
  if(dfs(start,end)) {
  	cout << start << " ";
		for(int i=path.size()-1;i>=0;i--) {
		  cout << path[i] << " ";
		}
  } else {
		cout << "no route found";
  } cout << endl;
 // vis.insert("asdf");
  //if(vis.find("asdf")==vis.end()) cout << "not found" << endl;
  return 0;
}
