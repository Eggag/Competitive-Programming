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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vi mn(30, n);
	rep(i, n) rep(j, s[i].size()) mn[s[i][j] - 'a'] = min(mn[s[i][j] - 'a'], i);
	int ans = 0;
	char ch = '#';
	vi p;
	for(int i = n - 1; i >= 0; i--){
		int m = s[i].size();
		if(i == (n - 1)){
			int f = 1;
			repn(j, 1, m) if(s[i][0] != s[i][j]) f = 0;
			if(f){
				ch = s[i][0];
				p.pb(m);
			}
			else{
				vector<pair<char, int>> b;
				int cnt = 1;
				repn(j, 1, m){
					if(s[i][j] == s[i][j - 1]) cnt++;
					else{
						b.pb(mp(s[i][j - 1], cnt));
						ans = max(ans, cnt);
						cnt = 1;
					}
				}
				b.pb(mp(s[i][m - 1], cnt));
				ans = max(ans, cnt);
				if(b[0].fi == b[b.size() - 1].fi && mn[b[0].fi - 'a'] < (n - 1)){
					ans = max(ans, b[0].se + 1 + b[b.size() - 1].se);
				}
				if(mn[b[0].fi - 'a'] < (n - 1)) ans = max(ans, b[0].se + 1);
				if(mn[b[b.size() - 1].fi - 'a'] < (n - 1)) ans = max(ans, b[b.size() - 1].se + 1);
				break;
			}
			continue;
		}
		int f = (s[i][0] == ch);
		repn(j, 1, m) if(s[i][0] != s[i][j]) f = 0;
		if(f) p.pb(m);
		else{
			vector<pair<char, int>> b;
			int cnt = 1, cur = (mn[ch - 'a'] < i);
			repn(j, 1, m){
				if(s[i][j] == s[i][j - 1]) cnt++;
				else{
					b.pb(mp(s[i][j - 1], cnt));
					if(s[i][j - 1] == ch) cur = max(cur, cnt);
					cnt = 1;
				}
			}
			b.pb(mp(s[i][m - 1], cnt));
			if(s[i][m - 1] == ch) cur = max(cur, cnt);
			if(b[0].fi == b[b.size() - 1].fi && mn[b[0].fi - 'a'] < (n - 1)){
				if(b[0].fi == ch) cur = max(cur, b[0].se + 1 + b[b.size() - 1].se);
			}
			if(mn[b[0].fi - 'a'] < i && b[0].fi == ch) cur = max(cur, b[0].se + 1);
			if(mn[b[b.size() - 1].fi - 'a'] < i && b[b.size() - 1].fi == ch) cur = max(cur, b[b.size() - 1].se + 1);
			if(cur) p.pb(cur);
			break;
		}
	}
	if(p.size()){
		ans = p.back();
		for(int i = (int)(p.size()) - 2; i >= 0; i--){
			ans += (ans + 1) * p[i];
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
