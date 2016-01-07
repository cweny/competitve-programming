#include<iostream>
#define ld long double

using namespace std;
int r,s,x,y,w;
ld p;
ld prob(int good, int bad) {
    if(good>=x) return 1;
    if(good+bad>=y) return 0;
    return p*prob(good+1,bad) + (1-p)*prob(good,bad+1);
}

int main(void) {
    int t;cin>>t;
    while(t--) {
        cin>>r>>s>>x>>y>>w;
        p=(ld)(s-r+1)/s;
        //cout << s-r << endl;
        if(prob(0,0)*w>1)
            cout << "yes"   <<endl;
        else 
            cout << "no" << endl;
    }
    return 0;
}