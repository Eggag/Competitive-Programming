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
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[2005][2005][2];
int m, d;
int powt[2005];

bool mgk(string a){
	int md = 0;
	rep(i, a.size()){
		if((i & 1) && (a[i] - '0') != d) return 0;
		if((i % 2 == 0) && (a[i] - '0') == d) return 0;
		md = (md + powt[a.size() - i - 1] * (a[i] - '0')) % m;
	}
	if(md) return 0;
	return 1;
}

ll solve(string a){
	rep(i, 2005) rep(j, 2005) rep(k, 2) dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	int n = a.size();
	repn(i, 1, n + 1){
		rep(j, m){
			repn(l, (i == 1), 10) if((i & 1 && l != d) || (l == d && i % 2 == 0)){
				int dig = (int)(a[i - 1] - '0');
				int num = ((powt[n - i] * l) + j) % m;
				if(l < dig){
					(dp[i][num][1] += (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD) %= MOD;
				}
				else if(l == dig){
					(dp[i][num][1] += dp[i - 1][j][1]) %= MOD;
					(dp[i][num][0] += dp[i - 1][j][0]) %= MOD;

				}
				else{
					(dp[i][num][1] += dp[i - 1][j][1]) %= MOD;
				}
			}
		}
	}
	return (ll)(dp[n][0][1] + dp[n][0][0]) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> m >> d;
	string a, b;
	cin >> a >> b;
	powt[0] = 1;
	repn(i, 1, 2005) powt[i] = (powt[i - 1] * 10) % m;
	ll ans = (solve(b) - solve(a) + MOD + mgk(a)) % MOD;
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
