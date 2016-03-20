#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;

struct data {
  ll x;
  ll isStart;
  ll popu;
};

vector<data> vec;

bool comp(const data &a, const data &b) {
    if(a.x == b.x) {
        if(a.isStart == 1) {
            return true;
        }
        return false;
    }
    return a.x < b.x;
}

int main(){
        int m;
    while(cin >>m){
        vec.clear();
    int cost; cin>> cost;
    for (int i = 0; i < m ; i++){
        int a,b,c;
        cin >> a >> b >> c;
        data d, d2;
        d.x = b;
        d.popu = a;
        d.isStart = 1;
        
        d2.x=c;
        d2.popu = a;
        d2.isStart = 0;
        
        vec.push_back(d);
        vec.push_back(d2);
    }
    
    sort(vec.begin(), vec.end(), comp);
    ll res =-1e9;
    ll prange = 0;
    ll popu = 0;
    ll currprof = 0;
    
    for(int i=0; i<vec.size(); i++) {
        ll at = vec[i].x;
        //int start_index = i;
        ll pas = 0;
        while(at==vec[i].x&& i<vec.size()) {
            
            if(vec[i].isStart == 1) {
                popu += vec[i].popu;
                currprof = popu * (vec[i].x-cost);
            } else {
                pas += vec[i].popu;
                currprof = popu * (vec[i].x-cost);
            }
            
            if(currprof >= res) {
                prange = vec[i].x;
                res = currprof;
            }
        
            i++;
        }
        popu -= pas;
        
        i--;
        // cout << "at range " << vec[i].x << ". population: " << popu << ". profit: " << res << endl;
        
    }
    
    cout << prange << endl;
    }
}