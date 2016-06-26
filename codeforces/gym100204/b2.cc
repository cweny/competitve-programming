#include<iostream>
#include<cmath>

#define int long long

using namespace std;

int r,n,m;
struct matrix {
	int a,b,c,d;
	matrix operator*(const matrix & y) {
		matrix res;
		res.a = ((a*y.a)%r + (b*y.c)%r)%r;
		res.c = ((c*y.a)%r + (d*y.c)%r)%r;
		res.b = ((a*y.b)%r + (b*y.d)%r)%r;
		res.d = ((c*y.b)%r + (d*y.d)%r)%r;
		return res;
	}
	void print() {
		cout << a << " " << b << endl;
		cout << c << " " << d << endl;
	}
};
matrix arr[30000];
matrix sqr[3000];
#undef int
int main(void) {
#define int long long
	//ios::sync_with_stdio(0); cin.tie(0);
	freopen("crypto.in", "r", stdin);
	freopen("crypto.out", "w", stdout);
	cin >> r >> n >> m;
	for(int i=0; i<n; i++) {
		int a,b,c,d; cin >> a >> b >> c >> d;
		arr[i].a=a; arr[i].b=b; arr[i].c=c; arr[i].d=d;
	}
	int n2 = sqrt(n);
	int idx = 0;
	matrix tmp;
	for(int i=0; i<n; i++) {
		if(i%n2 == 0) {
			tmp = arr[i];
		} else {
			tmp = tmp * arr[i];
		}
		if(i%n2 == n2-1) {
			sqr[idx] = tmp;	
			idx++;
		}
	}
	if(n<100 && false) {
		for(int i=0; i<m; i++) {
			int s,e; cin >> s >> e;
			s-=1; e-=1;
			matrix ans = arr[s];
			for(int i=s+1; i<=e; i++) {
				ans = ans * arr[i];
			}
			ans.print();
			cout << endl;
		}
		return 0;
	}
	for(int i=0; i<m; i++) {
		int s,e; cin >> s >> e;
		s-=1; e-=1;
		/*	
		if(e-s <= n2) {
			matrix ans = arr[s];
			for(int i=s+1; i<=e; i++) {
				ans = ans * arr[i];
			}
			ans.print();
			cout << endl;
		}*/
		matrix ans = arr[s];
		for(int i=s+1; i<=e; i++) {
			if(i%n2 == 0 && i+n2-1 <= e) {
				ans = ans * sqr[i/n2];
				i+=(n2-1);
			} else {
				ans = ans * arr[i];
			}
		}
		ans.print();
		cout << endl;
	}
	return 0; 
}
