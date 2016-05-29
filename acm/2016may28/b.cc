#include<iostream>
#include<cmath>
using namespace std;

int main(void) {
    long long a,b;
    cin >> a >> b;
    if(pow(2,b+1)-1 >= a) cout << "yes" << endl;
    else cout << "no" << endl;
    return 0;
}