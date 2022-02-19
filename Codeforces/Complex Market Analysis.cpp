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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxN];

void sieve(){
	repn(i, 2, mxN) if(!p[i]){
		for(int j = i + i; j < mxN; j += i) p[j] = 1;
	}
}

void solve(){
	int n, e;
	cin >> n >> e;
	vi a(n), lst(n + 1, -1), vis(n, 0);
	rep(i, n) cin >> a[i];
	ll ans = 0LL;
	rep(i, n) if(!vis[i]){
		vi cr;
		for(int j = i; j < n; j += e){
			cr.pb(a[j]);
			vis[j] = 1;
		}
		int m = (int)(cr.size());
		rep(j, m + 1) lst[j] = -1;
		for(int j = m - 1; j >= 0; j--){
			if(cr[j] == 1 && lst[j] != -1 && !p[cr[lst[j]]]){
				int r = lst[lst[j]];
				if(r == -1) r = m;
				ans += max(0, (r - j - 1)) - max(0, (lst[j] - (j + 1)));
			}
			if(!p[cr[j]] && cr[j] > 1){
				int r = lst[j];
				if(r == -1) r = m;
				ans += max(0, ((r - 1) - j));
			}
			if(j) lst[j - 1] = lst[j];
			if(cr[j] > 1 && j) lst[j - 1] = j;
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	sieve();
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
