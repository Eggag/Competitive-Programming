#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	ll t1, t2;
	cin >> n >> m >> t1 >> t2 >> k;
	vector<ll> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	if(n <= k || m <= k){
		cout << -1 << endl;
		return 0;
	}
	ll ans = 0LL;
	rep(i, k + 1){
		int pos = lb(all(b), a[i] + t1) - b.begin();
		if(pos == m){
			cout << -1 << endl;
			return 0;
		}
		int cur = k - i;
		if((pos + cur) >= m){
			cout << -1 << endl;
			return 0;
		}
		ans = max(ans, b[pos + cur] + t2);
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
