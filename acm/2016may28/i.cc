#include<iostream>
#include<set>
#include<algorithm>
#include<cstring>
#include<vector>

#define int long long
#define pii pair<int, int>

using namespace std;
const int inf = 1000000000;
bool cache[100000];
int csize,obj,acc;
int arr[100000];
int last_access[100000];
vector<int> vec[100000];

struct comp {
	bool operator() (const int a, const int b) const {
		return last_access[a] > last_access[b];
	}
};

// set<int , comp> os;
set<pii> os;
int ans, ccount;
#undef int
int main(void) {
#define int long long
	cin >> csize >> obj >> acc;
	for(int i=0; i<acc; i++) cin >> arr[i];
	for(int i=0; i<100000; i++) {
		last_access[i] = inf;
		cache[i] = 0;
	}
	// memset(last_access, -1, sizeof last_access);
	// memset(cache, 0, sizeof cache);
	for(int i=acc-1; i>=0; i--) {
		vec[arr[i]].push_back(i);
	}
	for(int i=0; i<obj; i++) {
		if(vec[i].size() != 0) {
			vec[i].pop_back();
		}
	}
	ans = 0, ccount = 0;
	for(int i=0; i<acc; i++) {
		if(cache[arr[i]] == true) {
			os.erase(os.find({last_access[arr[i]],arr[i]}));
			if(vec[arr[i]].size() != 0) {
				last_access[arr[i]] = vec[arr[i]].back();
				vec[arr[i]].pop_back();
			} else {
				last_access[arr[i]] = inf;
			}
			os.insert({last_access[arr[i]], arr[i]});
			continue;
		}
		if(ccount < csize) {
			cache[arr[i]] = true;
			ccount++;
			if(vec[arr[i]].size() == 0) {
				last_access[arr[i]] = inf;
			} else {
				last_access[arr[i]] = vec[arr[i]].back();
				vec[arr[i]].pop_back();
			}
			os.insert({last_access[arr[i]], arr[i]});
			ans++;
			continue;
		}
		int rem = (os.rbegin())->second;
		cache[rem] = false;
		os.erase(--os.end());
		if(vec[arr[i]].size() == 0) {
			last_access[arr[i]] = inf;
		} else {
			last_access[arr[i]] = vec[arr[i]].back();
			vec[arr[i]].pop_back();
		}
		os.insert({last_access[arr[i]],arr[i]});
		cache[arr[i]] = true;
		ans++;
	}

	cout << ans << endl;

	return 0;
}
