#include<iostream>
#include<string>

using namespace std;

int n;
string s;

bool ok(int a, int b) {
    int dx=0, dy=0;    
    for(int i=a; i<=b; i++) {
        if(s[i]=='U') {
            dy++;
        } else if(s[i]=='R') {
            dx++;
        } else if(s[i]=='L') {
            dx--;
        } else if(s[i]=='D') {
            dy--;
        }
    }
    return dx==0 && dy==0;
}

int main(void) {
    cin >> n >> s;
    long long ans = 0;
    for(int i=2; i<=n; i++) {
        for(int j=0; j+i-1<n; j++) {
            if(ok(j,j+i-1)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}