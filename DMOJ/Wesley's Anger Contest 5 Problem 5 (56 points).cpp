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
const int mxN = 46;
const int MOD = 998244353;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k1;

struct matrix{
	ll mat[mxN][mxN][2][2][10]; //[i][j][partner][shelter][acorns]
	matrix(){
		rep(i, mxN) rep(j, mxN) rep(k, 2) rep(l, 2) rep(m, 10) mat[i][j][k][l][m] = 0;
	}
};
 
 
matrix mul(matrix a, matrix b){
	matrix c;
	rep(i, n) rep(j, n) rep(k, n) rep(l, 2) rep(l1, 2) rep(m, 2) rep(m1, 2) rep(d, k1 + 1) rep(d1, k1 + 1) if((d + d1) <= (k1 + 1)){
		int l2 = (l | l1);
		int m2 = (m | m1);
		int d2 = d + d1 - (k == 3);
		(c.mat[i][j][l2][m2][d2] += (a.mat[i][k][l1][m1][d1] * b.mat[k][j][l][m][d]) % MOD) %= MOD;
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
	int e;
	cin >> n >> e >> k1;
	matrix cur;
	vector<string> s(n);
	rep(i, n){
		cin >> s[i];
		rep(j, n) if(s[i][j] == '1'){
			int nm = (i == 1);
			nm |= (j == 1);
			int nm1 = (i == 2);
			nm1 |= (j == 2);
			int nm2 = (i == 3);
			nm2 += (j == 3);
			cur.mat[i][j][nm][nm1][nm2]++;
		}
	}
	matrix ans = binPow(cur, e - 1);
	ll res = 0;
	(res += ans.mat[0][n - 1][1][1][k1]) %= MOD;
	cout << res << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
