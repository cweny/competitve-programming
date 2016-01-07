#include<iostream>
#define ll long long
using namespace std;


int main(void) {
    
    int t;cin>>t;
    while(t--) {
        ll n; cin >> n;
        ll tmp;
        if(n%2==0) {
            tmp = (n/2)*(n+1);
        } else {
            tmp = n*((n+1)/2);            
        }
        ll pow = 1;
        while(pow<=n) {
            tmp -= 2*pow;
            pow *= 2;
        }
        cout << tmp << endl;
    }
    return 0;
}