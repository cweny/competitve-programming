#include<iostream>
#include<string>
#include<vector>

using namespace std;

char arr[2501][2501];
int ns[2501][2501], ms[2501][2501];
vector<string> vec;
int n,m;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        string s; cin >> s;
        vec.push_back(s);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i>0)
                ns[j][i] = ns[j][i-1];
            if(vec[i][j] == '#') ns[j][i]++;
                
        }
    }
    for(int j=0; j<m; j++) {
        for(int i=0; i<n; i++) {
            if(j>0)
                ms[i][j] = ms[i][j-1];
            if(vec[i][j] == '#') ms[i][j]++;
        }
    }
    int q; cin >> q;
    while(q--) {
        int n1, m1, n2, m2; cin >> n1 >> m1 >> n2 >> m2;
        
    }
}