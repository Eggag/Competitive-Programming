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

struct HASH{
	size_t operator () (const pair<int, int> &x) const {
		return hash<long long>()(((long long)(x.first)) ^ (((long long)(x.second)) << 32));
	}
};

ll lcm(ll a, ll b){
	return (a / gcd(a, b)) * b;
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
	random_shuffle(all(p));
	if(n == 1){
		cout << lcm(p[0].fi, p[0].se) << '\n';
		return 0;
	}
	if(n == 2){
		ll a = lcm(gcd(p[0].fi, p[1].fi), gcd(p[0].se, p[1].se));
		ll b = lcm(gcd(p[0].se, p[1].fi), gcd(p[0].fi, p[1].se));
		cout << max(a, b) << '\n';
		return 0;
	}
	vector<pi> p1, p2, p3;
	rep(i, n){
		if(i < (n / 3)) p1.pb(p[i]);
		else if(i >= (n / 3) && i < ((2 * n) / 3)) p2.pb(p[i]);
		else p3.pb(p[i]);
	}
	int n1 = p1.size(), n2 = p2.size(), n3 = p3.size();
	unordered_set<pi, HASH> st, st1, st2;
	rep(i, (1 << n1)){
		int a = 0, b = 0;
		rep(j, n1){
			if(i & (1 << j)){
				a = gcd(a, p1[j].fi);
				b = gcd(b, p1[j].se);
			}
			else{
				a = gcd(a, p1[j].se);
				b = gcd(b, p1[j].fi);
			}
			if(a == 1 && b == 1) break;
		}
		st.insert(mp(a, b));
	}
	rep(i, (1 << n2)){
		int a = 0LL, b = 0LL;
		rep(j, n2){
			if(i & (1 << j)){
				a = gcd(a, p2[j].fi);
				b = gcd(b, p2[j].se);
			}
			else{
				a = gcd(a, p2[j].se);
				b = gcd(b, p2[j].fi);
			}
			if(a == 1 && b == 1) break;
		}
		st1.insert(mp(a, b));
	}
	rep(i, (1 << n3)){
		int a = 0LL, b = 0LL;
		rep(j, n3){
			if(i & (1 << j)){
				a = gcd(a, p3[j].fi);
				b = gcd(b, p3[j].se);
			}
			else{
				a = gcd(a, p3[j].se);
				b = gcd(b, p3[j].fi);
			}
			if(a == 1 && b == 1) break;
		}
		st2.insert(mp(a, b));
	}
	ll ans = 1LL;
	for(pi x : st) for(pi y : st1) for(pi z: st2){
		ll a = gcd(gcd(x.fi, y.fi), z.fi);
		ll b = gcd(gcd(x.se, y.se), z.se);
		ans = max(ans, lcm(a, b));
	}
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
