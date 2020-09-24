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

ll make_num(int a, int b){
	ll ret = a;
	repn(i, 32, 64) if(b & (1 << (i - 32))) ret |= (1LL << i);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p));
	map<ll, int> cnt;
	rep(i, n) repn(j, i + 1, n){
		int x = p[i].fi - p[j].fi, y = p[i].se - p[j].se;
		x += 1e9, y += 1e9;
		ll q = make_num(x, y);
		cnt[q]++;
	}
	ll ans = 0;
	rep(i, n) repn(j, i + 1, n){
		int x = p[i].fi - p[j].fi, y = p[i].se - p[j].se;
		x += 1e9, y += 1e9;
		ll q = make_num(x, y);
		ans += (cnt[q] - 1);
	}
	cout << ans / 4 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
