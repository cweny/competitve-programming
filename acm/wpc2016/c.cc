#include<iostream>
#include<math.h>


using namespace std;


int main(void) {
    
    int r,p;
    
    while(cin >> r) {
        cin >> p;
        r++;
        int R = r*p - abs(r-p);
        r--;
        p++;
        int P = r*p - abs(r-p);
        if(R>P) {
            cout << "Technical"     << endl;
        } else if (P>R) {
            cout << "Interpersonal"     << endl;
        } else {
            cout << "Either"     << endl;
        }
    }
    
    return 0;
}