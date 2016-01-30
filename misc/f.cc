#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct person {
  int h,w,s;
};

/*
http://www.ugrad.cs.ubc.ca/~cs490/2015W2/judge/assn1/
*/

// maximum amount of weight that can be added to the top of the best stack
int memo[1<<21];
int heights[1<<21];

person arr[20];
int N,H,answer;

void print(int bm) {
    for(int i=N-1; i>=0; i--) {
        if(bm & (1<<i)) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}
int dp(int bm) {
    // cout << "getting memo for " << bm << endl;;
    if(memo[bm] != -1) return memo[bm];
    
    int ans = -2;
    for(int i=0; i<N; i++) {
        
        if( (bm & (1<<i)) == 0) continue;
        
        int sub_bm = bm & ~(1<<i);
        // if(bm == 6) {
        //     cout << "   getting ";
        //     print(sub_bm);
        //     cout << endl;
        // }
        int sub_dp = dp(sub_bm);
        // if(bm == 6) {
        //     cout << "   got " << sub_dp << endl;
        //     cout << "   weight of person " << i << ": " << arr[N-i-1].w << endl;
        // }
        if(sub_dp>=arr[N-i-1].w) {
            ans = max(ans, min(sub_dp-arr[N-i-1].w, arr[N-i-1].s));
        }
    }
    
    return memo[bm]=ans;
}

void recur_heights(int p, int bm, int height_so_far) {
    if(p==N) {
        heights[bm] = height_so_far;
        return;
    }
    recur_heights(p+1,bm,height_so_far);
    recur_heights(p+1,bm | (1<<p), height_so_far+arr[N-p-1].h);
}

int main(void) {
    int t; cin >> t;
    
    while(t--) {
        cin >> N >> H;
        for(int i=0; i<N; i++) {
            int h,w,s; cin >> h >> w >> s;
            arr[i].h = h;
            arr[i].w = w;
            arr[i].s = s;
        }
        int temp = 0;
        recur_heights(0,0,0);
        memset(memo, -1, sizeof memo);
        for(int i=0; i<N; i++) {
            memo[1<<i] = arr[N-i-1].s;
            temp |= 1<<i;
        }
        memo[0]=0;
        dp(temp);
        answer = -1;
        for(int i=0; i<(1<<N); i++) {
            // cout << heights[i] << endl;
            if(heights[i] >= H) {
                answer = max(answer,memo[i]);
            }
            // cout << memo[i] << " " << heights[i]<< endl;
        }
        if(answer<0) {
            cout << "Too tall" << endl;
        } else {
            cout << answer << endl;
        }
        // cout << endl;
        // cout << dp(temp) << " " <<  endl << endl;;
    }
    return 0;
}