#include<iostream>
#include<set>

using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    int ans = 0;
    while(n--) {
        int x; cin >> x;
        if(s.count(x)>0) ans++;
        s.insert(x);
    }
    cout << ans << endl;
}