#include <bits/stdtr1c++.h>
using namespace std;

bool used[100006] = {false};
int g[100006];

int main() {
    int G, P; 
    cin >> G >> P;
    for (int i=1; i<=P; i++) {
        cin >> g[i];
    }
    for (int i=1; i<=P; i++) {
        int gate = g[i];
        bool docked = false;
        for (int j=gate; j>=1; j--) {
            if (used[j]) continue;
            docked = true;
            used[j] = true;
            break;
        }
        if (!docked) {
            cout << i-1 << endl;
            return 0;
        }
    }
    cout << P << endl;
}
