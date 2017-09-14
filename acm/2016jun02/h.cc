#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(void) {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int ans = 0;
        for(int i=0; i<n; i++) {
            int x,y; cin >> x >> y;
            double dist = sqrt(x*x + y*y);
            int t=0;
            for(int i=200; i>=20; i-=20 ) {
                if(dist>i){
                    break;  
                } 
                t++;
            }
            
            // cout << dist << " ";
            // cout << t << endl;
            
            ans += t;
        }
        cout << ans << endl;
    }
    return 0;
}