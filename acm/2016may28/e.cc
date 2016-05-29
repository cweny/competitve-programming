#include<iostream>
#include<algorithm>

using namespace std;
const int inf = 100000000;
int num,budget,hotels,weeks;

int main(void) {
    int ans = inf;
    int price, beds;
    
    cin >> num >> budget >> hotels >> weeks;
    
    for(int i=0; i<hotels; i++) {
        cin >> price;
        for(int j=0; j<weeks; j++) {
            cin >> beds;
            if(beds < num) continue;
            ans = min(ans, price*num);
        }
        
    }
    if(ans<=budget)
    cout << ans << endl;
    else
    cout << "stay home" << endl;
    return 0;
}