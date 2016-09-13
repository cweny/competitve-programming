#include<iostream>
#include<string>
#include<set>
#include<utility>
#include<algorithm>
#include<map>


#define pss pair<string, string>

using namespace std;



struct comp {
    bool operator() (const pss &a, const pss &b) const {
        if(a.first.compare(b.first) == 0) {
            return a.second.compare(b.second) < 0;
        }
        return a.first.compare(b.first) < 0;
    }
};


int main(void) {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        map<string,set<string>> m,_m;
        
        for(int i=0; i<n; i++) {
            string asdf; cin >> asdf;
            int j; cin >>j;
            vector<string> vec, _vec;
            for(int x=0; x<j; x++) {
                string s; cin >> s;
                vec.push_back(s);
            }
            int k; cin >> k;
            for(int x=0; x<k; x++) {
                string s; cin >> s;
                _vec.push_back(s);
            }
            
            
            for(string s:vec) {
                if(m.find(s) == m.end()) {
                    for(string ss:_vec) m[s].insert(ss);
                } else {
                    set<string> sstr;
                    for(string ss:_vec) {
                        if(m[s].find(ss) != m[s].end()) {
                            sstr.insert(ss);
                        }
                    }
                    m[s].swap(sstr);
                }
            }
            
            for(string s:_vec) {
                if(_m.find(s) == _m.end()) {
                    for(string ss:vec) _m[s].insert(ss);
                } else {
                    set<string> sstr;
                    for(string ss:vec) {
                        if(_m[s].find(ss) != _m[s].end()) {
                            sstr.insert(ss);
                        }
                    }
                    _m[s].swap(sstr);
                }
            }
        }
        set<pss, comp> ans,_ans;
        
        for(auto x:m) {
            for(auto y:x.second) {
                ans.insert({x.first,y});
            } 
        }
        
        for(auto x:_m) {
            for(auto y:x.second) {
                _ans.insert({y,x.first});
            } 
        }
        for(auto x:ans) {
            if(_ans.find(x) != _ans.end()) {
                cout << "(" << x.first << ", " << x.second << ")" << endl;
            }
        }
        cout << endl;
    }
    
    return 0;
}