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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n, m;
	cin >> n >> m;
	vi x(n);
	rep(i, n) cin >> x[i];
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	ll ans = 0LL;
	vi bst;
	rep(i, 1 << n){
		vector<pair<ll, int>> sc(m, mp(0LL, 0));
		rep(j, m) sc[j].se = j;
		rep(k, n) rep(j, m) if(s[k][j] == '1'){
			if(i & (1 << k)) sc[j].fi += 1e9 - x[k];
			else sc[j].fi -= 1e9 - x[k];
		}
		sort(all(sc));
		reverse(all(sc));
		int nm = m;
		vi pr(m, 0);
		rep(j, m) pr[sc[j].se] = nm--;
		ll tot = 0LL;
		rep(k, n){
			ll uwu = 0LL;
			rep(j, m){
				if(s[k][j] == '1') uwu += pr[j];
			}
			tot += abs(uwu - x[k]);
		}
		if(tot >= ans) swap(bst, pr), ans = tot;
	}
	rep(i, m) cout << bst[i] << ' ';
	cout << '\n';
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
