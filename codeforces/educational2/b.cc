#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<unordered_map>
#define ll long long
using namespace std;

int n,m;
//int a[2*(int)10e5],b[2*(int)10e5];

int main(void) {
    cin >> n >> m;
    vector<int> vec2;
    vector<int> vec, vec3;
    for(int i=0; i<n; i++) {
        int k; cin >>k;
        vec.push_back(k);
    }
    
    for(int i=0; i<m; i++) {
        int k; cin >> k;
        vec2.push_back(k);
        vec3.push_back(k);
    }
    sort(vec.begin(), vec.end());
    sort(vec2.begin(), vec2.end());
    int i = 0;
    unordered_map<int, int> um;
    
    for(int k=0; k<m; k++) {
        while(i<n && vec[i] <= vec2[k]) i++;
        // cout << vec2[k] << ": " << i << endl;
        um[vec2[k]] = i;
    }
    
    for(int x:vec3) {
        //int dist = 
        // cout << x << ":";
        // cout << distance(os.begin(), upper_bound(os.begin(), os.end(), x)) << " ";
        cout << um[x] << " ";
    }
    cout << endl;
    return 0;
}