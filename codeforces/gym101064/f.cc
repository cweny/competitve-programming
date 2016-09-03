#include<iostream>
#define int long long

using namespace std;

int n,j,pos;

void recur() {
    if(j%2 == 1) {
        cout << (pos+(j/2)) << endl;
        return;
    }
    pos+=(j/2);
    n-=(j/2);
    j=n;
    recur();
}

#undef int
int main(void) {
#define int long long

    int T; cin >> T;
    while(T--) {
        cin >> n >> j;
        pos = 1;
        recur();
    }
    return 0;
}