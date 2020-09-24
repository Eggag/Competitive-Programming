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
const int mxN = (1 << 20) + 1;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

double dp[2][mxN];
double p[25];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	dp[0][0] = 100.0;
	repn(i, 1, n + 1){
		int cur = i & 1;
		int prev = cur ^ 1;
		rep(j, n) cin >> p[j];
		rep(j, 1 << n) if(__builtin_popcount(j) <= i){
			rep(k, n) if(!(j & (1 << k))){
				dp[cur][j | (1 << k)] = max(dp[cur][j | (1 << k)], dp[prev][j] * (double)(p[k] / 100.0));
			}
		}
	}
	cout << fixed << setprecision(6) << dp[n & 1][(1 << n) - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
