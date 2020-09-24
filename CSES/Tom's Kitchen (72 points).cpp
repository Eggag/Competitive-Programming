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

int dp[90005];
int dp1[1605][1605];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vi a(n), b(m);
	int sumA = 0;
	int mn = 1e9;
	rep(i, n) cin >> a[i], sumA += a[i], mn = min(mn, a[i]);
	rep(i, m) cin >> b[i];
	if(mn < k){
		cout << "Impossible" << endl;
		return 0;
	}
	if(n >= 1 && n <= 300 && k > 1 && k <= 300 && m >= 1 && m <= 15){
		//subtasks 1 and 2: bitmask
		int ans = 1e9;
		rep(i, (1 << m)) if(__builtin_popcount(i) >= k){
			int sum = 0;
			int need = n * k;
			int can = 0;
			rep(j, m) if(i & (1 << j)){
				sum += b[j];
				can += min(n, b[j]);
			}
			if(sum >= sumA && can >= need) ans = min(ans, sum - sumA);
		}
		if(ans == 1e9) cout << "Impossible" << endl;
		else cout << ans << endl;
	}
	else if(k == 1){
		//subtast 3 -> DP
		rep(i, 90005) dp[i] = 0;
		dp[0] = 1;
		rep(i, m){
			for(int j = 90005 - b[i]; j >= 0; j--) dp[j + b[i]] |= dp[j]; 
		}
		repn(i, sumA, 90005) if(dp[i]){
			cout << i - sumA << endl;
			return 0;
		}
		cout << "Impossible" << endl;
	}
	else{
		//subtask 4: DP?
		//dp[value][can?]
		//value can at most bee 1600, same for can
		rep(i, 1605) rep(j, 1605) dp1[i][j] = 0;
		dp1[0][0] = 1;
		rep(i, m){
			//look over all values, add can to them?
			int cur = min(n, b[i]);
			for(int j = 1605 - b[i]; j >= 0; j--){
				rep(k1, 1605) if((k1 + cur) < 1605){
					dp1[j + b[i]][k1 + cur] |= dp1[j][k1];
				}
			}
		}	
		repn(i, sumA, 1605){
			repn(j, k * n, 1605) if(dp1[i][j]){
				cout << i - sumA << endl;
				return 0;
			}
		}

	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
