#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

ll nums[100005];
ll n,p;


ll getCombinations(ll a, ll b) {
    ll k;
    if(a>b)
        k=a-b+1;
    else 
        k=b-a+1;
    // ll k=abs(b-a)+1;
    if(k%2==0) {
        return (k/2)*(k+1);
    }
    return ((k+1)/2)*k;
}

int main(void) {
    int t; cin >> t;
    int ca=0;
    while(t--) {
        cin >> n >> p;
        int p1=0, p2=0;
        int prev1=-1, prev2=-1;
        for(int i=0; i<n; i++) {
            cin >> nums[i];
        }
        ll sum = nums[0];
        ll ans = 0;
        while(p2<n) {
            if(sum > p) {
                sum-=nums[p1];
                p1++;
                if(p1>p2) {
                    p2++;
                    sum+=nums[p1];
                }
            } else {
                if(p2+1 >= n || nums[p2+1]+sum > p){
                    if(prev1!=-1) {
                        if(p1<=prev2) {
                            ans -= getCombinations(p1,prev2);
                        }
                    }
                    prev1=p1;
                    prev2=p2;
                    ans += getCombinations(p2, p1);
                }
                p2++;
                sum+=nums[p2];
            }
        }
        cout <<"Case #" << ++ca << ": "<< ans << endl;
    }
    return 0;
}
