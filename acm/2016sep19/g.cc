#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, decr[2005], arr[2005], incr[2005], decrl[2005], incrl[2005];

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    // memset(decr, 1, sizeof decr);
    // memset(incr, 1, sizeof incr);
    for(int i=0; i<n; i++) {
        decr[i] = 1;incr[i] = 1;
        decrl[i] = arr[i]; incrl[i] = arr[i];
    }
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] < arr[j] ) {
                if(decr[i] < 1+decr[j]) {
                    decr[i] = 1+decr[j];
                    decrl[i] = decrl[j];
                }
            }
            
            if(arr[i] > decrl[j]) {
                if(incr[i] < 1+decr[j]) {
                    incr[i] = 1+decr[j];
                    incrl[i] = arr[j];
                } else if(incr[i] == 1+decr[i]) {
                    if(incrl[i] < arr[j]) {
                        incr[i] = 1+decr[i];
                        incrl[i] = arr[j];
                    }
                }
            }
            
            if(arr[i] > arr[j]) {
                if(incr[i] < 1+incr[j]) {
                    incr[i] = 1+incr[j];
                    incrl[i] = incrl[j];
                }
            }
            if(arr[i] < incrl[j]) {
                if(decr[i] < 1+incr[j]) {
                    decr[i] = 1+incr[j];
                    decrl[i] = arr[j];
                } else if(decr[i] == 1+incr[j]) {
                    if(decrl[i] > arr[j]) {
                        decr[i] = 1+incr[j];
                        decrl[i] = arr[j];
                    }
                }
            }
        }
    }
    
    int ans=-1;
    
    for(int i=0; i<n; i++) {
        ans = max(ans,max(incr[i],decr[i]));
    }
    cout << ans << endl;
    
    return 0;
}