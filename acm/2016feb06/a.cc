#include<iostream>
#include<string>

using namespace std;

int n,k;
string s;
int p1, p2, lef, rig;
long long ans;

int get1(int index) {
    for(;index<n;index++) {
        if(s[index]=='1') {
            break;
        }
    }
    return index;
}

int main(void) {
    int t; cin >> t;
    
    while(t--) {
        cin >> n >> k;
        cin >> s;
        ans = 0;
        int count = 0;
        for(int i=0; i<n; i++)
            if(s[i] == '1')
                count++;
        if(count < k) {
            cout << ans << endl;
            continue;
        }
        int idx=get1(0);
        // for(;idx<n;idx++) {
        //     if(s[idx]=='1')
        //         break;
        // }
        lef = idx+1;
        p1 = idx;
        count = 1;
        if(count < k) {
            idx++;
        }
        for(;idx<n;idx++) {
            if(count >= k) break;
            if(s[idx]=='1') {
                count++;
                if(count >= k) break;
            }
        }
        p2 = idx;
        // idx++;
        idx = get1(idx+1);
        // for(;idx<n;idx++) {
        //     if(s[idx]=='1') break;
        // }
        rig = idx - p2;
        // cout << lef << " " << rig << " " << p1 << " " << p2 << endl;
        ans += lef*rig;
        // cout << idx << endl;
        while(true) {
            // cout << idx << endl;
            if(idx >= n) break;
            p2 = idx;
            idx=get1(idx+1);
            // idx++;
            // for(;idx<n;idx++) {
            //     if(s[idx]=='1')
            //         break;
            // }
            rig = idx - p2;
            int idx2=get1(p1+1);
            // int idx2 = p1+1;
            // for(;idx2<n;idx2++) {
            //     if(s[idx2]=='1') {
            //         break;
            //     }
            // }
            lef = idx2 - p1;
            p1 = idx2;
            // cout << lef << " " << rig << " " << p1 << " " << p2 << endl;
            ans += lef*rig;
        }
        cout << ans << endl;
    }
    
    return 0;
}