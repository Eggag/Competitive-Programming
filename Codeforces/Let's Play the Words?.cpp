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
const int mxN = 2e5 + 5;
const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pair<ll, ll> hsh[mxN], hshRev[mxN];

pair<ll, ll> ha(string s){
	ll h = 1LL, h1 = 1LL;
	rep(i, s.size()){
		h = ((h * 179) + (ll)(s[i] - 'a') + 1) % MOD;
		h1 = ((h1 * 131) + (ll)(s[i] - 'a') + 1) % MOD1;
	}
	return mp(h, h1);
}

void solve(){
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int c11 = 0, c00 = 0, c10 = 0, c01 = 0;
	int r10 = 0, r01 = 0;
	set<pair<ll, ll>> st;
	rep(i, n){
		if(s[i][0] == '0' && s[i][(int)s[i].size() - 1] == '0') c00++;
		if(s[i][0] == '1' && s[i][(int)s[i].size() - 1] == '1') c11++;
		hsh[i] = ha(s[i]);
		string s1 = s[i];
		reverse(all(s1));
		hshRev[i] = ha(s1);
		st.insert(hshRev[i]);
	}
	vi g(n, 0), g1(n, 0);
	rep(i, n){
		if(s[i][0] == '0' && s[i][(int)s[i].size() - 1] == '1'){
			c01++;
			if(st.find(hsh[i]) == st.end()) g[i] = 1, r01++;
		}
		if(s[i][0] == '1' && s[i][(int)s[i].size() - 1] == '0'){
			c10++;
			if(st.find(hsh[i]) == st.end()) g1[i] = 1, r10++;
		}
	}
	if((c11 && c00) && (!c01 && !c10)){
		cout << -1 << endl;
		return;
	}
	if(abs(c01 - c10) <= 1){
		cout << 0 << endl << endl;
		return;
	}
	else{
		if(c01 > c10){
			int nm = (c01 - c10) / 2;
			int nm1 = nm;
			vi ans;
			rep(i, n){
				if(!nm) break;
				if(g[i]) nm--, ans.pb(i + 1);
			}
			if(nm){
				cout << -1 << endl;
				return;
			}
			cout << nm1 << endl;
			for(int x : ans) cout << x << " ";
			cout << endl;
			return;
		}
		else{
			int nm = (c10 - c01) / 2;
			int nm1 = nm;
			vi ans;
			rep(i, n){
				if(!nm) break;
				if(g1[i]) nm--, ans.pb(i + 1);
			}
			if(nm){
				cout << -1 << endl;
				return;
			}
			cout << nm1 << endl;
			for(int x : ans) cout << x << " ";
			cout << endl;
			return;
		}
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
