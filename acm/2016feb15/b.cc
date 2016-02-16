#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>

#define pi 3.14159265358979323846264338327950288419716939937510582

using namespace std;

double poli[11], pol[101];
double start, end, inc;
int n;

double integ(float x) {
    double power = x, ans=0;
    for(int i=0; i<=n; i++) {
        double tmp = power*pol[i];
        tmp /= i+1;
        ans += tmp;
        power*=x;
    }
    return pi*ans;
}

double volume(float from, float to) {
    return integ(to)-integ(from);
}

double bs(double val) {
    double a = integ(start);
    double lo=start, hi=end, mid;
    while(lo <= hi) {
        
        mid = lo + (hi-lo)/2;
        double b = integ(mid);
        // cout << lo << " " << mid << " " << hi << " " << b-a << endl;
        if(fabs(b-a-val) <= 0.01) {
            return mid;
        } else if(b-a < val) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return -1;
}

int main(void) {
    int ca = 0;
    while(cin >> n) {
        for(int i=0; i<=n; i++) {
            cin >> poli[i];
        }
        for(int i=0; i<=2*n; i++) {
            pol[i] = 0;
        }
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                
                pol[i+j] += poli[i]*poli[j];
            }
        }
        n=2*n;
        cin >> start >> end >> inc;
        cout << fixed << setprecision(2) << "Case " << ++ca << ": " << volume(start,end) << endl;
        if(inc > volume(start,end)) {
            cout << "insufficient volume" << endl;
            continue;
        }
        
        for(int i=1; i<=min(8,(int)(volume(start,end)/inc)); i++) {
            cout << bs(inc*i)-start << " ";
        }cout << endl;
    }
    
    return 0;
}