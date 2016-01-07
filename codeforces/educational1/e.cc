#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int memo[35][35][55];
int inf = 10000000;

int dp(int n, int m, int k) {
    if(memo[n][m][k] != -1) return memo[n][m][k];
    if(memo[m][n][k] != -1) return memo[n][m][k]=memo[m][n][k];
    
    if(n*m == k || k==0) return memo[n][m][k]=memo[m][n][k]=0;
    
    if(n*m < k ) return memo[n][m][k]=memo[m][n][k]=inf;
    
    if(n==0 || m==0) return memo[n][m][k]=memo[m][n][k]=inf;
    int mini=inf;
    for( int cut=1; cut<n; cut++ ) {
        for( int sum=0; sum<=k; sum++ ) {
            int tmp = dp(cut,m,sum) + dp(n-cut,m,k-sum) + m*m;
            mini=min(tmp,mini);
        }
    }
    
    for( int cut=1; cut<m; cut++ ) {
        for( int sum=0; sum<=k; sum++ ) {
            int tmp = dp(cut,n,sum) + dp(m-cut,n,k-sum) + n*n;
            mini=min(tmp,mini);
        }
    }
    
    return memo[n][m][k]=memo[m][n][k]=mini;;
}

int main(void) {
    int t; cin >> t;
    memset(memo, -1, sizeof memo);
    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;
        cout << dp(n,m,k) << endl;
    }
}