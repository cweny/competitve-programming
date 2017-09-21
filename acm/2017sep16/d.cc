#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>


using namespace std;

int memo[1000005];

vector<int> divisors(int n) {
    // Vector to store half of the divisors
    vector<int> v;
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i==0)
        {
            if (n/i == i) 
                v.push_back(i);
            else
            {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
    }
 
    // The vector will be printed in reverse
    // for (int i=v.size()-1; i>=0; i--)
    //     printf("%d ", v[i]);
    return v;
}

int dp(int n) {
    // cout << n << endl;
    if(memo[n] != -1) return memo[n];
    vector<int> dv = divisors(n);
    int ans = 0;
    for(int x: dv) {
        if(x==n) continue;
        ans += dp(x);
    }
    memo[n] = ans;
    return ans;
}

int main() {
    memset(memo, -1, sizeof memo);
    memo[1] = 1;
    int n; cin >> n;
    // divisors(64);
    cout << dp(n) << endl;
}