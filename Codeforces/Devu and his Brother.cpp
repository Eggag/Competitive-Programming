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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m), pos;
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	rep(i, n) pos.pb(a[i]);
	rep(i, m) pos.pb(b[i]);
	sort(all(a));
	sort(all(b));
	vector<ll> sumA(n, 0LL), sumB(m, 0LL);
	sumA[0] = a[0];
	sumB[0] = b[0];
	repn(i, 1, n) sumA[i] = sumA[i - 1] + a[i];
	repn(i, 1, m) sumB[i] = sumB[i - 1] + b[i];
	ll ans = 1e18;
	rep(i, pos.size()){
		auto it = lb(all(a), pos[i]);
		ll ind = it - a.begin();
		ll cur = 0LL;
		if(a[ind] > pos[i]) ind--;
		if(!(it == a.begin() && a[0] >= pos[i])){
			cur += (ll)((ind + 1) * pos[i]) - sumA[ind];
		}
		auto it1 = ub(all(b), pos[i]);
		ll ind1 = it1 - b.begin();
		if(it1 != b.end()){
			cur += (sumB[m - 1] - (ind1 ? sumB[ind1 - 1] : 0LL)) - ((m - 1 - ind1 + 1) * pos[i]);
		}
		ans = min(ans, cur);
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
