#include<iostream>
#include<string>

using namespace std;

string s,tmp;
int n;

void shift(int l, int r, int k) {
    int len=r-l+1;
    //cout << "len " << len << endl;
    for(int i=0; i<len; i++) {
        int idx = (i+k)%len;
        idx += l;
        //cout << idx << " " ;
        tmp[idx] = s[i+l];
        //cout << tmp << endl;
    }
    for(int i=l; i<=r; i++) {
        s[i]=tmp[i];   
    }
}

int main(void) {
    cin >> s;
    tmp = s;
    n=s.size();
    int q; cin>>q;
    while(q--) {
        int l,r,k;
        cin >> l >> r >> k;
        l--; r--;
        k %= (r-l+1);
        shift(l,r,k);
        
    }
    cout << s << endl;
    return 0;
}