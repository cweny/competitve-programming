#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int n;
vector<stack<int> > vec;
vector<int> ans;
vector<int> sorted;
bool f() {
    // return false;
    for(int i=0; i<n; i++) {
        sorted.push_back(i+1);
    }
    for(int i=n-2; i>=0; i--) {
        vector<int> at;
        for(int j=n-2; j>=i; j--) {
            at.push_back(vec[j].top());
            vec[j].pop();
        }
        reverse(at.begin(),at.end());
        // for(int x:at) {
        //     cout << x << " ";
            
        // } cout << endl;
        
        int idx=i;
        // cout << "new" << endl;
        for(int x:at) {
            //cout << x << " ";
            //swap
            
            //(void) x;
            if(x) {
                int tmp = sorted[idx];
                sorted[idx] = sorted[idx+1];
                sorted[idx+1] = tmp;
                if(sorted[idx]<sorted[idx+1]) {
                // cout << "err: " <<  << endl;
                return false;
                }
            } else {
                if(sorted[idx]>sorted[idx+1]) {
                // cout << "err: " <<  << endl;
                return false;
                }
            }
            // for(int y:sorted) {
            //     // cout << y << " ";
            // } cout << endl;
            
            
            idx++;
        } //cout << endl;
        
    }
    return true;
}

int main(void) {
    freopen("bubble.in","r",stdin);
    freopen("bubble.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n-1; i++) {
        stack<int> q;
        vec.push_back(q);
        for(int j=0; j<i; j++) {
            int x; cin >> x;
            vec[i-1].push(x);
        }
    }
    // for(int i=1; i<=n-1; i++) {
    //     while(!vec[i-1].empty()) {
    //         cout << vec[i-1].top() << " ";
    //         vec[i-1].pop();
    //     }cout << endl;
    // }
    
    if(f()) {
        cout << "YES" << endl;
        for(int x: sorted) {
            cout << x  << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}