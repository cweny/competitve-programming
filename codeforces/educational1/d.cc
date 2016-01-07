#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<cstring>
#define pii pair<int, int>

using namespace std;

vector<string> m;
set<pii> s;
bool seen[1005][1005];
int X,Y,Q;
int ans;
int resmap[1005][1005];
int results[1000005];
//m[y][x]

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
//up - down - left - right

void dfs(int x, int y, int res) {
    if(seen[y][x]) return;
    seen[y][x]=true;
    if(m[y][x]=='*') return;
    resmap[y][x]=res;
    for(int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
        //cout << ny << " " << nx << endl;
        if(m[ny][nx]=='*') {
         //   cout << "saw: " << "(" << ny << "," << nx << ") at: (" << y << "," << x << ")" << endl;
            ans++;
        }
    }
    for(int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx < 0 || nx >= X || ny < 0 || ny >= Y) continue;
        if(m[ny][nx]=='.') {
            dfs(nx,ny, res);
        }
    }
}

int main(void) {
    cin >> Y >> X >> Q;
    for(int i=0; i<Y; i++) {
        string str; cin >> str;
        m.push_back(str);
    }
    memset(seen, 0, sizeof seen);
    for(int i=0; i<Q; i++) {
        int x, y; cin >> y >> x;
        x--; y--;
        
        ans=0;
        if(seen[y][x]) {
            cout << results[resmap[y][x]] << endl;
            continue;
        }
        dfs(x,y,i);
        cout << ans << endl;
        results[i]=ans;
    }
    return 0;   
}