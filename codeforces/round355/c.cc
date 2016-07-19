#include<iostream>
#include<string>
#define int long long
const long long mod = 1e9+7;

using namespace std;

#undef int
int main(void) {
#define int long long
    string s;
    cin >> s;
    int n=s.size();
    int zeros = 0;
    for(int i=n-1; i>=0; i--) {
        char c = s[i];
        // cout << c << " ";
        int x=-1;
        if(c>='0' && c<='9') {
            x=(c-'0');
        } else if(c>='A' && c<='Z') {
            x=10+(c-'A');
        } else if(c>='a' && c<='z') {
            x=36+(c-'a');
        } else if(c == '-') {
            x=62;
        } else if(c == '_') {
            x=63;
        }
        // cout << x << endl;
        for(int i=0; i<6; i++) {
            if(x%2 == 0) zeros++;
            x/=2;
        }
    }
    int ans = 1;
    for(int i=0; i<zeros; i++) {
        ans = ans*3;
        ans = ans%mod;
    }
    cout << ans<<endl;;
    
    return 0;
}
