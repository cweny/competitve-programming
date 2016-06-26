#include<iostream>
#include<cmath>
#include<vector>

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


const int N = 70000;  // limit for array size
matrix tree[2 * N];

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = arr[start];
	//cout << "computing node: " << node << endl;
	//tree[node].print();
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
	//cout << "computing node: " << node << endl;
	//cout << "left: " << endl;
	//tree[2*node].print();
	//cout << "right: " << endl;
	//tree[2*node + 1].print();
	//cout << "res: " << endl;
        tree[node] = tree[2*node] * tree[2*node+1];
	//tree[node].print();
    }
}


matrix query(int node, int start, int end, int l, int r)
{
    if(r < start || end < l)
    {
        // range represented by a node is completely outside the given range
	matrix x;x.a=1; x.b=0; x.c=0; x.d=1;
        return x;
    }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
	//cout << 
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    matrix p1 = query(2*node, start, mid, l, r);
    matrix p2 = query(2*node+1, mid+1, end, l, r);
    matrix res = p1 * p2;
    return res;
}


#undef int
int main(void) {
#define int long long
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("crypto.in", "r", stdin);
	freopen("crypto.out", "w", stdout);
	cin >> r >> n >> m;
	for(int i=0; i<n; i++) {
		int a,b,c,d; cin >> a >> b >> c >> d;
		arr[i].a=a; arr[i].b=b; arr[i].c=c; arr[i].d=d;
	}
	build(1,0,n-1);
	for(int i=0; i<m; i++) {
		int s,e; cin >> s >> e;
		s-=1; e-=1;
/*
		matrix ans = arr[s];
		for(int i=s+1; i<=e; i++) {
			ans = ans * arr[i];
		}
		ans.print();
		cout << endl;
*/
		query(1,0,n-1,s,e).print();
		cout << endl;
	}
	return 0; 
}
