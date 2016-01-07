#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll arr[200000];
int main(void) {
    ll n; cin >> n;
    ll mini = 100000000000;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        mini = min(mini, arr[i]);
    }
    int first = -1;
    int last = -1;
    ll ans = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] != mini) continue;
        if(first == -1) {
            first = i;
            last = i;
            continue;
        }
        ans = max(ans, n*(mini-1) + n-last-1 + i);
        last = i;
    }
    ans = max(ans, mini*n + n-last-1 + first);
    cout << ans << endl;
    return 0;
}