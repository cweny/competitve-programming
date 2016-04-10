#include<iostream>
#include<cstring>

#define ll long long
using namespace std;

ll n;
bool seen[10];
int got;

int f(int x) {
    int ans = 0;
    while(x > 0) {
        int d = x%10;
        if(!seen[d]) {
            seen[d] = true;
            ans++;
        }
        x /= 10;
    }
    
    return ans;
}

int main(void) {
    int t;
    cin >> t;
    int ca=0;
    while(t--) {
        cin >> n;
        ll ans = 0;
        memset(seen, 0, sizeof seen);
        if(n==0) {
            cout << "Case #" << ++ca << ": INSOMNIA" << endl;
            continue;
        }
        got = 0;
        do {
            ans += n;
            got += f(ans);
        } while (got < 10);
        cout << "Case #" << ++ca << ": " << ans << endl;
    }
    return 0;
}