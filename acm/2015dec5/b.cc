#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int const inf = 100000000;
int memo[55][55];
char grid[55][55];
int h,w;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int dp(int i, int j) {
    if(memo[i][j] != -1) return memo[i][j];
    int res = 1;
    
    for(int idx=0; idx<8; idx++) {
        int ni = i+dy[idx];
        int nj = j+dx[idx];
        
        if(ni<0 || ni>=h || nj<0 || nj>=w) continue;
        if(grid[ni][nj] != grid[i][j]+1) continue;
        
        res = max(res,1+dp(ni,nj));
    }
    
    return memo[i][j]=res;
}

int main(void) {
    int ca = 0;
    // bool flag = false;
    while(1) {
       
        cin >> h >> w;
        if(h==0 && w==0)
            break;
        cout << "Case " << ++ca << ": ";
        int ans = 0;
        memset(memo, -1, sizeof memo);
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin >> grid[i][j];
            }
        }
        // cout << endl;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(grid[i][j]=='A')
                    ans = max(ans, dp(i,j));
                //cout << dp(i,j) << " ";
            }// cout << endl;
        }//cout << endl;
        if(h==0 || w==0) ans = -1;
        cout << ans<<endl;
    }
    // cout<<endl;
    return 0;
}