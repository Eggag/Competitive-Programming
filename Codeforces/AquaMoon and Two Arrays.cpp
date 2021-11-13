#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
	int n;
	cin >> n;
	vi a(n), b(n);
	int sum = 0, sum1 = 0;
	rep(i, n) cin >> a[i], sum += a[i];
	rep(i, n) cin >> b[i], sum1 += b[i];
	if(sum != sum1){
		cout << -1 << '\n';
		return;
	}
	vi t, g;
	rep(i, n){
		if(a[i] < b[i]){
			int dif = b[i] - a[i];
			while(dif--) t.pb(i);
		}
		if(a[i] > b[i]){
			int dif = a[i] - b[i];
			while(dif--) g.pb(i);
		}
	}
	cout << (int)(t.size()) << '\n';
	rep(i, t.size()) cout << g[i] + 1 << " " << t[i] + 1 << '\n';
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
