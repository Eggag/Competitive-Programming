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

ll dp[10], dp1[10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, 10) dp[i] = -1e18;
	dp[0] = 0;
	rep(i, n){
		int k;
		cin >> k;
		vector<ll> p[3];
		rep(j, k){
			int c;
			ll d;
			cin >> c >> d;
			p[c - 1].pb(d);
		}
		rep(i, 3) sort(all(p[i]));
		rep(j, 10) dp1[j] = dp[j];
		rep(j, 10){
			vector<vector<ll>> pos;
			int n1 = p[0].size();
			vector<ll> p1;
			for(int k = n1 - 1; k >= max(0, n1 - 3); k--){
				p1.pb(p[0][k]);
				pos.pb(p1);
			}
			if(p[0].size() && p[1].size()) pos.pb({p[0][p[0].size() - 1], p[1][p[1].size() - 1]});
			if(p[2].size()) pos.pb({p[2][p[2].size() - 1]});
			if(p[1].size()) pos.pb({p[1][p[1].size() - 1]});
			for(vector<ll> x : pos){
				sort(all(x));
				int m = x.size();
				int nxt = (j + m) % 10;
				if(nxt < j) x[m - 1] *= 2LL;
				ll c = 0LL;
				rep(k, m) c += x[k];
				dp[nxt] = max(dp[nxt], dp1[j] + c);
			}
		}
	}
	ll ans = 0LL;
	rep(i, 10) ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
