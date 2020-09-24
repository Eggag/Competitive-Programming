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

ll lcm(ll a, ll b){
	return ((a * b) / gcd(a, b));
}

struct frac{
	ll a, b;
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

frac mul(frac q, frac p){
	frac ret = (frac){q.a * p.a, q.b * p.b};
	ret.pr();
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> best;
	frac ans = (frac){0, 1};
	ll mn = a[n - 1];
	ll sum = a[n - 1];
	for(ll k = n - 2; k >= 1; k--){
		mn = min(mn, a[k]);
		sum += a[k];
		sum -= mn;
		frac now = {sum, n - k - 1};
		now.pr();
		sum += mn;
	 	if(ans < now){
			ans = now;
			best = {k};
		}
		else if(now == ans) best.pb(k);
	}
	sort(all(best));
	rep(i, best.size()) cout << best[i] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
