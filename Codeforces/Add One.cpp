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
const int MOD = 1e9 + 7;
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll p[15][mxN];

void solve(){
	string s;
	int m;
	cin >> s >> m;
	ll len = 0LL;
	rep(i, s.size()) (len += p[s[i] - '0'][m]) %= MOD;
	cout << len << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	rep(i, 10){
		ll len = 1LL;
		vector<ll> cnt(10, 0LL);
		cnt[i]++;
		repn(j, 1, mxN){
			ll ct = cnt[8];
			for(int k = 8; k >= 1; k--) cnt[k] = cnt[k - 1];
			cnt[0] = cnt[9], (cnt[1] += cnt[9]) %= MOD;
			(len += cnt[9]) %= MOD;
			cnt[9] = ct;
			p[i][j] = len;
		}
	}
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
