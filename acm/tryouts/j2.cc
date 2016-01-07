#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>

using namespace std;
void trim(string &s) {
    for(unsigned i=0; i<s.size();i++) {
        if(s[i]==' ')
            s.erase(i,1);
    }
}
map<string,int> m;
map<int,string> _m;
bool edges[2000][2000];
bool vis[2000];

vector<int> path;

bool dfs(int start, int end, int n) {
    if(start==end) return true;
    vis[start]=true;
    for(int i=0;i<n;i++) {
        if(vis[i]==false && edges[start][i]) {
            if(dfs(i,end,n)) {
                path.push_back(i);
                return true;
            }
        }
    }
    //vis[start]=false;
    return false;
}

int main(void) {
    m.clear();_m.clear();path.clear();
    int T; cin >> T;
    int count=0;
    for(int i=0;i<2000;i++) {
        vis[i]=false;
        for(int j=0;j<2000;j++) {
            edges[i][j]=false;
        }
    }
    string temp;
    getline(cin,temp);
    while(T--) {
        string str;
        getline(cin, str);
        stringstream ss; ss << str;
        string first; ss>>first;
        if(m.find(first)==m.end())  {
            _m[count]=first;
            m[first]=count++;
        }
        while(ss>>str) {
            if(m.find(str)==m.end())  {
                _m[count]=str;
                m[str]=count++;
            }
            edges[m[first]][m[str]]=true;
            edges[m[str]][m[first]]=true;
        }
    }
    string start,end; cin>>start>>end; 
    
    if(dfs(m[start],m[end],count)) {
        cout << start << " ";
        for(int i=path.size()-1;i>=0;i--) {
            cout << _m[path[i]];
            if(i>0) cout << " ";
        }
        
    } else {
        cout << "no route found";
    }
    cout << endl;
    return 0;
}