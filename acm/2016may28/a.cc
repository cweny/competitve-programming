#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define double long double
using namespace std;
#define int long long
int N, L, W;
int arr[2000];
double dp[2000][2000];

double dist(double a, double b, double c, double d) {
    return (double)sqrt((a-c)*(a-c) + (b-d)*(b-d));
}
#undef int
int main(void) {
#define int long long
    cin >> N >> L >> W;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+N);
    double space = (double)L/(N/2-1);
    for(int r=0; r<=N/2; r++) {
        for(int l=0; l<=N/2; l++) {
            int idx = l+r-1;
            if(l==0 && r==0) dp[l][r] = 0;
            else if(l==0) dp[l][r] = dp[l][r-1] + dist(0, arr[idx], W, space*(r-1));
            else if(r==0) dp[l][r] = dp[l-1][r] + dist(0, arr[idx], 0, space*(l-1));
            else dp[l][r] = min(  dp[l][r-1] + dist(0,arr[idx],W,space*(r-1)) , 
                                  dp[l-1][r] + dist(0,arr[idx],0,space*(l-1)) );
        }
    }
    cout << fixed << setprecision(10) << dp[N/2][N/2] << endl;
    return 0;
}