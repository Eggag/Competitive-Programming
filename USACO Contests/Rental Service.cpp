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

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	return a.se > b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	ll n, m, r;
	cin >> n >> m >> r;

	vector<ll> c(n + 1);
	repn(i, 1, n + 1) cin >> c[i];
	sort(c.begin() + 1, c.end());
	reverse(c.begin() + 1, c.end());
	//repn(i, 1, n + 1) debug(c[i]);

	vector<pair<ll, ll>> p(m + 1);
	repn(i, 1, m + 1) cin >> p[i].fi >> p[i].se;
	sort(p.begin() + 1, p.end(), cmp);
	//repn(i, 1, m + 1){
	//	debug2(p[i].fi, p[i].se);
	//}

	vector<ll> r1(r + 1);
	repn(i, 1, r + 1) cin >> r1[i];
	sort(r1.begin() + 1, r1.end());
	reverse(r1.begin() + 1, r1.end());
	//repn(i, 1, r + 1) debug(r1[i]);
	
	vector<ll> cnt(r + 1); //how much we earn from selling i cows
	cnt[0] = 0;
	repn(i, 1, r + 1) cnt[i] = cnt[i - 1] + r1[i];

	vector<ll> cnt1(n + 1);
	cnt1[0] = 0;
	repn(i, 1, n + 1) cnt1[i] = cnt1[i - 1] + c[i];
	
	vector<ll> cnt2(m + 1);
	cnt2[0] = 0;
	repn(i, 1, m + 1) cnt2[i] = cnt2[i - 1] + (p[i].fi * p[i].se);
	
	vector<ll> cnt3(m + 1);
	cnt3[0] = 0;
	repn(i, 1, m + 1) cnt3[i] = cnt3[i - 1] + (p[i].fi);

	ll ans = 0;
	rep(i, min(n, r) + 1){
		ll cur = cnt[i];
		int num = n - i;
		if(num > 0){
			ll bal = cnt1[num];
			int loc = ub(all(cnt3), bal) - cnt3.begin();
			ll nw1 = 0;
			if(loc > 0) cur += cnt2[loc - 1], nw1 = cnt3[loc - 1];
			ll nm = bal - nw1;
			nm = min(nm, p[loc].fi);
			if(nm > 0) cur += nm * p[loc].se;
		}
		ans = max(ans, cur);
	}
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
