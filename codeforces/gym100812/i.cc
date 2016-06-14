#include<iostream>
#include<algorithm>
using namespace std;
#define int long long

int n,c,d;
int cost[1001][1001], t[1001], ps[1001], dp[1001];

#undef int
int main(void) {
#define int long long
    cin >> n >> d >> c;
    for(int i=0; i<n; i++) {
        cin >> t[i];
        ps[i] = t[i];
    }
    for(int i=1; i<n; i++) {
        ps[i] += ps[i-1];
        
    }
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if(i==0)
            cost[i][j] = (t[j]*(j-i+1)-(ps[j]))*c + d;
            else
            cost[i][j] = (t[j]*(j-i+1)-(ps[j]-ps[i-1]))*c + d;
        }
    }
    dp[n] = 0; dp[n-1] = d;
    for(int i=n-2; i>=0; i--) {
        int tmp = 1000000000000;
        for(int j=i; j<n; j++) {
            tmp = min(tmp, cost[i][j] + dp[j+1]);
        }
        dp[i] = tmp;
    }
    cout << dp[0] << endl;
    return 0;
}