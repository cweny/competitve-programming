#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>


#define pii pair<int,int>

struct st {
    int r,c,i;
};

using namespace std;

int n;
bool cmp(const st &a, const st &b)
{
    return a.c < b.c;
}

vector<st> vec;
//c,r
int main(void) {
    cin >> n;
    for(int i=0; i<n; i++) {
        int c,r; cin >> c >> r;
        st tmp; tmp.c = c; tmp.r = r; tmp.i = i+1;
        vec.push_back(tmp);
    }
    int currr = 1;
    
    // cout << targc << endl;
    int ans = 0;
    int targc = vec[n-1].c;
    sort(vec.begin(), vec.end(), cmp);
    
    bool ok = false;
    int i=0;
    // for(auto x:vec) cout << x.first << " " << x.second << endl;
    vector<int> vans;
    while(true) {
        if(currr >= targc) {
            ok = true;
            break;
        }
        ans++;
        int nextr = -1;
        int maxi = -1;
        while(i<n && vec[i].c <= currr) {
            if(nextr < vec[i].r) {
                maxi = vec[i].i;
                nextr = vec[i].r;
            }
            // nextr = max(vec[i].r, nextr);
            i++;
        }
        // if(currr >= targc) {
        //     ok = true;
        //     break;
        // }
        
        if(nextr <= currr) break;
        currr = nextr;
        // cout << "at: " <<  i << " curr r: " << currr << endl;
        
        vans.push_back(maxi);
        if(currr >= targc) {
            ok = true;
            break;
        }
        
    }
    if (ok) {
        cout << ans+1 << endl;
        for(int i=0; i< ans; i++) cout << vans[i] << " ";
        cout << n << endl;
    }
    else cout << "No such luck" << endl;
    return 0;
}
