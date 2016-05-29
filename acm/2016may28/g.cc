#include<iostream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int w,h,px,py;
vector<string> g;
bool seen[51][51];
int ans;
void dfs(int x, int y) {
    seen[y][x] = true;
    if(g[y][x] == 'G') ans++;
    for(int i=0; i<4; i++) {
        
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx < 0 || tx >= w || ty < 0 || ty >= h) continue;
        if(g[ty][tx] == 'T') return;
    }
    for(int i=0; i<4; i++) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx < 0 || tx >= w || ty < 0 || ty >= h) continue;
        if((g[ty][tx] == '.' || g[ty][tx] == 'G') && !seen[ty][tx]) dfs(tx,ty);
    }
}


int main(void) {
    cin >> w >> h;
    for(int i=0; i<h; i++) {
        string s; cin >> s;
        for(int k=0; k<s.size(); k++) {
            if(s[k]=='P') {
                px = k;
                py = i;
            }
        }
        g.push_back(s);
    }
    
    memset(seen, 0, sizeof seen);
    ans = 0;
    dfs(px,py);
    cout << ans << endl;
    return 0;
}