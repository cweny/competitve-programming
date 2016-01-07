#include<iostream>
#include<string>

using namespace std;

char table[105][105];

int get(int n) {
    int ans=1;
    while(ans*ans<n) ans++;
    return ans;
}

int main (void) {
    
    int t;cin>>t;
    while(t--) {
        string s;cin>>s;
        int n=get(s.size());
        unsigned idx=0;
        for(int i=0; i<n; i++) {
            for(int j=0;j<n;j++) {
                if(idx<s.size()) {
                    table[i][j]=s[idx++];
                } else {
                    table[i][j]='*';
                }
            }
        }
        
        /*
        for(int i=0; i<n; i++) {
            for(int j=0;j<n;j++) {
                cout << table[i][j] << " ";
               
            }
            cout << endl;
        }*/
        for(int i=0; i<n; i++) {
            for(int j=n-1;j>=0;j--) {
                if(table[j][i]!='*') {
                    cout << table[j][i];
                }
            }
        }
        cout << endl;
    }
    return 0;
}
