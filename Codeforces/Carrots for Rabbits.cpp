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

ll f(ll a, ll b){
	ll d = a / b;
	ll rm = a % b;
	return sq(d) * (b - rm) + sq(d + 1) * rm;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n), cnt(n, 0LL);
	priority_queue<pair<ll, ll>> pq;
	rep(i, n){
		cin >> a[i];
		cnt[i] = 1;
		pq.push(mp(f(a[i], cnt[i]) - f(a[i], cnt[i] + 1), i));
	}
	rep(j, k - n){
		pair<ll, ll> cr = pq.top();
		pq.pop();
		cnt[cr.se]++;
		ll i = cr.se;
		pq.push(mp(f(a[i], cnt[i]) - f(a[i], cnt[i] + 1), i));
	}
	ll ans = 0LL;
	rep(i, n) ans += f(a[i], cnt[i]);
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
