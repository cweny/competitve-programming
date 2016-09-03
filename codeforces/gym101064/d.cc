#include<iostream>
#include<algorithm>

#define int long long

using namespace std;


int n,k,arr[100005];

int find(int idx, int x) {
    if(idx+1>=n) {
        return 0;
    }
    int l=idx+1, r=n-1, mid = (l+r)/2, ans=0;
    // cout << "find " << idx << " " << x << endl;
    while(l<=r) {
        mid = (l+r)/2;
        // cout <<mid<< " "<< arr[idx] + arr[mid] << " " <<l << " " << r << endl;
        if(arr[idx]+ arr[mid]<= x) {
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    // cout << "ret " << ans-idx << endl;
    return (ans-idx)<0?0:(ans-idx);
}

bool ok(int x) {
    
    int cnt=0;
    for(int i=0; i<n; i++) {
        cnt += find(i,x);
        // cout << "find " << find(i,x) << endl;
    }
    // cout << "return " << cnt << endl;
    return cnt >= k;
}


#undef int
int main(void) {
#define int long long
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int l=arr[0]+arr[1],r=arr[n-2]+arr[n-1],mid=(l+r/2),ans=l;
    while(l<=r) {
        mid=(l+r)/2;
        // cout << mid << " ";
        if(ok(mid)) {
            // cout << mid ;
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
            
        }
        // cout << endl;
    }
    // cout << ok(6) << endl;
    // cout << find(2,6) << endl;
    cout <<  ans << endl;
    return 0;
}