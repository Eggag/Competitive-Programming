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

ll d[205][205];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, r;
	cin >> n >> m >> r;
	vi t(r);
	rep(i, r) cin >> t[i], t[i]--;
	rep(i, 205) rep(j, 205) d[i][j] = 1e18;
	rep(i, 205) d[i][i] = 0;
	rep(i, m){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		d[a][b] = c;
		d[b][a] = c;
	}
	rep(k, n) rep(i, n) rep(j, n) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	ll ans = 1e18;
	sort(all(t));
	do{
		ll cur = 0;
		repn(i, 1, r) cur += d[t[i]][t[i - 1]];
		ans = min(ans, cur);
	} while(next_permutation(all(t)));
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
