#include<iostream>
#include<iomanip>
#include<algorithm>

using namespace std;

double dp[1340][1340];
int n;
double p[1340];
int main(void) {
    while(cin >> n) {
        for(int i=1; i<=n; i++) {
            int x;
            cin >> x;
            p[i] = x/100.0;
        }
        sort(p+1, p+n+1, greater<double>());
        dp[0][0] = 1;
        
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                if(i==0 && j==0) {
                    dp[i][j] = 1;
                } else if(i==0) {
                    dp[i][j] = 0;
                } else if(j==0) {
                    dp[i][j] = dp[i-1][j] * (double)(1-p[i]);
                } else if (i<j) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = (dp[i-1][j]*(1-p[i]) +  
                                    dp[i-1][j-1]*p[i]);
                }
            }
        }
        
        // for(int i=0; i<=n; i++) {
        //     for(int j=0; j<=n; j++) {
        //         cout << dp[i][j] << " ";
        //     }cout << endl;
        // }
        
        double ans = -1;
        for(int i=1; i<=n; i++) {
            double tmp = 0;
            for(int j=1; j<=n; j++) {
                if(i%2==1 && j>i/2) {
                    tmp += dp[i][j];
                }
            }
            ans = max(ans, tmp);
        }
        cout << fixed << setprecision(5) << ans << endl;
    }
    return 0;
}