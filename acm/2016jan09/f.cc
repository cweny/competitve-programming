#include<iostream>
#include<string>
#include<sstream>

using namespace std;

string s;
int y;
int months[] = {31, 28, 31, 30}


int main() {
    while (cin >> s) {
        stringstream ss(s.substr(0,4));
        ss >> y;
        int month=(s[5]-'0')*10+(s[6]-'0');
        int date=(s[8]-'0')*10+(s[9]-'0');
        
        
        int num_dates = (y-1)*365;
        num_dates += (y-1)/400;
        
        
        
        cout << y << "-";
        if(month < 10) cout << "0";
        cout << month << "-" ;
        if(date < 10) cout << "0";
        cout << date << endl;
    }
}