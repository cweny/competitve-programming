#include<iostream>
#include<string>

using namespace std;


int main() {
    string s; cin >> s;
    int bal = 0;
    for(char c: s) {
        if(c == '(') bal++;
        else bal--;
        if(bal < 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << s;
    for(int i=0; i<bal; i++) cout << ")";
    cout << endl;
    return 0;
}