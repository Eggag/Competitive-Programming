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
const int mxN = 2e5 + 5;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n;
vi g[mxN];
ll v[mxN], de[mxN];
ll dp[mxN][2];
ll ans = 0LL;

void dfs0(int cur, int prev, int d = 0){
	dp[cur][d & 1] = de[cur] = 1;
	for(int x : g[cur]) if(x != prev){
		dfs0(x, cur, d + 1);
		rep(i, 2) dp[cur][i] += dp[x][i];
		de[cur] += de[x];
	}
}

void dfs(int cur, int prev, int d = 0, ll ev = 0LL, ll od = 0LL){
	if(v[cur] > 0){
		(ans += (v[cur] * n) % MOD) %= MOD;
	}
	else{
		ans -= (-1 * v[cur] * n) % MOD;
		(ans += MOD) %= MOD;
	}
	if(d & 1){
		ll a = (od * de[cur]) % MOD;
		if(v[cur] > 0){
			(ans += ((v[cur] * a) % MOD)) %= MOD;
		}
		else{
			ans -= ((-1 * v[cur] * a) % MOD);
			(ans += MOD) %= MOD;
		}
		ll b = (ev * de[cur]) % MOD;
		if(v[cur] > 0){
			ans -= (v[cur] * b) % MOD;
			(ans += MOD) %= MOD;
		}
		else{
			(ans += (-1 * v[cur] * b) % MOD) %= MOD;
		}
	}
	else{
		ll a = (ev * de[cur]) % MOD;
		if(v[cur] > 0){
			(ans += ((v[cur] * a) % MOD)) %= MOD;
		}
		else{
			ans -= ((-1 * v[cur] * a) % MOD);
			(ans += MOD) %= MOD;
		}
		ll b = (od * de[cur]) % MOD;
		if(v[cur] > 0){
			ans -= (v[cur] * b) % MOD;
			(ans += MOD) %= MOD;
		}
		else{
			(ans += (-1 * v[cur] * b) % MOD) %= MOD;
		}
	}
	for(int x : g[cur]) if(x != prev){
		ll a = (dp[x][d & 1] * (ll)(n - de[x])) % MOD;
		ll b = (dp[x][1 - (d & 1)] * (ll)(n - de[x])) % MOD;
		ll owo = 0LL;
		if(v[cur] > 0){
			(owo += (v[cur] * a) % MOD) %= MOD;
		}
		else{
			owo -= (-1 * v[cur] * a) % MOD;
			(owo += MOD) %= MOD;
		}
		if(v[cur] > 0){
			owo -= (v[cur] * b) % MOD;
			(owo += MOD) %= MOD;
		}
		else{
			(owo += (-1 * v[cur] * b) % MOD) %= MOD;
		}
		ans += owo;
		(ans += MOD) %= MOD;
		ev += dp[x][0];
		od += dp[x][1];
	}
	for(int x : g[cur]) if(x != prev){
		ll ev1 = ev - dp[x][0], od1 = od - dp[x][1];
		if(d & 1) od1++;
		else ev1++;
		dfs(x, cur, d + 1, ev1, od1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> v[i];
	rep(i, n - 1){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs0(0, -1);
	dfs(0, -1);
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
