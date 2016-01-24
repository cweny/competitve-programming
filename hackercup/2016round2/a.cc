#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int inf = 100000000000;

char a[100005];
char b[100005];
int dpa[100005];
int dpb[100005];
int dpamod[100005];
int dpbmod[100005];
int n;
int dpa2[100005];
int dpb2[100005];

void dphelper(int curr, int prev, int next, int *memo, int *memomod, char *colors, char *others) {
    if(a[curr]==b[curr]) {
        memo[curr] = memo[prev];
    } else {
        memo[curr] = 1 + memomod[prev];
    }
    
    if(others[curr]==others[next]) {
        memomod[curr] = memomod[prev];
    } else {
        memomod[curr] = 1+memomod[prev];
    }
}
#undef int
int main(void) {
#define int long long
    int T, ca=0; cin >> T;
    while(T--) {
        int ans = inf;
        cin >> n;
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
       
        if(a[0]==b[0]) dpa[0] = 0;
        else dpa[0] = 1;
        if(b[1]==b[0]) {
            dpamod[0] = 0;
        } else {
            dpamod[0] = 1;
        }
        
        
        if(a[n-1]==b[n-1]) dpb[n-1] = 0;
        else dpb[n-1] = 1;
        if(b[n-2]==b[n-1]) {
            dpbmod[n-1] = 0;
        } else {
            dpbmod[n-1] = 1;
        }
        
        
        for(int i=1; i<n; i++) {
            dphelper(i,i-1, i+1, dpa,dpamod,a,b);
        }
        for(int i=n-2; i>=0; i--) {
            dphelper(i,i+1, i-1,dpb,dpbmod,a,b);
        }
        
        
        
        // for(int i=0; i<n;i++) {
        //     cout << dpa[i] << " " ;
        // } cout << endl;
        
        // for(int i=0; i<n;i++) {
        //     cout << dpb[i] << " " ;
        // } cout << endl;
        
        // dpa2[n-1] = dpa[0];
        // for(int i=0; i<n-1; i++) {
        //     dpa2[i] = dpa[0]-dpa[i+1];
        // }
        // dpb2[0] = dpb[n-1];
        // for(int i=n-1; i>0; i--) {
        //     dpb2[i] = dpb[n-1]-dpb[i-1];
        // }
        
        // for(int i=0; i<n;i++) {
        //     cout << dpa[i] << " " ;
        // } cout << endl;
        
        // for(int i=0; i<n;i++) {
        //     cout << dpb[i] << " " ;
        // } cout << endl;
        
        // for(int i=0; i<n;i++) {
        //     cout << dpamod[i] << " " ;
        // } cout << endl;
        // for(int i=0; i<n;i++) {
        //     cout << dpbmod[i] << " " ;
        // } cout << endl;
        
        ans = min(dpa[n-1],dpb[0]);
        
        for(int i=0; i<n-1; i++) {
            ans = min(ans, max(dpa[i], dpb[i+1]));
        }
        
        cout << "Case #" << ++ca << ": " << ans << endl;
    }
    return 0;
}