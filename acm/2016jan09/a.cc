#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

struct edge {
    int a, b, w;
};

int n;
int mat[2005][2005];

bool cmp(const edge &e1, const edge &e2) {
    if (e1.w==e2.w) {
        if (e1.a==e2.a)
            return e1.b < e2.b;
        else return e1.a<e2.a;
    }
    else
    return e1.w<e2.w;
}

int main() {
    while (cin >> n) {
        memset(mat, 0, sizeof mat);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                cin >> mat[i][j];
        vector<edge> v;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                edge e;
                e.a=j; e.b=i; e.w=mat[i][j];
                v.push_back(e);
            }
        }
        sort(v.begin(), v.end(), cmp);
        int x=0;
        for (auto e : v) {
            if (x==n) break;
            cout << e.a << " " << e.b << " " << e.w << endl;
            x++;
        }
        cout << endl;
    }
}