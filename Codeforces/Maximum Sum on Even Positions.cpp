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

void solve(){
	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0LL, sum1 = 0LL;
	rep(i, n) cin >> a[i];
	ll ans = 0LL;
	pi bst = {-1, -1};
	vector<ll> mn(2, 0LL), bst1(2, 0LL);
	rep(i, n){
		if(i % 2 == 0) sum += a[i];
		else sum1 += a[i];
		if(ans <= ((sum1 - sum) - mn[i & 1])){
			ans = sum1 - sum - mn[i & 1];
			bst = {bst1[i & 1], i};
		}
		if((sum1 - sum) < mn[i & 1]){
			mn[i & 1] = sum1 - sum;
			bst1[i & 1] = i + 1;
		}
	}
	if(bst.fi != -1 && bst.se != -1) reverse(a.begin() + bst.fi, a.begin() + bst.se + 1);
	ll res = 0LL;
	rep(i, n) if(i % 2 == 0) res += a[i];
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
