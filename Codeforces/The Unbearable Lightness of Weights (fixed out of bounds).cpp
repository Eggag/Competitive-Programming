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
const int mxN = 105;
const int MOD = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[mxN][mxN * mxN];
ll comb[mxN][mxN];
int cnt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i], cnt[a[i]]++;
	dp[0][0] = 1LL;
	comb[0][0] = 1LL;
	repn(i, 1, mxN){
		comb[i][0] = comb[i][i] = 1;
		repn(j, 1, i) (comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j]) %= MOD;
	}
	rep(i, n){
		for(int j = i + 1; j >= 1; j--){
			for(int k = sq(mxN) - a[i] - 1; k >= 0; k--){
				(dp[j][k + a[i]] += dp[j - 1][k]) %= MOD;
			}
		}
	}
	int ans = 1;
	repn(i, 1, 101) if(cnt[i]){
		repn(j, 1, cnt[i] + 1){
			if(dp[j][j * i] == comb[cnt[i]][j]){
				int p = -1;
				int f = 1;
				int nm = j;
				rep(k, n){
					if(a[k] == i){
						if(!nm){
							if(p == -1) p = a[k];
							else if(p != a[k]) f = 0;
						}
						else nm--;
					}
					else{
						if(p == -1) p = a[k];
						else if(p != a[k]) f = 0;
					}
				}
				ans = max(ans, j);
				if(f) ans = n;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
