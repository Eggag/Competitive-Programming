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
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans1 = 0;
	vector<ll> best;
	rep(i, n){
		ll ans = a[i];
		ll mn = a[i];
		vector<ll> res;
		for(int j = i - 1; j >= 0; j--){
			res.pb(min(mn, a[j]));
			ans += min(mn, a[j]);
			mn = min(mn, a[j]); //can't be larger
		}
		reverse(all(res));
		res.pb(a[i]);
		mn = a[i];
		for(int j = i + 1; j < n; j++){
			res.pb(min(mn, a[j]));
			ans += min(mn, a[j]);
			mn = min(mn, a[j]); //can't be larger
		}
		if(ans > ans1) best = res, ans1 = ans;
	}
	for(ll x : best) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
