#include<iostream>
#include<algorithm>

using namespace std;

int n,c,arr[100003];

bool ok(int x) {
    int prev = arr[0];
    int done = 1;
    // int at = 1;
    for(int i=1; i<n; i++) {
        if(arr[i]-prev >= x) {
            prev = arr[i];
            done++;
        }
    }
    return done >= c;
}

int bs() {
    int l=1,r=arr[n-1]-arr[0],mid=(l+r)/2;
    int ans = l;
    while(l<=r) {
        
        mid=(l+r)/2;
        // cout << "at " << mid << endl;
        if(ok(mid)) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    // for(int i=1; i<arr[n-1]-arr[0]; i++) {
    //     cout <<i<< " " << ok(i) << endl;
    // }
    return ans;
}

int main(void) {
    int T; cin >> T;
    while(T--) {
        cin >> n >> c;
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr,arr+n);
        
        cout << bs() << endl;
        
    }
    
    return 0;
}