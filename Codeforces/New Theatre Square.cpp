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
const int mxN = 1005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s[mxN];
int vis[105][mxN];

void solve(){
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	rep(i, n) cin >> s[i];
	int nm = 0;
	rep(i, n) rep(j, m) nm += (s[i][j] == '.');
	if((x * 2) < y){
		cout << nm * x << endl;
		return;
	}
	int ans = 0;
	rep(i, n) rep(j, m) vis[i][j] = 0;
	rep(i, n){
		rep(j, m) if(s[i][j] == '.'){
			if(j && s[i][j - 1] == '.' && !vis[i][j - 1]){
				vis[i][j] = vis[i][j - 1] = 1;
				ans += y - x;	
			}
			else ans += x;
		}
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
