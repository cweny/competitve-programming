#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


int main(void) {
    
    vector<string> vec;
    for(int i=0; i<8; i++)     {
        string s; cin >> s;
        vec.push_back(s);
    }
    //A-white-to0
    //B-black-to7
    int min_white = 100;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(vec[j][i] == 'B') {
                break;
            } else if(vec[j][i] == 'W'){
                min_white = min(j,min_white);
                break;
            }
        }
    }
    
    int min_black = 100;
    for(int i=0; i<8; i++) {
        for(int j=7; j>=0; j--) {
            if(vec[j][i] == 'W') {
                break;
            } else if(vec[j][i] == 'B') {
                min_black = min(min_black, 7-j);
                break;
            }
        }
    }
    cout<< min_white << " " << min_black << endl;
    if(min_white <= min_black) {
        cout << "A" << endl;
    } else {
        cout << "B" << endl;
    }
    return 0;
}