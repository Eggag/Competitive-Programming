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

bool cmp(pi a, pi b){
	return a.se - a.fi < b.se - b.fi;
}

bool cmp1(array<int, 3> a, array<int, 3> b){
	if(a[1] != b[1]) return a[1] < b[1];
	return a[0] < b[0];
}

void solve(){
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p), cmp);
	vi dp(n, 0);
	rep(i, n){
		int st = i;
		while(i < n && p[i].se - p[i].fi == p[st].se - p[st].fi) i++;
		i--;
		repn(j, st, i + 1){
			vector<array<int, 3>> p1;
			rep(k, i) if(p[k].fi >= p[j].fi && p[k].se <= p[j].se) p1.pb({p[k].fi, p[k].se, k});
			sort(all(p1), cmp1);
			int m = (int)(p1.size());
			if(!m){
				dp[j] = 1;
				continue;
			}
			vi dp1(m, 0);
			rep(k, m){
				dp1[k] = dp[p1[k][2]];
				rep(l, k) if(p1[l][1] < p1[k][0]) dp1[k] = max(dp1[k], dp[p1[k][2]] + dp1[l]);
			}
			dp[j] = *max_element(all(dp1)) + 1;
		}
	}
	vector<array<int, 3>> p2;
	rep(i, n) p2.pb({p[i].fi, p[i].se, i});
	sort(all(p2), cmp1);
	vi dp2(n, 0);
	rep(i, n){
		dp2[i] = dp[p2[i][2]];
		rep(j, i) if(p2[j][1] < p2[i][0]) dp2[i] = max(dp2[i], dp[p2[i][2]] + dp2[j]);
	}
	int ans = *max_element(all(dp2));
	cout << max(ans, *max_element(all(dp))) << '\n';
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
