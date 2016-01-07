#include<iostream>
#include<string>

using namespace std;

int main(void) {
    int t;cin>>t;
    string tmp;getline(cin,tmp,'\n');
    while(t--) {
        //cout << t << endl;
        string s; getline(cin,s,'\n');
        //cout << s << endl;
        if(s.size()>10 && s[0]=='S' && s[1]=='i' &&s[2]=='m' && s[3]=='o'&&s[4]=='n' && s[5]==' ' && s[6]=='s' &&s[7]=='a'&&s[8]=='y'&&s[9]=='s') {
          //cout << true <<s<< endl;
          cout << s.substr(10,string::npos) << endl;
        } 
    }
    return 0;
}