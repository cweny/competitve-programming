#include<iostream>
#include<vector>

using namespace std;

int arr[7][6];
vector<int> vec, ans;
void shift(int idx) {
	int tmp = arr[idx][5];
	for(int i=5; i>=1; i--) {
		arr[idx][i] = arr[idx][i-1];
	}
	arr[idx][0] = tmp;
}
void rot(int idx, int idx2, int x) {
	int count = 0;
	while(arr[idx][idx2] != x) {
		shift(idx);
	}
}
bool f() {
	rot(vec[0], 0, 1);
	for(int i=1; i<=6; i++) {
		rot(vec[i], (i+2)%6, arr[vec[0]][(i+5)%6]);
	}
	
	for(int i=1; i<=5; i++) {
		if(arr[vec[i]][(i+1)%6] != arr[vec[i+1]][(i+4)%6]) {
			return false;
		}
	}
	
	if(arr[vec[6]][1] != arr[vec[1]][4]) return false;
	ans.swap(vec);
	return true;
}

bool recur(int bm) {
	if(bm == (1<<7)-1) {
		return f();
	}
	for(int i=0; i<7; i++) {
		if(bm & 1<<i) continue;
		vec.push_back(i);
		if(recur(bm | 1<<i)) return true;
		vec.pop_back();
	}
	return false;
}

int main(void) {
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		vec.clear();
		for(int j=0; j<7; j++) {
			for(int k=0; k<6; k++) {
				cin >> arr[j][k];
			}
		}
		cout << "Case " << i+1 << ": ";
		
		//return 0;
		if(recur(0)) {
			for(int x:ans) cout << x << " ";
			cout << endl;
		} else {
			cout << "No solution" << endl;
		}
	}
	return 0;
}
