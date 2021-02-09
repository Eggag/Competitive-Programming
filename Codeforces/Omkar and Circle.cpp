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
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0LL;
	rep(i, n) cin >> a[i], sum += a[i];
	if(n == 1){
		cout << a[0] << endl;
		return 0;
	}
	vector<ll> l(n), l1(n), r(n), r1(n); //l is even, l1 is odd
	ll ans = 0;
	rep(i, n){
		if(i % 2 == 0){
			l[i] = a[i];
			if(i > 1) l[i] += l[i - 2];
		}
		else{
			l1[i] = a[i];
			if(i > 1) l1[i] += l1[i - 2];
		}
	}
	for(int i = n - 1; i >= 0; i--){
		if(i % 2 == 0){
			r[i] = a[i];
			if(i < (n - 2)) r[i] += r[i + 2];
		}
		else{
			r1[i] = a[i];
			if(i < (n - 2)) r1[i] += r1[i + 2];
		}
	}
	rep(i, n - 1){
		ll cur;
		if(i % 2 == 0) cur = (i ? l1[i - 1] : 0) + (i == (n - 2) ? 0 : r[i + 2]);
		else cur = (i ? l[i - 1] : 0) + ((i == (n - 2)) ? 0 : r1[i + 2]);
		ans = max(ans, sum - cur);
	}
	ll pos = 0LL;
	rep(i, n - 1) if(i & 1) pos += a[i];
	cout << max(sum - pos, ans) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
