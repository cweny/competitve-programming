#include<iostream>
#include<algorithm>
#define inf 100000000
using namespace std;

int n,k;
int memo[300][31];
int distances[300][300];
int arr[300];
int end_dist[300];

int dist(int a, int b) {
    int ans = 0;
    for(int i=a+1; i<b; i++) {
        ans += min(arr[i]-arr[a], arr[b]-arr[i]);
    }
    return ans;
}

int main(void) {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    sort(arr,arr+n);
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            distances[i][j] = dist(i,j);
        }
    }
    
    memo[0][1] = 0;
    for(int i=1; i<n; i++) {
        memo[i][1] = memo[i-1][1] + (arr[i] - arr[i-1])*i;
    }
    
    end_dist[n-1] = 0;
    for(int i=n-2; i>=0; i--) {
        end_dist[i] = end_dist[i+1] + (arr[i+1]-arr[i])*(n-1-i);
    }
    
    for(int i=2; i<=k; i++) {
        for(int j=i-1; j<n; j++) {
            int ans = inf;
            for(int c=i-2; c<j; c++) {
                ans = min(ans, memo[c][i-1] + distances[c][j]);
            }
            memo[j][i] = ans;
        }
    }
    int ans = inf;
    for(int i=k-1; i<n; i++) {
        ans = min(ans, memo[i][k] + end_dist[i]);
    }
    cout << ans << endl;
    return 0;
}