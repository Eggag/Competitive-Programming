#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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
	ll n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	if(x < 0){
		x = -x;
		rep(i, s.size()){
			if(s[i] == '1') s[i] = '0';
			else s[i] = '1';
		}
	}
	ll bal = 0LL;
	map<int, ll> cnt; //keep track of balances we encounter
	ll mx = -1e9, mn = 1e9;
	rep(i, s.size()){
		bal += (s[i] == '0' ? 1 : -1);
		cnt[bal]++;
		mx = max(mx, bal);
		mn = min(mn, bal);
	}
	if(!bal){
		if(cnt[x]) cout << -1 << endl; //infinite
		else cout << 0 << endl; //none
		return;
	}
	if(bal > 0){
		ll need = max(0LL, (x - mx) / bal);
		ll took = need * bal;
		ll cur = x - took;
		ll ans = 0LL;
		int num = need;
		while(cur >= mn){
			ans += cnt[cur];
			cur -= bal;
			num++;
		}
		if(!x) ans++;
		cout << ans << endl;
	}
	else{
		ll cur = x;
		ll ans = 0;
		while(cur <= mx){
			ans += cnt[cur];
			cur -= bal;
		}
		if(!x) ans++;
		cout << ans << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
