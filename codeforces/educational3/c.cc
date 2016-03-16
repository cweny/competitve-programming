#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int n, arr[(int)10e5];
int main(void) {
    cin >> n;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr,arr+n);
    ll mini = sum/n;
    int offset = sum%n;
    
    int i=0, j=n-1;
    ll ans = 0;
    
    // cout << mini << " " << offset << endl;
    while(i<j) {
        int jexpected = mini, iexpected = mini;
        if(n-j <= offset) {
            jexpected = mini+1;
        }
        
        if(n-i <= offset) {
            iexpected = mini + 1;
        }
        // cout << i << " " << j <<" " << jexpected << endl;
        if(arr[i] == iexpected) {
            i++;
            continue;
        }
        if(arr[j] == jexpected) {
            j--;
            continue;
        }
        ans += 1;
        arr[j]--;
        arr[i]++;
    }
    cout << ans << endl;
    return 0;
}