#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int const inf = 100000000;
int n,k;
int sum[4005][4005];
int memo[805][4005];

int getint() {
    char c;
    while( (c=getchar())<'0' || c>'9');
    return c-'0';
}
int cost(int s, int e) {
    return sum[e][e] - sum[s-1][e] - sum[e][s-1] + sum[s-1][s-1];
}
void compute(int gon, int l, int r, int optL, int optR) {
    if(l>r) return;
    int m=(l+r)>>1;
    int idx = -1, tmp;
    memo[gon][m] = inf;
    //cout << "range: " << l << " to " << r << endl;
	//cout << " computing " << gon << " gondolas and " << m << "people. " ;
	//cout << "computing from: " << optL << " to " << min(m,optR) ;
	//cout << " computing for: " << m;
	//cout << ".  from: " << optL << " to " << min(m,optR) ;
    for(int i=optL; i<=min(m,optR); i++) {
        tmp = memo[gon-1][i] + cost( n-m+1, n-i);
        if(memo[gon][m] >  tmp) {
            memo[gon][m] = tmp;
            idx = i;
        }
    }
	//cout << ". answer: " << idx << endl;
    if(l==r) return;
    compute(gon,l,m-1,optL,idx);
    compute(gon,m+1,r,idx,optR);
}
int main(void) {
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            sum[i][j] = getint() + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for(int i=1; i<=n; i++) {
        memo[1][i] = cost(n-i+1,n);
    }
    for(int i=2; i<=k; i++) {
        compute(i,1,n,1,n);
        //cout << endl;
    }
    // for(int i=0; i<=n; i++) {
    //     cout << memo[2][i] << " ";
    // }cout << endl;
    printf("%d", memo[k][n]>>1);
    return 0;
}
