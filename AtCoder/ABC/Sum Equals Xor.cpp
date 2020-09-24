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
const int mod = 1e9 + 7;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll dp[100005][2]; //[current bit][taken lower?]

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string l;
	cin >> l;
	int n = l.size();
	rep(i, 100005) rep(j, 2) dp[i][j] = 0LL;
	dp[0][1] = 1;
	dp[0][0] = 2; //either a or b
	repn(i, 1, n){
		if(l[i] == '1'){
			(dp[i][1] += (2 * (dp[i - 1][1]))) %= mod; //take
			(dp[i][1] += (dp[i - 1][1] + dp[i - 1][0])) %= mod; //not take
			(dp[i][0] += (2 * dp[i - 1][0])) %= mod; //take
			//(dp[i][0] += (dp[i - 1][0])) %= mod; //not take
		}
		else{
			(dp[i][1] += (2 * (dp[i - 1][1]))) %= mod; //take
			(dp[i][1] += dp[i - 1][1]) %= mod; //not take
			//(dp[i][0] += (2 * dp[i - 1][0])) %= mod; //take
			(dp[i][0] += (dp[i - 1][0])) %= mod; //not take
		}
	}
	cout << (dp[n - 1][1] + dp[n - 1][0]) % mod << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
