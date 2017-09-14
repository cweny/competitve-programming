#include<iostream>

using namespace std;

int main(void) {
    
    long double x[20],y[20];
    for(int i=0; i<11; i++) {
        cin >> x[i];
    }

    for(int i=0; i<11; i++) {
        cin >> y[i];
    }
    for(int i=0; i<11; i++) {
        // cout << x[i] << " " << y[i] << endl;
    }
    for(int i=1; i<11; i++) {
        cout <<( y[i] - y[i-1])/(x[i] - x[i-1]) << endl;
    }
}