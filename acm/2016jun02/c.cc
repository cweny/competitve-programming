#include<iostream>
#include<set>
#include<string>
#include<vector>


using namespace std;

string arr[] = {"h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k","ca","sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr","nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe","cs","ba","hf","ta","w","re","os","ir","pt","au","hg","tl","pb","bi","po","at","rn","fr","ra","rf","db","sg","bh","hs","mt","ds","rg","cn","fl","lv","la","ce","pr","nd","pm","sm","eu","gd","tb","dy","ho","er","tm","yb","lu","ac","th","pa","u","np","pu","am","cm","bk","cf","es","fm","md","no","lr"};
set<string> os;

int main(void) {

	int T; cin >> T;
	int idx = 0;
	while(true) {
		os.insert(arr[idx]);
		if(arr[idx] == "lr") break;
		idx++;
	}
	while(T--) {
		string s; cin >> s;
		int n = s.size();
		vector<bool> dp(n);
		for(int i=0; i<n; i++) dp[i] = false;
		string str = "";
		str.push_back(s[n-1]);
		dp[n-1] = os.find(str) != os.end();
		for(int i=n-2; i>=0; i--) {
			string s1 = "";
			s1.push_back(s[i]);
			if(os.find(s1) != os.end() && dp[i+1]) dp[i] = true;
			s1.push_back(s[i+1]);
			if(os.find(s1) != os.end() && (i+2 >= n || dp[i+2])) dp[i] = true;
		}
		if(dp[0]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
