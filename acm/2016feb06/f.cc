#include<iostream>

#include<algorithm>


using namespace std;
int n,c;
int arr[100000];

bool ok(int m) {
    int cows = 1, prev = arr[0];
    for(int i=1; i<n; i++) {
        // cout << "prev" << prev << endl;
        if(arr[i]-prev >= m) {
            prev = arr[i];
            cows++;
        }
        
        if(cows >= c) return true;
    }
    return cows >= c;
}
int main (void) {
    
    int t; cin >> t;
    while(t--) {
       cin >> n >> c;
       for(int i=0; i<n; i++) {
           cin >> arr[i];
       }
       sort(arr,arr+n);
    //   for(int i=0; i<n; i++) cout << arr[i];
    //   cout << endl;
       int r = (arr[n-1] - arr[0] + 1)/(c-1) + 1;
       int l = 0;
       int m = r/2;
    //   cout << l << " " << m << " " << r << endl;
       while(r-l>=0) {
            // cout << "this is " << ok(m) << endl;
            if(ok(m))
                l=m+1;
            else
                r=m-1;
            m=(l+r)/2;
            // cout << "interval: " << l << " " << r << endl;
        }
        if(ok(m+1)) {
            m=m+1;
        }
        cout << m << endl;
    }
    return 0;
}