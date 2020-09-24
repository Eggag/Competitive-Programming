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
const int MOD = 1e9 + 7;
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
struct matrix{
	ll mat[mxN][mxN];
	matrix(){
		rep(i, mxN) rep(j, mxN) mat[i][j] = 0;
	}
};

ll a[mxN];
int n;

bool good(ll a1, ll b){
	ll nm = a1 ^ b;
	int ans = 0;
	for(int i = 0; i < 63; i++) if((1LL << i) & nm) ans++;
	return (ans % 3 == 0);
}


matrix mul(matrix a1, matrix b){
	matrix c;
	rep(i, n) rep(j, n) rep(k, n){
		(c.mat[i][j] += (a1.mat[i][k] * b.mat[k][j]) % MOD) %= MOD;
	}
	return c;
}
 
matrix binPow(matrix a, ll n){
	matrix res = a;
	n--;
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
	ll k;
	cin >> n >> k;
	matrix cur;
	rep(i, n) cin >> a[i];
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	rep(i, n) rep(j, n) if(good(a[i], a[j])) cur.mat[i][j] = 1;
	k--;
	matrix ans = binPow(cur, k);
	ll res = 0LL;
	rep(i, n) rep(j, n) (res += ans.mat[i][j]) %= MOD;
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
