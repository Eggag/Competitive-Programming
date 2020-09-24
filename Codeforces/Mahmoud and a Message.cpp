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
const int MOD = 1e9 + 7;
const int mxN = 1e3 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dp[mxN];
int a[30];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, 26) cin >> a[i];
	rep(i, n){
		int mn = 1e9;
		for(int j = i; j >= 0; j--){
			mn = min(mn, a[s[j] - 'a']);
			if(mn < (i - j + 1)) break;
			(dp[i] += (j ? dp[j - 1] : 1)) %= MOD;
		}
	}
	cout << dp[n - 1] << endl;
	int mx = 0;
	rep(i, n){
		int mn = 1e9;
		repn(j, i, n){
			mn = min(mn, a[s[j] - 'a']);
			if(mn < (j - i + 1)) break;
			mx = max(mx, j - i + 1);
		}
	}
	cout << mx << endl;
	int num = 1;
	int lst = 0;
	int mn = a[s[0] - 'a'];
	repn(i, 1, n){
		mn = min(mn, a[s[i] - 'a']);
		if(mn < (i - lst + 1)){
			num++;
			lst = i;
			mn = a[s[i] - 'a'];
		}
		else mx = max(mx, i - lst + 1);
	}
	cout << num << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
