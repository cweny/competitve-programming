#include<iostream>
#include<vector>

using namespace std;

bool arr[512][512];

int pow(int n) {
    int ret = 1;
    for(int i=0; i<n; i++) {
        ret *= 2;
    }
    return ret;
}

void recur(int n) {
    if(n<=2) {
        arr[0][0] = true;
        arr[0][1] = true;
        arr[1][0] = true;
        arr[1][1] = false;
        return;
    }
    recur(n/2);
    for(int i=0; i<n/2; i++) {
        int x=1;
        for(int j=n/2; j<n; j++) {
            arr[i][j] = !arr[i][j-x];
            x+=2;
        }
    }
    
    for(int i=n/2; i<n; i++) {
        for(int j=0; j<n/2; j++) {
            arr[i][j] = arr[i-n/2][j];
        }
    }
    
    for(int i=n/2; i<n; i++) {
        int x=1;
        for(int j=n/2; j<n; j++) {
            arr[i][j] = arr[i][j-x];
            x += 2;
        }
    }
}
int main(void) {
    int k; cin >> k;
    int sz = pow(k);
    recur(sz);
    for(int i=0; i<sz; i++) {
        for(int j=0; j<sz; j++) {
            if(arr[i][j]) {
                cout << "+";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
    return 0;
}
