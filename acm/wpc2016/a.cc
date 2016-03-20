#include<cstring>
#include<iostream>
#include<vector>

using namespace std;
vector<int> arr;
bool seen[1000];
int your;


int match(int x) {
    for(int i=x-1; i>=0; i--) {
        if(seen[i]) continue;
        if(arr[i] + arr[x] < your) {// ok
            seen[i] = true;
            return i;
        }
    }
    return -1;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin >>n;
        int m; cin>>m;
        arr.clear();
        for(int i = 0;i < n-1;i++){
            int tm; cin >>tm;
            arr.push_back(tm);
        }
        your = m + arr[n-2];
        int ans = 1;
        // int pre = n-3;
        // for (int i = n-3; i >)
        // cout << n/2 - ans -1 << endl;
        memset(seen, 0, sizeof seen);
        for(int i=n-3; i>=0; i--) {
            if(seen[i]) continue;
            seen[i] = true;
            int tmp = match(i);
            if(tmp != -1) { //able to match
                // cout << i << " matched with " << tmp << endl;
            } else { //match with next greatest
                int j=i-1; 
                while(j>=0 && seen[j]==true) {
                    j--;
                }
                seen[j] = true;
                // cout << i << " matched with " << j << endl;
                ans++;
            }
        }
        
        cout << ans << endl;
    }
}