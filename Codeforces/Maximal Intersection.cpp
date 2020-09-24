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

pi intersect(pi a, pi b){
	return mp(max(a.fi, b.fi), min(a.se, b.se));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> a;
	rep(i, n){
		int l, r;
		cin >> l >> r;
		a.pb({l, r});
	}
	vector<pi> cnt(n);
	cnt[0] = a[0];
	repn(i, 1, n) cnt[i] = intersect(a[i], cnt[i - 1]);
	vector<pi> cnt1(n);
	cnt1[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--){
		cnt1[i] = intersect(cnt1[i + 1], a[i]);
	}
	int ans = 0;
	repn(i, 1, n - 1){
		pi cur = intersect(cnt[i - 1], cnt1[i + 1]);
		ans = max(ans, cur.se - cur.fi);
	}
	ans = max({ans, cnt1[1].se - cnt1[1].fi, cnt[n - 2].se - cnt[n - 2].fi});
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
