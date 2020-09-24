#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int a[5005];
int dp[5005][5005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n){
		cin >> a[i];
		dp[0][i] = a[i];
	}
	repn(i, 1, n){
		rep(j, n - i){
			dp[i][j] = dp[i - 1][j] ^ dp[i - 1][j + 1];
		}
	}
	repn(i, 1, n) rep(j, n - i){
		dp[i][j] = max({dp[i][j], dp[i - 1][j], dp[i - 1][j + 1]});
	}
	int q;
	cin >> q;
	rep(i, q){
		int l, r;
		cin >> l >> r;
		int len = r - l;
		l--;
		cout << dp[len][l] << endl;
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
