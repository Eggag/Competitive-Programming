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

ll solve(string s){
	int n = s.size();
	if(!n) return 1;
	if(n == 1) return 2;
	ll cur = 0;
	ll ret = 1e18;
	vector<ll> p = {0};
	rep(i, n){
		if(s[i] == 'A') cur++;
		else cur--;
		p.pb(cur);
	}
	vector<ll> pmx(n + 1, -1e9), pmn(n + 1, 1e9);
	vector<ll> smx(n + 1, -1e9), smn(n + 1, 1e9);
	pmx[0] = pmn[0] = p[0];
	repn(i, 1, n + 1){
		pmx[i] = max(p[i], pmx[i - 1]);
		pmn[i] = min(p[i], pmn[i - 1]);
	}
	smx[n] = smn[n] = p[n];
	for(int i = n - 1; i >= 0; i--){
		smx[i] = max(p[i], smx[i + 1]);
		smn[i] = min(p[i], smn[i + 1]);
	}
	repn(i, 1, n){
		//[0, i] and [i + 1, n]
		ll mx = pmx[i], mn = pmn[i];
		ll mx1 = smx[i + 1], mn1 = smn[i + 1];
		ret = min(ret, max(mx, mx1 + 1) - min(mn, mn1 + 1) + 1);
		ret = min(ret, max(mx, mx1 - 1) - min(mn, mn1 - 1) + 1);
	}
	return ret;
}

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	ll mn = 0, mx = 0;
	ll cur = 0;
	string a = "", b = "";
	rep(i, n){
		if(s[i] == 'A') cur++, a += 'A';
		if(s[i] == 'D') cur--, a += 'B';
		mn = min(mn, cur);
		mx = max(mx, cur);
	}
	ll mn1 = 0, mx1 = 0;
	cur = 0;
	rep(i, n){
		if(s[i] == 'W') cur++, b += 'A';
		if(s[i] == 'S') cur--, b += 'B';
		mn1 = min(mn1, cur);
		mx1 = max(mx1, cur);
	}
	ll ans = (mx1 - mn1 + 1) * (mx - mn + 1);
	ans = min(ans, (ll)(solve(a) * (mx1 - mn1 + 1)));
	ans = min(ans, (ll)(solve(b) * (mx - mn + 1)));
	cout << ans << '\n';
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
