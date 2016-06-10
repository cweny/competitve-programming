#include<iostream>
#include<map>
#include<unordered_map>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

int n,k;
int arr[500000];
int om[1000005];
// map<int, int> om;

int main() {
    ios_base::sync_with_stdio(0);
    memset(om, 0, sizeof om);
    cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    int num = 0, idx = 0, sz=0;
    while((num < k || om[arr[idx]] > 0) && idx < n) {
        if(om[arr[idx]] == 0) {
            om[arr[idx]]++;
            num++;
        } else {
            om[arr[idx]]++;
        }
        sz++;
        idx++;
    }
    int l = 0, r = idx;
    int ans = sz;
    int i1=0, i2=idx;
    while(i2 < n) {
        while(num!=k-1) {
            sz--;
            om[arr[i1]]--;
            if(om[arr[i1]]==0) {
                num--;
            }
            i1++;
        }
        while(true) {
            if(i2 >= n) break;
            if(num < k || om[arr[i2]] > 0) {
                sz++;
                if(om[arr[i2]] == 0) {
                    num++;
                }
                om[arr[i2]]++;
                i2++;
            } else {
                break;
            }
        }
        
        if(ans < sz) {
            l = i1;
            r = i2;
            ans = sz;
        }
    }
    cout << l+1 << " " << r << endl;
}