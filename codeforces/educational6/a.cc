#include<iostream>
#include<algorithm>

using namespace std;

int main(void) {
    long long x1,x2,y1,y2,dx,dy;
    cin >> x1 >> y1 >> x2 >> y2;
    dx = x1-x2;
    dy = y1-y2;
    dx = dx<0 ? -dx:dx;
    dy = dy<0 ? -dy:dy;
    cout << max(dx,dy) << endl;
}