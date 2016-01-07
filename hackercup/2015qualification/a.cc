#include<iostream>
#include<algorithm>


using namespace std;

int T, n;


int decimals() {
    int ans=1;
    while(ans<=n)
        ans*=10;
    return ans/10;
}

int swp(int a, int b) {
    return n - ((n/b)%10)*b + ((n/a)%10)*b - ((n/a)%10)*a + ((n/b)%10)*a;
}

int main(void) {
    cin >> T;
    int ca=0;
    while(T--) {
        cout << "Case# " << ++ca << ": ";
        cin >> n;
        int m=n, M=n, dec=decimals();
        
        for(int i=dec; i>0; i/=10) {
            for(int j=i/10; j>0; j/=10) {
                // cout << "digit: " << n/i%10 << endl;
                if((n/j)%10 == 0 && i==dec) continue;
                // cout << swp(dec,i) << endl;
                m = min(m, swp(j, i));
                M = max(M, swp(j, i));
            }
        }
        
        // cout << endl << decimals() << endl;
        cout << m << " " << M << endl;
    }
    return 0;
}