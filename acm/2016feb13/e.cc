#include<iostream>
#include<algorithm>

using namespace std;

int n,m;

bool arr[1000][1000];
int dp[1000][1000];

int main (void) {
    while(true) {
        cin >> n >> m;
        if(n == 0 && m == 0) {
            break;
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cin >> arr[i][j];
            }
        }
        int ans = -1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(arr[i][j]) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(arr[i][j]) {
                    dp[i][j] = max(dp[i][j], 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) ));
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}