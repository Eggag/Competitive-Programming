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
const int inf = 1e9;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[200005][2]; //floor, was the prev. the elevator?

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, c;
	cin >> n >> c;
	vi a(n + 1);
	repn(i, 1, n) cin >> a[i];
	vi b(n + 1);
	repn(i, 1, n) cin >> b[i];
	memset(dp, inf, sizeof(dp));
	dp[1][0] = 0;
	dp[1][1] = inf;
	repn(i, 2, n + 1){
		dp[i][1] = min(dp[i - 1][0] + c + b[i - 1], dp[i - 1][1] + b[i - 1]);	
		dp[i][0] = min(dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1]);
	}
	cout << 0;
	repn(i, 2, n + 1){
		cout << " " << min(dp[i][1], dp[i][0]);
	}
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
