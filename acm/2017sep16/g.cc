#include<iostream>
#include<map>
#include<string>
#include<cstring>

using namespace std;


int main() {
    string s; cin >> s;
    if(s.size() > int('z'-'a') + 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    // map<char, int> m;
    bool seen[100], orig[100];
    memset(seen, 0, sizeof seen);
    memset(orig, 0, sizeof orig);
    for(char c:s) {
        orig[c-'a'] = true;
    }
    // for(char c:s) m[c]++;
    // for(auto x:m) cout << x.first << " " << x.second << endl;
    for(char c:s) {
        if(!seen[int(c-'a')]) {
            cout << c;
            seen[int(c-'a')] = true;
        } else {
            for(int i=0; i<26; i++) {
                if(!seen[i] && !orig[i]) {
                    cout << char('a' + i);
                    seen[i] = true;
                    break;
                }
            }
        }
    }
    cout << endl;
    
}