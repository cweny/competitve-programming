#include<iostream>

using namespace std;

int main(void) {
    int bm = 3;
    for(int i=0; i<5; i++) {
        int nbm = bm & (1<<i);
        cout << nbm << endl;
    }
    return 0;
}