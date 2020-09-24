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

ll dp[64][2];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll last = 0;
	for(ll i = 0; i <= 50; i++){
		if(k < (1LL << i)){
			last = i - 1;
			break;
		}
	}
	vector<ll> cnt(64, 0LL);
	rep(i, n) for(ll j = 0; j <= 50; j++) if(a[i] & (1LL << j)) cnt[j]++;
	rep(i, 64) rep(j, 2) dp[i][j] = 0LL;
	dp[last][0] = (n - cnt[last]) * (1LL << last); //took it up, so can't take everything
	dp[last][1] = cnt[last] * (1LL << last); //we do not pick it, can be free further
	for(ll i = last - 1; i >= 0; i--){
		dp[i][1] = max(dp[i + 1][1] + (max(n - cnt[i], cnt[i]) * (1LL << i)), ((k & (1LL << i)) ? (cnt[i] * (1LL << i)) + dp[i + 1][0] : 0));
		dp[i][0] = dp[i + 1][0] + (1LL << i) * ((k & (1LL << i)) ? n - cnt[i] : cnt[i]);
	}
	ll ans = 0;
	for(ll i = last + 1; i <= 60; i++) ans += (ll)(cnt[i] * (1LL << i));
	cout << ans + max(dp[0][0], dp[0][1]) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
