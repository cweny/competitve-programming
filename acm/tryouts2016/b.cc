#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

int arr[100000];
#undef int
int main(void) {
#define int long long
    int T; cin >> T;
    while(T--) {
        int n,m; cin >> n >> m;
        for(int i=0; i<n; i++) cin >> arr[i];
        sort(arr, arr+n);
        int st = 100000000,ans=0;
        for(int i=0; i<n; i++) {
            if(arr[i]>=0) {
                st=i;
                break;
            }
        }
        int negidx = st-1;
        // cout << st << endl;
        if(n-st>=2) {
            ans+= arr[st]+arr[st+1];
            st+=2;
            
            for(int i=st; i<n; i++) {
                ans+=2*arr[i];
            }
            
            
            if(negidx-1 >= 0) {
                int n1 = arr[negidx], n2 = arr[negidx-1];
                int p1 = arr[negidx+1], p2 = arr[negidx+2];
                
                int res = max(n1+p1+n2+p2,max(n1+p1,max(n1+p2, max(n2+p1, n2+p2))));
                if(res>0) ans += res;
                
            } else if(negidx >= 0) {
                if(arr[negidx+2]+arr[negidx]) {
                    ans += arr[negidx+2]+arr[negidx];
                }
            }
        } else if(n-st==1) {
            if(negidx >= 0) {
                if(arr[st]+arr[negidx] > 0) {
                    ans += arr[st]+arr[negidx];
                }
            }
        }
        
        cout << ans << endl;
        
    }
    
    
    return 0;
}