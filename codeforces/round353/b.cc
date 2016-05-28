#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

#undef int
int main(void) {
#define int long long
	int n, a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	int arr[4];
	arr[0]=a+b; arr[1]=b+d; arr[2]=c+d; arr[3]=c+a;
	sort(arr, arr+4);
	int M = arr[3], m=arr[0];
	int k = m+n-M;
	if(k<0) cout << 0;
	else cout << k*n;
	cout << endl;
	
	return 0;
}