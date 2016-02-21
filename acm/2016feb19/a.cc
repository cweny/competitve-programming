#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int p,a,b,c,d,n;
double arr[1000001], diff[1000001];

double maxSubArraySum(double a[], int size)
{
    double max_so_far = 0, max_ending_here = 0;
 
    for (int i = 1; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main(void) {
    cin >> p >> a >> b >> c >> d >> n;
    for(int i=1; i<=n; i++) {
        arr[i]=p*(sin(a*i+b)+cos(c*i+d)+2);
    }
    for(int i=1; i<n; i++) {
        diff[i] = arr[i]-arr[i+1];
    }
    // double res = 0;
    // double sum = 0;
    // for (int i = 0; i< n;i ++){
    //     if(sum + diff[i] < 0) {
    //         sum = 0;
    //     } else {
    //         sum += diff[i];
    //     }
    //     res = max(res, sum);
    // }
    cout <<fixed<<setprecision(6)<< maxSubArraySum(diff,n)<< endl;
    return 0;
}