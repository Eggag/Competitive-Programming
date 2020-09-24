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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<ll> a(n), t(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> t[i];
	if(a[n - 1] != t[0]){
		cout << 0 << endl;
		return 0;
	}
	repn(i, 1, n) if(a[i] > a[i - 1] && t[i] < a[i]){
		cout << 0 << endl;
		return 0;
	}
	rep(i, n - 1) if(t[i] > t[i + 1] && a[i] < t[i]){
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1LL;
	repn(i, 1, n - 1){
		if(a[i] > a[i - 1] || t[i] > t[i + 1]) ans *= 1LL;
		else (ans *= 1LL * (min(a[i], t[i]))) %= MOD;
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
