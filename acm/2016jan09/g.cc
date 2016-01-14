#include<iostream>
#include<algorithm>
using namespace std;
int a, b ,c;
int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    while(cin >> a ) {
        cin >> b >> c;
        int num = a *b;
        int deno = c - b;
        int g = gcd(max(num, deno), min(num, deno));
        num  /= g;
        deno /=g;
        cout << num << "/" << deno << "\n";
 }
 return 0;
}