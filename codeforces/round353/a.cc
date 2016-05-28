#include<iostream>

using namespace std;

int main(void) {
	int a,b,c; cin >> a >> b >> c;
	if(c==0) {
		(a==b) ? cout << "YES" << endl : cout << "NO" << endl;
		return 0;
	}
	if((b-a)%c == 0 && (b-a)/c >= 0) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	cout << endl;
	return 0;
}