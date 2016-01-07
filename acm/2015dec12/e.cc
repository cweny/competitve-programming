#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main(void) {
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int ans = 100000000;
    for(int i=0; i<n/2; i++) {
        ans = min(ans, arr[i]+arr[n-1-i]);
    }
    cout << ans << endl;
}