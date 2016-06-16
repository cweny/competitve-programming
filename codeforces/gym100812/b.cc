#include<iostream>
#include<map>
#include<string>


using namespace std;
map<string,int> om;
int j,t;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin >> j >> t;
	for(int i=0; i<j; i++) {
		string s; cin >> s;
		int count = 0;
		for(int i=0; i<t; i++) {
			if(s[i] == '1') count++;
			if(count > 15) break;
		}
		if(count >= 8 && count <=15) om[s]++;
	}
	int ans = -1;
	string sans;
	for(auto x:om) {
		if(x.second > ans) {
			ans = x.second;
			sans = x.first;
		}
	}
	if(ans == -1) {
		for(int i=0; i<8; i++) {
			sans += '1';
		}
		for(int i=8; i<t; i++) {
			sans += '0';
		}
	}
	cout << sans << endl;
	return 0;
}