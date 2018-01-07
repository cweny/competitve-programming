#include<iostream>
#include<string>

using namespace std;

int main() {
    string s; cin >> s;
    if(s.size() < 3) {
        cout << "boring..." << endl; return 0;
    }
    for(int i=0; i<s.size()-2; i++) {
        if(s[i] == 'A' && s[i+1] == 'C' && s[i+2] == 'M') {
            cout << "Fun!" << endl;
            return 0;
        }
    }
    cout << "boring..." << endl;
    
}