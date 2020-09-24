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

int dp[100005];

void solve(){
	int n;
	cin >> n;
	vi s(n + 1);
	repn(i, 1, n + 1) cin >> s[i], dp[i] = 1;
	int ans = 0;
	repn(i, 1, n + 1){
		for(int j = 1; (j * j) <= i; j++){
			if(i % j == 0){
				if(j != i){
					if(s[i] > s[j]) dp[i] = max(dp[i], dp[j] + 1);
				}
				if((i / j != j) && (i / j) != i){
					if(s[i] > s[i / j]) dp[i] = max(dp[i], dp[i / j] + 1);
				}
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
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
