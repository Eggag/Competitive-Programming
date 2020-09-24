#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int ind = 0;
int a[mxN], b[mxN];

//https://github.com/superj6/CPcode/blob/master/c%2B%2B%20sol/CSES/Range%20Queries/range_update_queries.cpp

struct segTree{ //rythm orz
	int l, r;
	segTree *left, *right;
	ll val = 0, lazy = 0;
	
	segTree(int a, int b){
		l = a;
		r = b;
		if(l != r){
			int mid = (l + r) / 2;
			left = new segTree(l, mid);
			right = new segTree(mid + 1, r);
		}
	}
	
	void add(int a, int b, int v){
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			lazy = v;
			val = v;
			return;
		}
		if(lazy) val = lazy;
		if(lazy) left->lazy = lazy;
		left->add(a, b, v);
		if(lazy) right->lazy = lazy;
		right->add(a, b, v);
		lazy = 0;
	}

	ll qry(int a, int b){
		if(lazy) val = lazy;
		if(r < a || b < l) return 0;
		if(a <= l && r <= b) return val;
		if(lazy){
			left->lazy = lazy;
			right->lazy = lazy;
		}
		lazy = 0;
		return max(left->qry(a, b), right->qry(a, b));
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	repn(i, 1, n + 1) cin >> a[i];
	repn(i, 1, n + 1) cin >> b[i];
	vector<array<int, 3>> op;
	segTree tree(1, n);
	rep(i, m){
		int t;
		cin >> t;
		if(t == 1){
			int x, y, k;
			cin >> x >> y >> k;
			op.pb({x, y, k});
			ind++;
			tree.add(y, y + k - 1, ind);
		}
		else{
			int nm;
			cin >> nm;
			int r = tree.qry(nm, nm);
			if(!r) cout << b[nm] << endl;
			else{
				r--;
				cout << a[op[r][0] + (nm - op[r][1])] << endl;
			}
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
