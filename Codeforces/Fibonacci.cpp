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
const int mxN = 2;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
struct matrix{
	ll mat[mxN][mxN];
	matrix(){
		rep(i, mxN) rep(j, mxN) mat[i][j] = 0;
	}
};
 
 
matrix mul(matrix a, matrix b){
	matrix c;
	rep(i, mxN) rep(j, mxN) rep(k, mxN){
		(c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD) %= MOD;
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
	ll n;
	cin >> n;
	if(n == 0){
		cout << 0 << endl;
		return 0;
	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	matrix cur;
	cur.mat[0][0] = 0;
	cur.mat[0][1] = 1;
	cur.mat[1][0] = 1;
	cur.mat[1][1] = 1;
	matrix ans = binPow(cur, n);
	cout << ans.mat[1][0] << endl;	
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
