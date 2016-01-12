#include<iostream>
#include<unordered_map>
#include<algorithm>

#define ll long long
using namespace std;



struct point {
  ll x,y;  
};

unordered_map<ll,ll> m;
int n;
point arr[2000];

ll distance(point &a, point &b) {
    return (a.x-b.x)*(a.x-b.x) +  (a.y-b.y)*(a.y-b.y);
}

int main(void) {
    int t,ca=0; cin >> t;
    while(t--) {
        
        ll ans=0;
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i].x >> arr[i].y;
        }
        for(int i=0; i<n; i++) {
            m.clear();    
            for(int j=0; j<n; j++) {
                if(j==i) continue;
                m[distance(arr[i],arr[j])]++;
            }
            for(auto kv:m) {
                // cout << kv.second << endl;
                if(kv.second %2 == 0) {
                    ans += (kv.second/2)*(kv.second - 1);
                } else {
                    ans += ((kv.second-1)/2)*kv.second;
                }
            }
        }
        
        
        
        cout <<"Case #" << ++ca << ": "<< ans << endl;
    }
    return 0;
}