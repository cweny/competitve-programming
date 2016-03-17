#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstdio>
#define pii pair<int,int>

struct point {
    int x;
    bool isStart;
};
bool comp(const point &a, const point &b) {
    return a.x < b.x;
}
using namespace std;
int n,k;
pii vec[2000000];

int f(int &curr, int &i, int sz) {
    int at = vec[i].first;
    if(vec[i].second) {
        curr++;
    } else {
        curr--;
    }
    while(i+1 < sz && vec[i+1].first == at) {
        if(vec[i+1].second) {
            curr++;
        } else {
            curr--;
        }
        i++;
    }
    return at;
}

int main(void) {
    // cin >> n >> k;
    scanf("%d %d",&n, &k);
    // cout << n << " " << k << endl;
    for(int i=0; i<n; i++) {
        int a,b; //cin >> a >> b;
        scanf("%d %d", &a, &b);
        vec[2*i].first=a;
        vec[2*i].second=0;
        vec[2*i+1].first=b;
        vec[2*i+1].second=1;
        // vec.push_back(point(a,true));
        // vec.push_back(point(b,false));
    }
    sort(vec, vec+2*n);
    vector<int> ans;
    int anssize = 0;
    int curr = 0, sz = 2*n;
    // for(int i=0; i<sz; i++) {
    //     pii x=vec[i];
    //     cout << x.first << " " << x.second << endl;
    // }
    for(int i=0; i<sz; i++) { 
        if(vec[i].second) {
            curr--;
        } else {
            curr++;
        }
        if(curr >= k && (anssize%2 == 0)) {
            ans.push_back(vec[i].first);
            anssize++;
        } else if(curr < k && (anssize%2 == 1)){
            ans.push_back(vec[i].first);
            anssize++;
        }
        // cout << vec[i].x << " ";
        // int pos = f(curr,i,sz);
        // if((curr >= k) && (anssize%2 == 0)) {
        //     ans.push_back(pos);
        //     anssize++;
        // } else if (curr < k && anssize%2 == 1){
        //     ans.push_back(pos);
        //     anssize++;
        // }
        // cout << curr << " " << anssize;
        // for(int x:ans) cout << " " << x;
        // cout << endl;
    }
    sz = ans.size();
    cout << anssize/2 << endl;
    for(int i=0; i<sz; i+=2) {
        cout << ans[i] << " " <<ans[i+1] << endl;
    }
    return 0;
}