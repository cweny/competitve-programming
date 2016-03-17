#include<iostream>
#include<string>
#include<stack>

using namespace std;


string s;

bool same(char a,char b) {
    
    return (a=='<' && b=='>')
        || (a=='{' && b=='}')
        || (a=='[' && b==']')
        || (a=='(' && b==')');
}

int f() {
    stack<char> st;
    
    int ans = 0;
    for(char c:s) {
        if(c=='<' 
        || c=='('
        || c=='['
        || c=='{') {
            st.push(c);
        } else {
            if(st.empty()) {
                return -1;
            } else {
                char x = st.top();
                st.pop();
                if(!same(x,c)) {
                    ans++;
                }
            }
        }
    }
    if(!st.empty()) return -1;
    return ans;
}

int main(void) {
    cin >> s;
    int ans = f();
    if(ans < 0) {
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}