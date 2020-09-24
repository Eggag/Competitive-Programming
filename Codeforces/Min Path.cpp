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
const int mxN = 105;
const ll INF = (ll)(1e18) + 10LL;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
struct matrix{
	ll mat[mxN][mxN];
	matrix(){
		rep(i, mxN) rep(j, mxN) mat[i][j] = 0;
	}
};
 
 
matrix mul(matrix a, matrix b){
	matrix c;
	rep(i, mxN) rep(j, mxN) c.mat[i][j] = INF;
	rep(k, mxN) rep(i, mxN) rep(j, mxN){
		if(a.mat[i][k] != INF && b.mat[k][j] != INF) c.mat[i][j] = min(a.mat[i][k] + b.mat[k][j], c.mat[i][j]);
	}
	return c;
}
 
matrix binPow(matrix a, ll n){
	matrix res = a;
	n--;
	while(n){
		if(n & 1) res = mul(res, a);
		a = mul(a, a);
		n /= 2;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	matrix cur;
	rep(i, mxN) rep(j, mxN) cur.mat[i][j] = INF;
	rep(i, m){
		int a, b;
		ll w;
		cin >> a >> b >> w;
		a--, b--;
		cur.mat[a][b] = w;
	}
	matrix ans = binPow(cur, k);
	ll res = INF;
	rep(i, n) rep(j, n) res = min(ans.mat[i][j], res);
	if(res >= INF) cout << "IMPOSSIBLE" << endl;
	else cout << res << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
