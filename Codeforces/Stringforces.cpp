#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, k;
int dp[1 << 18];
int nxt[18][mxN];
int gd[18];
string s;

bool check(int g){
	if(!g) return 1;
	rep(i, (1 << k)) dp[i] = 1e9;
	dp[0] = 0;
	rep(i, k) gd[i] = 0;
	int cnt = 0;
	rep(i, n){
		if(!cnt){
			if(s[i] >= 'a' && s[i] <= (char)('a' + k)) cnt++;
		}
		else{
			if(s[i] == s[i - 1]) cnt++;
			else{
				if(cnt >= g) gd[(int)(s[i - 1] - 'a')] = 1;
				cnt = (s[i] >= 'a' && s[i] <= (char)('a' + k));
			}
		}
	}
	rep(i, k){
		int bal = 0;
		rep(j, g) if(s[j] == (char)('a' + i) || s[j] == '?') bal++;
		rep(j, n + 1) nxt[i][j] = 1e9;
		if(bal == g) nxt[i][0] = g;
		repn(j, 1, n - g + 1){
			if(s[j - 1] == (char)('a' + i) || s[j - 1] == '?') bal--;
			if(s[j + g - 1] == (char)('a' + i) || s[j + g - 1] == '?') bal++;
			if(bal == g) nxt[i][j] = j + g;
		}
		for(int j = n - 2; j >= 0; j--) nxt[i][j] = min(nxt[i][j], nxt[i][j + 1]);
	}
	repn(i, 1, (1 << k)){
		rep(j, k) if(i & (1 << j)){
			if(gd[j]) dp[i] = min(dp[i], dp[i ^ (1 << j)]);
			else if(dp[i ^ (1 << j)] < n) dp[i] = min(dp[i], nxt[j][dp[i ^ (1 << j)]]);
		}
	}
	if(dp[(1 << k) - 1] <= n) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	cin >> s;
	int l = 0, r = n;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
