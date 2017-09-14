#include<iostream>
#include<string>
#include<set>
#include<utility>
#include<algorithm>
#include<map>

using namespace std;




int main(void) {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int idx=0, _idx=0;
        map<string, int> id,_id;
        map<int,string> rid, _rid;
        
        
        
        for(int i=0; i<n; i++) {
            
            string asdf; cin >> asdf;
            int j; cin >> j;
            vector<string> ss,_ss;
            for(int x=0; x<j; x++) {
                string s; cin >> s;
                ss.push_back(s);
            }
            int k; cin >> k;
            for(int x=0; x<k; x++) {
                string s; cin >> s;
                _ss.push_back(s);
            }
            vector<int> vec,_vec;
            
            for(string s:ss) {
                if(id.find(s) == id.end()) {
                    rid[idx] = s;
                    id[s] = idx++;
                }
                vec.push_back(id[s]);
            }
            for(string s:_ss) {
                if(_id.find(s) == _id.end()) {
                    _rid[_idx] = s;
                    _id[s] = _idx++;
                }
                _vec.push_back(_id[s]);
            }
            
            
            
            
            
            
            
            
        }
        
        for(auto x:_rid) {
            cout << x.first << " " << x.second << endl;
        }
    }
    
    
    return 0;
}