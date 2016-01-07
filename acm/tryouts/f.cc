#include<string>
#include<iostream>
#include<vector>
using namespace std;
//int n='z'-'a'+1;
bool lo[26],up[26];

int main(void) {
    int t;cin>>t;
    string tmp;getline(cin,tmp,'\n');
    while(t--){
        string s;getline(cin,s);
        for(int i=0; i<26;i++) {
            lo[i]=false;up[i]=false;
        }
        
        for(unsigned i=0; i<s.size();i++) {
            if(s[i]>='a' && s[i]<='z') {
                lo[s[i]-'a']=true;
                //cout << "got" << s[i] << endl;
            }
            
            if(s[i]>='A'&&s[i]<='Z') {
                up[s[i]-'A']=true;
                //cout << "got" << s[i] << endl;
            }
        }
        bool ok=true;
        for(int i=0; i<26;i++) {
            if(lo[i]==false && up[i]==false) {
                if(ok==true) {
                    ok=false; cout << "missing ";
                }
                cout << char(i+'a') ;
            }
        }
        if(ok) cout << "pangram";
        cout << endl;
    }
    return 0;
}
