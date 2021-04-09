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

void solve(){
	ll n;
	cin >> n;
	if(n <= 4){
		cout << 0 << endl;
		return;
	}
	ll l = 0, r = n + 10;
	while(l < r){
		ll mid = (l + r + 1) / 2;
		ll num = 1 + (2 * mid);
		ll b = ((num * num) + 1) / 2;
		if(((num * num) - b) <= n && b <= n && num <= n) l = mid;
		else r = mid - 1;
	}
	/*
	int cnt = 0;
	repn(a, 1, n + 1) repn(b, 1, n + 1){
		int c = sq(a) - b;
		if(sq(c) == (sq(a) + sq(b)) && c <= n){
			cout << a << " " << b << " " << c << endl;
			cnt++;
		}
	}
	debug(cnt);
	*/
	cout << l << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
