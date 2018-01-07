#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

double arr[500];

int main() {
    int n,k; cin >> n >> k;
    for(int i=0; i<=n; i++) arr[i] = 0;
    arr[0] = 1;
    while(k--) {
        vector<double> v(n+1);
        for(int i=0; i<n; i++) v[i] = 0;
        for(int i=0; i<n; i++) {
            v[i] += arr[i]*0.5; 
            v[i+1] += arr[i]*0.5;
        }
        v[n-1] += arr[n]*0.5;
        v[n] += arr[n]*0.5;
        for(int i=0; i<=n; i++) {
            arr[i] = v[i];
        } 
        
    }
    double ans=0;
    for(int i=1; i<=n; i++) {
        ans += i*arr[i];
    }
    cout << fixed << setprecision(8) << ans << endl;
}