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

map<vi, ll> subset5, subset4, subset3, subset2;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);
	ll n;
	cin >> n;
	ll subset1[1000005];
	memset(subset1, 0LL, sizeof(subset1));
	rep(i, n){
		vi a(5);
		rep(j, 5) cin >> a[j];
		//subsets of 5
		sort(all(a));
		subset5[a]++;
		rep(j, 5){
			vi b;
			rep(k, 5) if(k != j) b.pb(a[k]);
			subset4[b]++;
		}
		rep(j, 5) repn(k, j + 1, 5){
			vi b;
			rep(l, 5) if(l != j && l != k) b.pb(a[l]);
			subset3[b]++;
		}
		rep(j, 5) repn(k, j + 1, 5){
			vi b = {a[j], a[k]};
			subset2[b]++;
		}
		rep(j, 5) subset1[a[j]]++;
	}
	ll num = (n * (n - 1)) / 2;
	ll ans = 0;
	rep(i, 1000005) ans += (subset1[i] * (subset1[i] - 1)) / 2;
	//for(pair<int, ll> x : subset1) ans += (x.se * (x.se - 1)) / 2;
	for(pair<vi, ll> x : subset2) ans -= (x.se * (x.se - 1)) / 2;
	for(pair<vi, ll> x : subset3) ans += (x.se * (x.se - 1)) / 2;
	for(pair<vi, ll> x : subset4) ans -= (x.se * (x.se - 1)) / 2;
	for(pair<vi, ll> x : subset5) ans += (x.se * (x.se - 1)) / 2;
	cout << num - ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
