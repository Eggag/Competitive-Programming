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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n][m], b[n][m];
	string s[n];
	rep(i, n) cin >> s[i];
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	a[0][0] = 1;
	rep(i, n) rep(j, m) if(s[i][j] == '.' && a[i][j]){
		if(i < (n - 1) && s[i + 1][j] == '.') a[i + 1][j] = 1;
		if(j < (m - 1) && s[i][j + 1] == '.') a[i][j + 1] = 1;
	}
	if(!a[n - 1][m - 1]){
		cout << 0 << endl;
		return 0;
	}
	b[n - 1][m - 1] = 1;
	for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) if(s[i][j] == '.' && b[i][j]){
		if(i > 0 && s[i - 1][j] == '.') b[i - 1][j] = 1;
		if(j > 0 && s[i][j - 1] == '.') b[i][j - 1] = 1;
	}
	if(!b[0][0]){
		cout << 0 << endl;
		return 0;
	}
	vi cnt(n + m, 0);
	rep(i, n) rep(j, m){
		if(b[i][j] && a[i][j]) cnt[i + j]++;
	}
	int ans = 2;
	repn(i, 1, n + m - 2) if(cnt[i] == 1) ans = 1;
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
