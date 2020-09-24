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

int n;
ll k;
ll a[200005], f[200005];

bool check(ll lw){
	ll k1 = k;
	rep(i, n){
		//use the minimum to get it <= lw
		ll l = 0, r = k1;
		while(l < r){
			ll mid = (l + r) / 2;
			if(((a[i] - mid) * (f[i])) <= lw) r = mid;
			else l = mid + 1;
		}
		if(((a[i] - l) * (f[i])) > lw) return 0;
		k1 -= l;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> f[i];
	sort(a, a + n);
	sort(f, f + n);
	reverse(f, f + n);
	ll l = 0, r = 1e13;
	while(l < r){
		ll mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
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
