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
const int MOD = 998244353;

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

unordered_map<ll, int> um;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi u(m), v(m);
	rep(i, m){
		cin >> u[i] >> v[i];
		u[i]--, v[i]--;
	}
	vi p(n);
	rep(i, n) p[i] = i;
	ll ans = 0;
	do{
		ll x = 0;
		rep(i, m) x |= ((ll)(p[u[i]] < p[v[i]])) << i;
		if(!um[x]){
			ans = (ans + (__builtin_popcountll(x))) % MOD;
			um[x] = 1;
		}
	} while(next_permutation(all(p)));
	cout << ans % MOD << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
