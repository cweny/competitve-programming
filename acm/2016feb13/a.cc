#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

int arr[101][101], n;
int dp[101][101];

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    memset(dp, 0, sizeof dp);
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<=i; j++) {
    //         cout << dp[i][j] << " "; 
    //     } cout << endl;
    // }
    dp[0][0] = arr[0][0];
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<=i; j++) {
            if(dp[i][j] + arr[i+1][j] > dp[i+1][j]) {
                dp[i+1][j] = dp[i][j] + arr[i+1][j];
            }
            
            if(dp[i][j] + arr[i+1][j+1] > dp[i+1][j+1]) {
                dp[i+1][j+1] = dp[i][j] + arr[i+1][j+1];
            }
        }
    }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<=i; j++) {
    //         cout << dp[i][j] << " "; 
    //     } cout << endl;
    // }
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = max(ans, dp[n-1][i]);
    }
    cout << ans << endl;
    return 0;
}