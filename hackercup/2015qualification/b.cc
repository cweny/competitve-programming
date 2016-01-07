#include<iostream>

using namespace std;

int T;
int n;
int a[20], b[20], c[20], A, B, C;

bool recur(int thisa, int thisb, int thisc, int bm) {
    // cout << bm << endl;
    if(bm >= n) {
        return thisa == A && thisb == B && thisc == C;
    }
        
    if(recur(thisa, thisb, thisc, bm+1))
        return true;
    thisa += a[bm];
    thisb += b[bm];
    thisc += c[bm];
    
    if(recur(thisa,thisb,thisc,bm+1))
        return true;
    return false;
}

int main(void) {
    cin >> T;
    int ca=0;
    while(T--) {
        cout << "Case #" << ++ca << ": ";
      cin >> A >> B >> C;
      cin >> n;
      
      for(int i=0; i<n; i++) {
          cin >> a[i] >> b[i] >> c[i];
      }
    //   cout << n << endl;
      
      if(recur(0,0,0,0)) {
          cout << "yes" << endl;
      } else {
          cout << "no" << endl;
      }
    }
    return 0;
}