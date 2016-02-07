#include<iostream>
#include<string>

using namespace std;

long long n,k,ans,p1,p2;
string s;
int arr[1000005];
long long summ(long long x) {
    x++;
    if(x%2==0) {
        return (x/2)*(x-1);
    } else {
        return ((x-1)/2)*x;
    }
}
int main (void) {
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> s;
        ans = 0;
        int count = 0;
        for(int i=0; i<n; i++)
            if(s[i] == '1')
                count++;
        if(count < k) {
            cout << ans << endl;
            continue;
        }
        
        int n2 = 1;
        arr[0] = -1;
        for(int i=0; i<n; i++) {
            if(s[i] == '1') {
                arr[n2++] = i;
            }
        }
        arr[n2] = n;
        n2++;
        if(k==0) {
            // cout << n2 << endl;
            if(n2==2) {
                // cout << "0" << endl;
                cout << summ(n) << endl;
            } else {
                for(int i=1; i<n2-1; i++) {
                    ans += summ(arr[i]-arr[i-1]-1);
                }
                ans += summ(arr[n2-1]-arr[n2-2]-1);
                // cout << "1" << endl;
                cout << ans << endl;
            }
            continue;
        }
        // for(int i=0; i<n2; i++) {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;
        p1=1;
        p2=p1+k-1;
        for( ; p2<n2-1; p2++,p1++ ) {
            ans += (arr[p1] - arr[p1-1]) * (arr[p2+1]-arr[p2]);
        }
        cout << ans << endl;
        
    }
    return 0;
}