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
const int mxN = 130;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct matrix{
	ld mat[mxN][mxN];
	matrix(){
		rep(i, mxN) rep(j, mxN) mat[i][j] = 0;
	}
};
 
 
matrix mul(matrix a, matrix b){
	matrix c;
	rep(i, mxN) rep(j, mxN) rep(k, mxN){
		c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
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
	int n, k;
	cin >> n >> k;
	matrix q, w;
	q.mat[0][0] = 1;
	rep(i, k + 1){
		ld t;
		cin >> t;
		rep(j, mxN) if((j ^ i) < mxN) w.mat[j][j ^ i] = t;
	}
	q = binPow(w, n);
	ld res = 1 - q.mat[0][0];
	cout << fixed << setprecision(7) << res << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
