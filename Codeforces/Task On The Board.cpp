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
	string s;
	cin >> s;
	int m;
	cin >> m;
	vi b(m);
	rep(i, m) cin >> b[i];
	vector<pair<int, vi>> gr;
	vi cnt(m, 0);
	int tot = 0;
	vi vis(m, 0);
	while(tot < m){
		int nm = 0;
		vi cur;
		rep(i, m) if(!vis[i] && cnt[i] == b[i]){
			vis[i] = 1;
			tot++;
			nm++;
			cur.pb(i);
		}
		gr.pb(mp(nm, cur));
		rep(i, m) rep(j, cur.size()) cnt[i] += abs(i - cur[j]);
	}
	reverse(all(gr));
	int x = 0;
	vector<char> ans(m, 'Z');
	vi cnt1(30, 0);
	rep(i, s.size()) cnt1[s[i] - 'a']++;
	//debug(gr.size());
	rep(i, gr.size()){
		//debug2(cnt1[x], gr[i].fi);
		while(x < 30 && cnt1[x] < gr[i].fi) x++;
		assert(!(x >= 30 || cnt1[x] < gr[i].fi));
		rep(j, gr[i].se.size()) ans[gr[i].se[j]] = (char)('a' + x);
		x++;
	}
	rep(i, m) cout << ans[i];
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
