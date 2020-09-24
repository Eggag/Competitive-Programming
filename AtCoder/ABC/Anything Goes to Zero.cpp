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

ll mypow(ll a, ll p, ll MOD){
	if(MOD <= 0) return 0;
	if(p == 0) return 1;
	if(p == 1) return (a % MOD);
	if(p & 1) return ((a % MOD) * (mypow(a, p - 1, MOD) % MOD)) % MOD;
	ll x = mypow(a, p / 2, MOD) % MOD;
	return (x * x) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll MOD = 0LL;
	rep(i, n) MOD += (s[i] == '1');
	ll MOD1 = MOD + 1, MOD2 = MOD - 1;
	ll cur3 = 0, cur4 = 0;
	reverse(all(s));
	rep(i, n) if(s[i] == '1') (cur3 += mypow(2, i, MOD1)) %= MOD1;
	if(MOD2 > 0) rep(i, n) if(s[i] == '1') (cur4 += mypow(2, i, MOD2)) %= MOD2;
	vi ans;
	rep(i, s.size()){
		if(MOD == 1 && s[i] == '1'){
			ans.pb(0);
			continue;
		}
		int num = 1;
		ll cur1 = cur3;
		ll MOD3 = MOD1;
		if(s[i] == '1') cur1 = cur4, MOD3 = MOD2;
		if(s[i] == '0') (cur1 += mypow(2, i, MOD3)) %= MOD3;
		else cur1 -= mypow(2, i, MOD3);
		while(cur1 < 0) cur1 += MOD3;
		//now we do the operation until we are done
		string nw = "";
		int ppcnt = 0;
		rep(j, 25){
			if(cur1 & (1LL << j)) nw += '1', ppcnt++;
			else nw += '0';
		}
		while(ppcnt){
			ll cur2 = 0;
			rep(j, nw.size()) if(nw[j] == '1') (cur2 += mypow(2, j, ppcnt)) %= ppcnt;
			string nw1 = "";
			ppcnt = 0;
			rep(j, 25){
				if(cur2 & (1LL << j)) nw1 += '1', ppcnt++;
				else nw1 += '0';
			}
			nw = nw1;
			num++;
		}
		ans.pb(num);
	}
	reverse(all(ans));
	rep(i, ans.size()) cout << ans[i] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
