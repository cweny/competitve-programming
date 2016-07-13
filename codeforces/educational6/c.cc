#include<iostream>
#include<utility>
#include<vector>
#include<set>

#define pii pair<int, int>
using namespace std;


int arr[300005], n;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    set<int> os;
    vector<pii> vans;
    int first = 0;
    bool ok = false;
    for(int i=0; i<n; i++) {
        int x = arr[i];
        if(os.find(x) != os.end()) {
            ok=true;
            vans.push_back({first+1, i+1});
            first = i+1;
            os.clear();
        } else {
            os.insert(x);
        }
    }
    if(!vans.empty())
        vans[vans.size()-1].second = n;
    if(ok) {
        cout << vans.size() << endl;
        for(auto x:vans) {
            cout << x.first << " " << x.second << endl;
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}