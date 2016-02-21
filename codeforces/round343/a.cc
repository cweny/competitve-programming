#include<iostream>

using namespace std;
int n;
bool arr[105][105];

long long c2(long long x) {
    long long ans;
    if(x%2==0) {
        ans = (x/2)*(x-1);
    } else {
        ans = ((x-1)/2)*x;
    }
    
    return ans;
}

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char c; cin >> c;
            if(c=='C') {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }
    long long ans = 0;
    for(int i=0; i<n; i++) {
        long long tmp = 0, tmp2=0;
        for(int j=0; j<n; j++) {
            if(arr[i][j]) {
                tmp += 1;
            }
            if(arr[j][i]) {
                tmp2+=1;
            }
        }
        ans += c2(tmp) + c2(tmp2);
    }
    cout << ans << endl;
    return 0;
}