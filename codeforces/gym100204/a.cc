#include<iostream>

using namespace std;

int main(void) {
//	ios::sync_with_stdio(0); cin.tie(0);
	freopen("assign.in", "r", stdin);
	freopen("assign.out", "w", stdout);
	int n; cin >> n;
	for(int i=0; i<n; i++) cout << i << " ";
	cout << endl;
	cout << "0 ";
	for(int i=1; i<n; i++) cout << "100 ";
	cout << endl;
	for(int i=2; i<n; i++) {
		for(int i=0; i<n; i++) {
			cout << "1 ";
		}cout << endl;
	}
	return 0;
}
