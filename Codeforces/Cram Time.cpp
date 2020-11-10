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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll a, b;
	int f = 0;
	cin >> a >> b;
	if(b < a) f = 1, swap(a, b);
	ll l = 0, r = 100000;
	while(l < r){
		ll mid = (l + r + 1) / 2;
		if(((mid * (mid + 1)) / 2) <= (a + b)) l = mid;
		else r = mid - 1;
	}
	ll tot = 0LL;
	ll cur = 1LL;
	vector<ll> d, h;
	while((tot + cur) <= a){
		d.pb(cur);
		tot += cur;
		cur++;
	}
	ll dif = a - tot;
	rep(i, d.size()) d[i] += dif / (ll)(d.size());
	dif %= (ll)d.size();
	for(int i = (int)(d.size()) - 1; i >= 0; i--){
		if(!dif) break;
		dif--;
		d[i]++;
		assert(d[i] <= l);
	}
	vi vis(l + 1, 0);
	rep(i, d.size()) vis[d[i]] = 1;
	repn(i, 1, l + 1) if(!vis[i]) h.pb(i);
	if(f){
		cout << (int)h.size() << endl;
		for(ll x : h) cout << x << " ", vis[x] = 1;
		cout << endl;
		cout << (int)d.size() << endl;
		for(ll x : d) cout << x << " ";
		cout << endl;
	}
	else{
		cout << (int)d.size() << endl;
		for(ll x : d) cout << x << " ";
		cout << endl;
		cout << (int)h.size() << endl;
		for(ll x : h) cout << x << " ", vis[x] = 1;
		cout << endl;
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
