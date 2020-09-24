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
	ll n, k;
	cin >> n >> k;
	ll l = 0, r = n - 1;
	while(l < r){
		ll mid = (l + r + 1) / 2;
		if((((n - mid) * (n - mid - 1)) / 2) >= k) l = mid;
		else r = mid - 1;
	}
	ll ind1 = l;
	ll num = ((n - l - 1) * (n - l - 2)) / 2;
	ll nm = k - num;
	ll ind2 = n - nm;
	rep(i, n){
		if(i == ind1 || i == ind2) cout << 'b';
		else cout << 'a';
	}
	cout << endl;
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
