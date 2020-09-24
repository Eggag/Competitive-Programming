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

ll lcm(ll a, ll b){
	return ((a / gcd(a, b)) * b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	unordered_set<ll> dp[n + 1];
	dp[0].insert(1LL);
	repn(i, 1, n + 1){
		rep(j, i){
			for(ll x : dp[j]){
				dp[i].insert(lcm(x, i - j));
			}
		}
	}
	ll res = 0;
	for(ll x : dp[n]){
		(res += x) %= m;
	}
	cout << res << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
