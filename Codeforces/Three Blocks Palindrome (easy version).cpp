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
	int n;
	cin >> n;
	vi cnt[30];
	vi a(n);
	rep(i, n) cin >> a[i], cnt[a[i]].pb(i);
	int ans = 0;
	rep(i, n) repn(j, i, n) if(a[i] == a[j]){
		int num = ((int)(ub(all(cnt[a[i]]), j) - cnt[a[i]].begin()) - 1) - (((int)(ub(all(cnt[a[i]]), i - 1) - cnt[a[i]].begin()) - 1));
		rep(k, 30) if(cnt[k].size() && k != a[i]){
			auto l = lb(all(cnt[k]), i);
			auto r = lb(all(cnt[k]), j);
			int l1 = 0;
			if(l != cnt[k].end()) l1 = (int)(l - cnt[k].begin());
			else l1 = cnt[k].size();
			int r1 = 0;
			if(r != cnt[k].end()) r1 = (int)(cnt[k].size() - (int)(r - cnt[k].begin()));
			else r1 = 0;
			int cur = num + min(l1, r1) * 2;
			ans = max(ans, cur);
		}
	}
	rep(i, 30) ans = max(ans, (int)(cnt[i].size()));
	cout << ans << endl;
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
