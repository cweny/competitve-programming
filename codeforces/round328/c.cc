#include<iostream>
#include<cmath>

using namespace std;
int gcd(int a, int b) {
     int c;
      while ( a != 0 ) {
         c = a; a = b%a;  b = c;
      }
      return b;
}
int main(void) {
    int t,w,b; cin >> t >> w >> b;
    cout << t/(w/gcd(w,b) + w/gcd(w,b)) << endl;
    cout << t/(w/gcd(w,b) + w/gcd(w,b)) << endl;
    
    return 0;
}