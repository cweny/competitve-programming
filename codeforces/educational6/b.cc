#include<iostream>

using namespace std;

int cost[] = {6,2,5,5,4,5,6,3,7,6};

int main(void) {
    long long ans = 0;
    int a,b; cin >> a >> b;
    for(int i=a; i<=b; i++) {
        int x = i;
        while(x>0) {
            ans += cost[x%10];
            x /= 10;
        }
    }
    cout << ans << endl;
    return 0;
}