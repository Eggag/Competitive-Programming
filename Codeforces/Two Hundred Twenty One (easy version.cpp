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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[mxN][2][2];

void solve(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	rep(i, n) rep(j, 2) rep(k, 2) cnt[i][j][k] = 0;
	rep(i, n){
		if(i) rep(j, 2) rep(k, 2) cnt[i][j][k] += cnt[i - 1][j][k];
		cnt[i][i & 1][(s[i] == '+' ? 1 : 0)]++;
	}
	rep(i, q){
		int l, r;
		cin >> l >> r;
		l--, r--;
		int cr = (l & 1), pr = 1 - cr;
		int a = cnt[r][cr][1] - (l ? cnt[l - 1][cr][1] : 0);
		int b = cnt[r][cr][0] - (l ? cnt[l - 1][cr][0] : 0);
		int c = cnt[r][pr][1] - (l ? cnt[l - 1][pr][1] : 0);
		int d = cnt[r][pr][0] - (l ? cnt[l - 1][pr][0] : 0);
		if(a + d == b + c) cout << 0 << '\n';
		else if((l - r + 1) & 1) cout << 1 << '\n';
		else cout << 2 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
