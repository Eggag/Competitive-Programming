#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 2005;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(mxN, 0);
	}
	void update(int ind, T delta){
		for(; ind < mxN; ind = ind | (ind + 1)){
			bit[ind] += delta;
			if(bit[ind] < 0) bit[ind] += MOD;
			if(bit[ind] >= MOD) bit[ind] -= MOD;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
			sum += bit[ind];
			if(sum < 0) sum += MOD;
			if(sum >= MOD) sum -= MOD;
		}
		return sum;
	}
};

int dp[mxN][mxN][2];
int cnt[mxN][mxN], cnt1[mxN][mxN];
BIT<int> bit[mxN], bit1[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	dp[0][0][0] = dp[0][0][1] = 1;
	rep(i, n){
		cnt[i][m - 1] = (s[i][m - 1] == 'R');
		for(int j = m - 2; j >= 0; j--){
			cnt[i][j] = cnt[i][j + 1] + (s[i][j] == 'R');
		}
	}
	rep(j, m){
		cnt1[n - 1][j] = (s[n - 1][j] == 'R');
		for(int i = n - 2; i >= 0; i--){
			cnt1[i][j] = cnt1[i + 1][j] + (s[i][j] == 'R');
		}
	}
	rep(i, n) rep(j, m){
		if(i || j){
			dp[i][j][0] = bit1[j].query(i);
			dp[i][j][1] = bit[i].query(j);
		}
		bit[i].update(j + 1, dp[i][j][0]);
		bit[i].update(m - cnt[i][j + 1], -dp[i][j][0]);
		bit1[j].update(i + 1, dp[i][j][1]);
		bit1[j].update(n - cnt1[i + 1][j], -dp[i][j][1]);
	}
	if(n == 1 && m == 1) cout << (s[0][0] == '.' ? 1 : 0) << '\n';
	else cout << (dp[n - 1][m - 1][0] + dp[n - 1][m - 1][1]) % MOD << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
