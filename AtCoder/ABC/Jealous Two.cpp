#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

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

bool cmp(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	return a.se > b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	BIT<int> bit;
	set<int> pos;
	rep(i, n){
		cin >> p[i].fi;
		pos.insert(p[i].fi);
	}
	rep(i, n){
		cin >> p[i].se;
		pos.insert(p[i].se);
	}
	map<int, int> cnt;
	int ind = 1;
	for(int x : pos) cnt[x] = ind++;
	map<pi, ll> nm;
	rep(i, n){
		p[i].fi = cnt[p[i].fi];
		p[i].se = cnt[p[i].se];
		nm[mp(p[i].fi, p[i].se)]++;
	}
	ll ans = n;
	for(pair<pi, ll> x : nm){
		ans += (x.se * (x.se - 1)) / 2;
	}
	sort(all(p), cmp);
	rep(i, n){
		ans += i - bit.query(p[i].se - 1);
		bit.update(p[i].se, 1);
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
