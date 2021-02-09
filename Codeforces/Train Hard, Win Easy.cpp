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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	vector<ll> sc(n, 0LL);
	vector<pair<ll, ll>> s(n);
	rep(i, n) s[i] = mp(p[i].fi - p[i].se, i);
	sort(all(s));
	vector<ll> cnt(n + 1, 0LL);	
	rep(i, n) cnt[i + 1] += p[s[i].se].fi;
	partial_sum(all(cnt), cnt.begin());
	rep(i, n) cnt[i] += p[s[i].se].fi * (ll)(n - i - 1);
	rep(i, n) sc[s[i].se] += cnt[i];
	reverse(all(s));
	rep(i, n + 1) cnt[i] = 0LL;
	rep(i, n) cnt[i + 1] += p[s[i].se].se;
	partial_sum(all(cnt), cnt.begin());
	rep(i, n) cnt[i] += p[s[i].se].se * (ll)(n - i - 1);
	rep(i, n) sc[s[i].se] += cnt[i];
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		ll tot = min(p[a].fi + p[b].se, p[b].fi + p[a].se);
		sc[a] -= tot, sc[b] -= tot;
	}
	rep(i, n) cout << sc[i] << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
