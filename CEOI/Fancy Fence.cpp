#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b){
	return a.se.fi < b.se.fi;
}

template<class T> struct BIT{
	vector<T> bit;
	BIT(){
		bit.assign(mxN, 0);
	}
	void update(int ind, T delta){
		for(; ind < mxN; ind = ind | (ind + 1)){
			bit[ind] += delta;
		}
	}
	T query(int ind){
		T sum = 0;
		for(; ind >= 0; ind = (ind & (ind + 1)) - 1){
			sum += bit[ind];
		}
		return sum;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input1.txt", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<ll, pair<ll, ll>>> p(n);
	vector<ll> w(n), h(n);
	rep(i, n) cin >> p[i].se.fi, p[i].fi = i, h[i] = p[i].se.fi;
	rep(i, n) cin >> p[i].se.se, w[i] = p[i].se.se, h[i]++;
	sort(all(p), cmp);
	BIT<ll> bit;
	rep(i, n) bit.update(i, w[i]);
	ll ans = 0LL;
	set<ll> pos;
	rep(i, n){
		//inside
		ll mn = h[p[i].fi];
		ll one = ((mn * (mn - 1)) / 2) % MOD;
		ll two = ((w[p[i].fi] * (w[p[i].fi] + 1)) / 2) % MOD;
		ll add = (one * two) % MOD;
		(ans += add) %= MOD;
		ll sub = 0LL, sub1 = 0LL;
		auto it1 = pos.lb(p[i].fi);
		int f1 = 0;
		if(it1 != pos.begin()) it1--, f1 = 1;
		if(pos.size() && f1) sub = bit.query(*it1); //we have smth before
		ll left = (p[i].fi ? bit.query(p[i].fi - 1) : 0LL) - sub; //how many on left are below
		auto it = pos.lb(p[i].fi);
		int f = 0;
		if(it != pos.end()){
			f = 1;
			sub1 = bit.query(*it - 1);
		}
		ll right = (f ? sub1 : bit.query(mxN - 1)) - bit.query(p[i].fi); //how many on right are below
		//left - right
		add = ((((left % MOD) * (right % MOD)) % MOD) * one) % MOD;
		(ans += add) %= MOD;
		//left - us
		add = ((((left % MOD) * (w[p[i].fi] % MOD)) % MOD) * one) % MOD;
		(ans += add) %= MOD;
		//us - right
		add = ((((w[p[i].fi] % MOD) * (right % MOD)) % MOD) * one) % MOD;
		(ans += add) %= MOD;
		bit.update(p[i].fi, -w[p[i].fi]);
		pos.insert(p[i].fi);
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
