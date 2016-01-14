#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<iomanip>

using namespace std;


char cards[100];
int flipped[10000];
long double memo[10000];
int n, m, num_cards;


int main(void) {
    while(cin >> n) {
        cin >> m;
        for(int i=0; i<n; i++) {
            string tmp; cin >> tmp;
            if(tmp.size() > 1) {
                cards[i] = 'J';
            }
            else {
                cards[i] = tmp[0];
            }
        }
        num_cards = m;
        int so_far = m-1;
        memset(flipped, 0, sizeof flipped);
        for(int i=0; i<n; i++) {
            int to_add;
            // cout << cards[i] << endl;
            if(cards[i] >= '1' && cards[i] <='9') {
                num_cards += cards[i]-'0';
                to_add = cards[i] - '0';
            } else if(cards[i] == 'A') {
                num_cards += 11;
                to_add = 11;
            } else {
                num_cards += 10;
                to_add = 10;
            }
            if(i==n-1)
                num_cards -= to_add;
            flipped[so_far] = to_add;
            
            so_far += to_add;
        }
        
        // for(int i=0; i<num_cards; i++) {
        //     cout << flipped[i] << " ";
        // }cout << endl;
        // cout << num_cards << endl;
        
        memo[0] = 1.0/10;
        for(int i=1; i<num_cards; i++) {
            double p=0;
            if(i<10 ) {
                p+=(1/10.0);
            }
            
            for(int j=max(0, i-11); j<i-1; j++) {
                if(flipped[j]>0 ) {
                    if(j+flipped[j]==i) {
                        // cout << flipped[i] << endl;
                        p += memo[j];
                    }
                } else {
                    if(i-j == 10) {
                        p += memo[j]*4.0/13.0;
                    } else {
                        p += memo[j]/13.0;
                    }
                }
                // cout << p << endl;
            }
            memo[i] = p;
        }
        // for(int i=0; i<num_cards; i++) {
        //     cout << flipped[i] << " ";
        // }cout << endl;
        cout << fixed << setprecision(25) << memo[num_cards-1] << endl;;
    }
    
    
    return 0;
}