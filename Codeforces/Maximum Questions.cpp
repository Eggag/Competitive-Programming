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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pi dp[mxN];
int q[mxN];
int a0[mxN], a1[mxN], b0[mxN], b1[mxN];

pi mx(pi a, pi b){
	if(a.fi > b.fi) return a;
	if(a.fi < b.fi) return b;
	if(a.se < b.se) return a;
	return b;
}

bool valid(int l, int r){
	if(l & 1){
		int sm = (a0[r] - (l ? a0[l - 1] : 0)) + (b1[r] - (l ? b1[l - 1] : 0));
		return !sm;
	}
	else{
		int sm = (a1[r] - (l ? a1[l - 1] : 0)) + (b0[r] - (l ? b0[l - 1] : 0));
		return !sm;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int m;
	cin >> m;
	rep(i, mxN) dp[i] = {0, 1e9};
	int p = (m == 1 && (s[0] == '?' || s[0] == 'a'));
	dp[0] = {p, (p && s[0] == '?')};
	rep(i, n){
		q[i] = (s[i] == '?');
		if(i) q[i] += q[i - 1];
	}
	rep(i, n){
		if(s[i] == 'a'){
			if(i & 1) a1[i]++;
			else a0[i]++;
		}
		if(s[i] == 'b'){
			if(i & 1) b1[i]++;
			else b0[i]++;
		}
		if(i){
			a0[i] += a0[i - 1];
			a1[i] += a1[i - 1];
			b0[i] += b0[i - 1];
			b1[i] += b1[i - 1];
		}
	}
	repn(i, 1, n){
		if(i >= (m - 1)){
			int sg = q[i] - (i == (m - 1) ? 0 : q[i - m]);
			if(i == (m - 1)){
				if(valid(0, i)) dp[i] = mx(dp[i], mp(1, sg));
			}
			else{
				if(valid(i - (m - 1), i)) dp[i] = mx(dp[i], mp(dp[i - m].fi + 1, dp[i - m].se + sg));
			}
		}
		dp[i] = mx(dp[i], dp[i - 1]);
	}
	cout << dp[n - 1].se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
