#include<iostream>
#include<algorithm>
#include<cstring>
#define pii pair<int,int>

using namespace std;

int J,A;
char j[1000005];
pii a[1000005];
bool seen[1000005];

bool comp(char a, char b) {
    if(a=='L') {
        if(b=='L') {
            return true;
        } 
        return false;
    } else if( a=='M') {
        if(b=='M' || b=='L') {
            return true;
        }
        return false;
    }
    
    return true;
}

int main(void) {
    cin >> J >> A;
    
    for(int i=1; i<=J; i++) {
        cin >> j[i];
    }
    
    for(int i=1; i<=A; i++) {
        int x; char c; cin >> c >> x;
        a[i].first = x;
        a[i].second = (int)c;
    }
    
    // sort(a, a+A);
    memset(seen, 0, sizeof seen);
    int ans = 0;
    for(int i=1; i<=A; i++) {
        // cout << a[i].first << " " << (char)a[i].second << endl;
        int num = a[i].first;
        if(!seen[num]) {
            if(comp((char)a[i].second, j[num])) {
                seen[num] = true;
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
