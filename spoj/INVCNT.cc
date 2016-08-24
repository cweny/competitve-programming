#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int arr[200000],n;
long long ans;

void recur(int a, int b) {
    if(a==b) return;
    int mid = (a+b)/2;
    recur(a,mid);
    recur(mid+1,b);
    int p = a, p2 = mid+1;
    
    vector<int> vec;
    
    while(p<=mid && p2<=b) {
        if(arr[p] <= arr[p2]) {
            vec.push_back(arr[p]);
            p++;
        } else {
            ans = ans + (mid-p+1);
            vec.push_back(arr[p2]);
            p2++;
        }
    }
    
    while(p<=mid) {
        vec.push_back(arr[p]);
        p++;
    }
    
    while(p2<=b) {
        vec.push_back(arr[p2]);
        p2++;
    }
    
    for(int i=a; i<=b; i++) {
        arr[i] = vec[i-a];
    }
    
}

int main(void) {
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        ans=0;
        recur(0,n-1);
        cout << ans << endl;
    }
    return 0;
}