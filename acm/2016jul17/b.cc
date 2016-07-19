#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<set>

#define int long long
#define pii pair<int, int>

using namespace std;
const int N=505, inf = 10000000000000000;
int h,w,d,
dx[] = {1,0,-1,0},
dy[] = {0,1,0,-1};
vector<string> m; //m[h][w]

int dist[N][N];
bool seen[N][N];

int cost(int y, int x) {
    if(m[y][x] == '.') return 1;
    else if(m[y][x] == '@') return d+1;
    return inf;
}

struct cmp {
    bool operator()(const pii& u, const pii& v) {
        if ( dist[u.first][u.second] == dist[v.first][v.second] ) {
            return true;
        }
        else return dist[u.first][u.second] < dist[v.first][v.second];
    }
};
void dijkstra( pii s ) {
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            dist[i][j] = inf;
        }
    }
    dist[s.first][s.second] = 0;
    seen[s.first][s.second] = true;
    set<pii, cmp> q;
    q.insert(s);
    while ( !q.empty() ) {
        pii v = *q.begin();
        seen[v.first][v.second] = true;
        q.erase(q.begin());
        for (int i=0; i<4; i++) {//each edge e = (v, u) leaving v
            pii u;
            u.first = v.first+dx[i];
            u.second = v.second+dy[i];
            if(u.first >= h || u.first < 0 || u.second >= w || u.second < 0) {
                cout << dist[v.first][v.second]+1 << endl;
                return;
            }
            // cout << u.first << " " << u.second << endl;
            if(m[u.first][u.second] == 'S' || m[u.first][u.second] == '#') continue;
            if(seen[u.first][u.second]) continue;
            int distance = dist[v.first][v.second] + cost(u.first, u.second);
            if ( distance < dist[u.first][u.second] ) {
                q.erase(u);
                dist[u.first][u.second] = distance;
                q.insert(u);
            }
        }
    }
}

#undef int
int main(void) {
#define int long long
    int T; cin >> T;

    while(T--) {
        cin >> h >> w >> d;
        m.clear();
        memset(seen, 0, sizeof seen);
        for(int i=0; i<h; i++) {
            string s; cin >> s;
            m.push_back(s);
        }
        pii s;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(m[i][j] == 'S') {
                    s.first = i; s.second=j;
                    break;
                }
            }
        }
        dijkstra(s);
        // int ans = inf;
        // for(int i=0; i<h; i++) {
        //     if(m[i][0] != 'S' && m[i][0] != '#')
        //     ans = min(ans, dist[i][0]);
        //
        //     if(m[i][w-1] != 'S' && m[i][w-1] != '#')
        //     ans = min(ans, dist[i][w-1]);
        // }
        // for(int i=0; i<w; i++) {
        //     if(m[0][i] != 'S' && m[0][i] != '#')
        //     ans = min(ans, dist[0][i]);
        //
        //     if(m[h-1][i] != 'S' && m[h-1][i] != '#')
        //     ans = min(ans, dist[h-1][i]);
        // }
        // cout << ans+1 << endl;
    }

    return 0;
}
