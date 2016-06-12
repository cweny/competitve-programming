#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>

#define ll long long
using namespace std;

const ll inf = 100000000000;
ll arr[200000], n;
ll ans = inf, idx;

map<ll,ll> um;

void recur(int s, int e) {
    ll sz = e-s+1;
    if(sz == 1) {
        if(arr[e] == 0 && ans > 1) {
            ans = 1;
            idx = e;
        }
        return;
    }
    
    ll mid = (s+e)/2;
    um.clear();
    ll sum = 0;
    for(int i=mid; i>=s; i--) {
        sum+=arr[i];
        if(um.find(sum) == um.end()) {
           um[sum] = i;
        }
    }
    sum = 0;
    for(int i=mid+1; i<=e; i++) {
        sum += arr[i];
        
        if(um.find(-sum) != um.end()) {
            int p1 = um[-sum], p2 = i;
            if(ans > p2-p1+1) {
                ans = p2-p1+1;
                idx = p1;
            }
        }
    }
    
    recur(s,(s+e)/2);
    recur((s+e)/2+1,e);
}

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    recur(0,n-1);
    if(ans >= inf) {
        cout << -1 << endl;
    } else {
        cout << idx+1 << " " << ans << endl;
    }
    return 0;
}