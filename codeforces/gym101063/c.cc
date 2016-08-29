#include<iostream>

#define int long long

using namespace std;


int n,m;
int cnt[1030];
long double f[1030][1030];
long double q;
#undef int
int main(void) {
#define int long long
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        int y=0;
        for(int j=0; j<x; j++) {
            int z; cin >> z; z--;
            y = y | (1<<z);
        }
        cnt[y]++;
    }
    cin >> q;
    for(int i=0; i<=1024; i++) {
        for(int j=0; j<=1024; j++) {
            if(__builtin_popcount(i|j) > 0) {
                f[i][j] = (long double)__builtin_popcount(i&j)/__builtin_popcount(i|j);
            } else {
                f[i][j] = -1;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=1024; i++) {
        for(int j=i; j<=1024; j++) {
            if(f[i][j] >= q) {
                if(i!=j) {
                    ans += cnt[i]*cnt[j];
                } else {
                    ans += (cnt[i]*(cnt[i]-1))/2;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}