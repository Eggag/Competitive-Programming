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
	return (ll)((a / gcd(a, b)) * b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll lc = 1LL;
	rep(i, n){
		if(lc > m){
			cout << 0 << endl;
			return 0;
		}
		lc = lcm(lc, a[i] / 2);
	}
	rep(i, n) if(lc % a[i] == 0){
		cout << 0 << endl;
		return 0;
	}
	ll l = 0, r = 1.1e9;
	while(l < r){
		ll mid = (l + r + 1) / 2;
		if(((mid * 2 - 1) * lc) <= m) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
