#include<iostream>
#define ll long long

using namespace std;

ll memo[100][11];

int main(void) {
    int t; cin >> t;
    for(int i=0; i<=9; i++) {
        memo[1][i] = 1;
    }
    
    for(int i=2; i<=64; i++) {
        for(int j=0; j<=9; j++) {
            for(int k=j; k<=9; k++) {
                memo[i][j] += memo[i-1][k];
            }
        }
    }
    
    while(t--) {
        int T,n; cin >> T >> n;
        
        
        
        cout << T << " ";
        ll ans = 0;
        for(int i=0; i<=9; i++) {
            ans+=memo[n][i];
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}