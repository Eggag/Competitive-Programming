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

int cnt[30];

bool cmp(pair<char, int> a, pair<char, int> b){
	if(cnt[a.fi - 'a'] != cnt[b.fi - 'a']) return cnt[a.fi - 'a'] > cnt[b.fi - 'a'];
	return a.fi < b.fi;
}

void solve(){
	string s;
	cin >> s;
	int n = (int)(s.size());
	rep(i, 30) cnt[i] = 0;
	rep(i, n) cnt[s[i] - 'a']++;
	rep(i, 30) if(cnt[i] > (n / 2)){
		cout << "IMPOSSIBLE\n";
		return;
	}
	vector<char> ans(n, '.');
	vector<pair<char, int>> p(n);
	rep(i, n) p[i] = mp(s[i], i);
	sort(all(p), cmp);
	int l = 0;
	while(p[l].fi == p[0].fi) l++;
	rep(i, n){
		ans[p[i].se] = p[l].fi;
		l++;
		if(l == n) l = 0;
	}
	rep(i, n) cout << ans[i];
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
