#include <bits/stdc++.h>

using namespace std;

int k,n;
vector<vector<int> > dp_vec[7];
int dp[7][40];
int arr[7];
int rows[7];
// 7 7 = 1
// 7 6 = 7
// 7 5 = 21
// 7 4 = 35
// 7 3 = 35
// 7 2 = 21
// 7 1 = 7
void recur(int choose, int from, int dp_index, vector<int> &vec) {
    // cout << "   chooseing " << choose << " from " << from << endl;
    if(choose == 0) {
        dp_vec[dp_index].push_back(vec);
        return;
    }
    if(from == 0) {
        return;
    }
    recur(choose, from-1, dp_index, vec);
    vec.push_back(from);
    recur(choose-1, from-1, dp_index, vec);
    vec.pop_back();
}
int main(void) {
    while(cin >> k) {
        
        // cout << "$$$$$$$$$$$$$$" << endl;
        for(int i=0; i<k; i++) {
            
            
            cin >> rows[i];
            //arr[i];
        }
        memset(arr,0,sizeof arr);
        for(int i=0; i<k; i++) {
            for(int j=0; j<rows[i]; j++) {
                arr[j]++;
            }
        }
        int tmp=k;
        k=0;
        for(int i=0; i<tmp; i++) {
            k=max(k,rows[i]);
            // cout << k << endl;
        }
        // cout << "K " << k << endl;
        for(int i=0; i<k; i++) {
            dp_vec[i].clear();
            // arr[i];
            // cout << arr[i] << " ";
        } //cout << endl;
        
        cin >> n;
        
        for(int i=0; i<k; i++) {
            vector<int> vec;
            // cout << "choose  " << arr[i] << " from " << n << endl;
            recur(arr[i], n, i, vec);
            // for(vector<int> v:dp_vec[i]) {
            //     for(int x:v) {
            //         cout << x << " ";
            //     }cout << endl;
            // }
            // cout << "---------" << endl;
        }
        memset(dp, 0, sizeof dp);
        for(int i=0; i<dp_vec[0].size(); i++) {
            dp[0][i] = 1;
        }
        for(int i=1; i<k; i++) {
            int j=0;
            for(vector<int> curr:dp_vec[i] ) {
                int k2=0;
                for(vector<int> prev:dp_vec[i-1]) {
                    
                    bool ok=true;
                    int prev_last = prev.size()-1;
                    for(int sz=curr.size()-1; sz>=0; sz--) {
                        // cout << sz <<  " " << prev_last << endl;
                        if(curr[sz] < prev[prev_last]) {
                            // cout << " got false in " << sz << " " << prev_last<< endl;
                            ok = false;
                            break;
                        }
                        prev_last--;
                    }
                    // cout << "verifying ";
                    // for(int x : curr) {
                    //     cout << x << " ";
                    // }
                    // cout << " and ";
                    // for(int x : prev) {
                    //     cout << x << " ";
                        
                    // }
                    // cout << "got " << ok << endl;
                    if(ok) {
                        dp[i][j] += dp[i-1][k2];
                        // cout << dp[i][j];
                    }
                    k2++;
                }
                // cout << dp[i][j] << " ";
                j++;
            }//cout << endl;
        }
        
        int ans=0;
        for(int i=0; i<dp_vec[k-1].size(); i++) {
            ans += dp[k-1][i];
        }
        cout << ans << endl;
    }
    
    return 0;
}