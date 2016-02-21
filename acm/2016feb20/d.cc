#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<algorithm>

using namespace std;

int stot(string s) {
    return s[4]*60 + 
            s[3]*10*60 +
            s[1]*3600 +
            s[0]*10*3600;
}

int main(void) {
    int t; cin >> t;
    while(t--) {
        int n,to; cin >> n >> to;
        to*=60;
        unordered_map<string,int> lin;
        unordered_set<string> us;
        int ans = 0;
        for(int i=0; i<n; i++) {
            string ltime; cin >> ltime;
            int sec = stot(ltime);
            string e; cin >> e;
            if(e=="SERVER") {
                string x; cin >> x;
                lin.clear();
            } else {
                string name; cin >> name;
                us.insert(name);
                string lg; cin >> lg;
                if(lg == "LOG_IN") {
                    // cout << name << endl;
                    lin[name] = sec;
                    int count = 0;
                    for(auto x:lin) {
                        // cout << x.second << " " << x.second+to <<" " << sec << endl;
                        if(x.second + to > sec) {
                            count++;
                        }
                    }
                    ans = max(ans, count);
                } else {
                    auto x = lin.find(name);
                    if(x!=lin.end()) {
                        lin.erase(x);
                    }
                }
            }
        }
        cout << us.size() << " " << ans << endl;
    }
}