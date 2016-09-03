#include<iostream>

using namespace std;

int n;
bool f(int k) {
    long double x = 1;
    for(int i=1; i<k; i++) {
        x = x*(long double)((long double)n-i)/n;
        // cout << x << endl;
    }
    // cout << k << " " << x << endl;
    return (x<=0.5);
}
int main(void) {
    cin >> n;
    int ans = 0;
    for(int i=1; i<=n+1; i++) {
        if(f(i)) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}