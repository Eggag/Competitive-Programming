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
	int n, k;
	ll x;
	cin >> n >> k >> x;
	string s;
	cin >> s;
	x--;
	int cnt = 0;
	vi nm;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '*') cnt++;
		else{
			if(cnt) nm.pb(cnt);
			cnt = 0;
		}
	}
	if(cnt) nm.pb(cnt);
	int uwu = 0;
	vi d;
	while(x > 0){
		int cr = (nm[uwu++] * k) + 1;
		d.pb(x % cr);
		x /= cr;
	}
	int ind = 0, lst = -1;
	string ans = "";
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == 'a') ans += 'a', lst = 1;
		else{
			if(!lst) continue;
			if(ind == (int)(d.size())) continue;
			rep(j, d[ind]) ans += 'b';
			ind++;
			lst = 0;
		}
	}
	reverse(all(ans));
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
