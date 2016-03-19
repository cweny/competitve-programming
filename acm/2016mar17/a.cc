#include<iostream>

using namespace std;

int n,b,t;


int main(void) {
    while(cin >> n) {
        cin >> b >> t;
        int bb = 0, bt = 0;
        int bans = 0, tans = 0;
        while(n) {
            if(bb) {
                bb--;
                bans++;
            } else {
                if(n>=b) {
                    bb = b;
                    n-=b;
                } else {
                    bb = n;
                    n=0;
                }
            }
            
            
            
            if(bt) {
                bt--;
                tans++;
            } else {
                if(n>=t) {
                    bt = t;
                    n -= t;
                } else {
                    bt = n;
                    n=0;
                }
            }
        }
        bans += bb;
        tans += bt;
        cout << bans << " " << tans << endl;
    }
    
}