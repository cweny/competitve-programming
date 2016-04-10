#include<iostream>
#include<stack>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    stack<int> q;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        if(x==0) {
            q.pop();
        } else {
            q.push(x);
        }
    }
    int ans = 0;
    while(!q.empty()) {
        // cout << q.top() << endl;
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}