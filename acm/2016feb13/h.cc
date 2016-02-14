#include<iostream>
#include<string>

using namespace std;

long long dp[10000000];
string s;

bool isvalid(char a, char b) {
    if(a=='0') return false;
    int n = (a-'0')*10 + (b-'0');
    return n<=26;
}
void dodp(int n) {
    for(int i=2; i<n; i++) {
            if(s[i] == '0') {
                if((s[i-1]-'0')>2 || (s[i-1]-'0')<1) {
                    cout << 0 << endl;
                    return;
                } else {
                    dp[i] = dp[i-2];
                }
            } else {
                dp[i] = dp[i-1];
                if(isvalid(s[i-1], s[i])) {
                dp[i] += dp[i-2];
                }
            }
        }
        cout << dp[n-1] << endl;
}
int main(void) {
    while(cin >> s) {
        
        if(s.size() == 1 && s[0]=='0')    break;
        
        if(s[0]=='0') {
            cout << 0 << endl;
            continue;
        }
        int n=s.size();
        for(int i=0; i<n; i++) {
            dp[i] = 0;
        }
        dp[0]=1;
        if(n==1) {
            cout << 1 << endl;
            continue;
        }
        // cout << "s[1]" << s[1] << endl;
        if(s[1]=='0') {
            // cout << s[0]-'0' << " " << (s[0]-'0') << endl;
            if((s[0]-'0')>2 || (s[0]-'0')<1) {
                // cout << 0 << endl;
                continue;
            } else {
                dp[1] = 1;
            }
        } else if(isvalid(s[0],s[1])) {
            dp[1] = 2;
        } else {
            dp[1] = 1;
        }
        
        dodp(n);
        // for(int i=0 ; i<n; i++) cout << dp[i] << " ";
        // cout << endl;
    }
    
    return 0;
}