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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), q(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> q[i];
	ll mx = -1e18, tot = 0LL;
	vector<pair<ll, int>> mxS;
	rep(i, n){
		tot += a[i];
		mx = max(mx, tot);
		if(mx > 0 && (!mxS.size() || mxS.back().fi < mx)) mxS.pb({mx, i});
	}
	if(tot <= 0){
		rep(i, m){
			if(q[i] <= mx){
				auto it = lb(all(mxS), mp(q[i], -1));
				pair<ll, int> cr = *it;
				cout << cr.se << " ";
			}
			else cout << "-1 ";
		}
		cout << '\n';
		return;
	}
	rep(i, m){
		if(q[i] <= mx){
			auto it = lb(all(mxS), mp(q[i], -1));
			pair<ll, int> cr = *it;
			cout << cr.se << " ";
		}
		else{
			ll ans = (q[i] - mx + tot - 1) / tot;
			ll rem = q[i] - (tot * ans);
			auto it = lb(all(mxS), mp(rem, -1));
			pair<ll, int> cr = *it;
			cout << cr.se + (ans * n) << " ";
		}
	}
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
