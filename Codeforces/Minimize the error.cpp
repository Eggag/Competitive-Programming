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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll n, k1, k2;
	cin >> n >> k1 >> k2;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<pair<ll, int>> lst;
	rep(i, n) lst.pb({sq(a[i] - b[i]), i});
	sort(lst.rbegin(), lst.rend());
	rep(i, k1){
		int ind = lst[0].se;
		if(a[ind] > b[ind]){
			a[ind]--;
			lst[0] = {sq(a[ind] - b[ind]), ind};
		}
		else if(a[ind] < b[ind]){
			a[ind]++;
			lst[0] = {sq(a[ind] - b[ind]), ind};
		}
		else lst[ind] = {1, ind}, a[ind]++;
		sort(lst.rbegin(), lst.rend());
	}
	rep(i, k2){
		int ind = lst[0].se;
		if(a[ind] > b[ind]){
			a[ind]--;
			lst[0] = {sq(a[ind] - b[ind]), ind};
		}
		else if(a[ind] < b[ind]){
			a[ind]++;
			lst[0] = {sq(a[ind] - b[ind]), ind};
		}
		else lst[ind] = {1, ind}, a[ind]++;
		sort(lst.rbegin(), lst.rend());
	}
	ll ans = 0;
	rep(i, n) ans += lst[i].fi;
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
