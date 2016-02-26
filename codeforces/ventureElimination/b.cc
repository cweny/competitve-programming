#include<iostream>
#include<string>
#include<cstring>
#define ll long long
using namespace std;

int n;
string s;
int memo[201][201][201];

int dp(int bc, int rc, int gc) {
    if(memo[bc][rc][gc]!=-1) return memo[bc][rc][gc];
    
    ll ans = 0;
    if(bc>1) {
        ans |= dp(bc-1, rc, gc);
    }
    if(rc>1) {
        ans |= dp(bc, rc-1, gc);
    }
    if(gc>1) {
        ans |= dp(bc, rc, gc-1);
    }
    if(bc>0 && rc>0) {
        ans |= dp(bc-1, rc-1, gc+1);
    }
    if(rc>0 && gc>0) {
        ans |= dp(bc+1, rc-1, gc-1);
    }
    if(bc>0 && gc>0) {
        ans |= dp(bc-1, rc+1, gc-1);
    }
    return memo[bc][rc][gc]=ans;
}

int main(void) {
    cin >> n >> s;
    int rc, gc, bc;
    rc = gc = bc = 0;
    for(char c:s) {
        if(c=='R') {
            rc++;
        } else if(c=='B') {
            bc++;
        } else if(c=='G') {
            gc++;
        }
    }
    memset(memo, -1, sizeof memo);
    memo[0][0][0] = 0;
    memo[1][0][0] = 4;
    memo[0][1][0] = 2;
    memo[0][0][1] = 1;
    int res = dp(bc,rc,gc);
    string ans = "";
    if(res & 4) {
        ans += "B";
    }
    if(res & 1 ) {
        ans += "G";
    }
    if(res & 2) {
        ans += "R";
    }
    cout << ans << endl;
    return 0;
}