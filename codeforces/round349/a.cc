#include<iostream>
#include<iomanip>


using namespace std;
const double PI = 3.14159265358979323846;
int main(void) {
    int d,h,v,e;
    
    cin >> d >> h >> v >> e;
    double a = (double)d/2;
    a = a*a*PI;
    double s = (double)v;
    s = s/a;
    //cout << s << " " << a << endl;
    s = s-e;
    if(s<0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << fixed << setprecision(8) <<  (double)h/s << endl;
    }
    return 0;
}