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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct matrix{
	ll mat[105][105];
	matrix(){
		rep(i, 105) rep(j, 105) mat[i][j] = 0;
	}
};
 
int k, x;
 
matrix mul(matrix a, matrix b){
	matrix c;
	rep(i, x) rep(j, x) rep(k, x){
		(c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % MOD) %= MOD;
	}
	return c;
}
 
matrix binPow(matrix a, ll n){
	matrix res = a;
	while(n > 0){
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
	int n, b;
	cin >> n >> b >> k >> x;
	vi a(n);
	vi num(10, 0);
	rep(i, n) cin >> a[i], num[a[i]]++;
	matrix cur;
	rep(i, x) rep(j, 10){
		(cur.mat[i][((i * 10) + j) % x] += num[j]) %= MOD;
	}
	matrix ans = binPow(cur, b - 1);
	cout << ans.mat[0][k] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
