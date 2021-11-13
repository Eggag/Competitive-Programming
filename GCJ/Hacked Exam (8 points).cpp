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

ll lcm(ll a, ll b){
	return ((a * b) / gcd(a, b));
}

struct frac{
	ll a, b;
	frac(ll a1, ll b1){
		a = a1, b = b1;
	}
	void pr(){
		ll g = gcd(a, b);
		a /= g;
		b /= g;
	}
	bool operator == (const frac &p) const{
		return (ll)(a * p.b) == (ll)(b * p.a);
	}
	bool operator < (const frac &p) const{
		return (ll)(a * p.b) < (ll)(b * p.a);
	}
};

frac add(frac q, frac p){
	ll l = lcm(q.b, p.b);
	q.a *= (l / q.b);
	p.a *= (l / p.b);
	frac now = (frac){q.a + p.a, l};
	now.pr();
	return (frac)now;
}

void solve(){
	int n, q;
	cin >> n >> q;
	vector<pair<ll, ll>> pos(q);
	vector<pair<string, int>> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	rep(i, 1 << q){
		int f = 1;
		rep(j, n){
			int sc = 0;
			rep(k, q){
				if(i & (1 << k)){
					if(p[j].fi[k] == 'T') sc++;
				}
				else{
					if(p[j].fi[k] == 'F') sc++;
				}
			}
			if(sc != p[j].se) f = 0;
		}
		if(f){
			rep(k, q){
				if(i & (1 << k)){
					pos[k].fi++;
				}
				else{
					pos[k].se++;
				}
			}
		}
	}
	string ans = "";
	frac fr(0, 1);
	rep(i, q){
		if(pos[i].fi > pos[i].se) ans += 'T';
		else ans += 'F';
		frac fr1 = frac(max(pos[i].fi, pos[i].se), (pos[i].fi + pos[i].se));
		fr = add(fr, fr1);
	}
	cout << ans << " " << fr.a << "/" << fr.b << '\n';
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
