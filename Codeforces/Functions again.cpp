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
	vector<ll> c(n - 1);
	c[0] = abs(a[0] - a[1]);
	int cur = -1;
	repn(i, 1, n - 1){
		c[i] = c[i - 1] + (abs(a[i] - a[i + 1]) * cur);
		if(cur == -1) cur = 1;
		else cur = -1;
	}
	ll mn = 0;
	ll ans = 0;
	rep(i, n - 1){
		ans = max(ans, c[i] - mn);
		mn = min(mn, c[i]);
	}
	c[1] = abs(a[1] - a[2]);
	cur = -1;
	repn(i, 2, n - 1){
		c[i] = c[i - 1] + (abs(a[i] - a[i + 1]) * cur);
		if(cur == -1) cur = 1;
		else cur = -1;
	}
	mn = 0;
	repn(i, 1, n - 1){
		ans = max(ans, c[i] - mn);
		mn = min(mn, c[i]);
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
