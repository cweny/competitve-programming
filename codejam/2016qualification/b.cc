#include<iostream>
#include<string>

using namespace std;

int n;
string s;
bool flipped;

int main(void) {
    int t;
    cin >> t;
    int ca=0;
    
    while(t--) {
        cin >> s;
        int ans = 0;
        n = s.size();
        char obj = '+';
        for(int i=n-1; i>=0; i--) {
            if(s[i] != obj) {
                ans++;
                if(obj == '-') obj = '+';
                else obj = '-';
            }
        }
        
        cout << "Case #" << ++ca << ": " << ans << endl;
    }
    return 0;
}