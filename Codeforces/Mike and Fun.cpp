#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[505][505];
int best[505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	rep(i, n) rep(j, m) cin >> g[i][j];
	rep(i, n){
		int ans = 0;
		int cur = 0;
		rep(j, m){
			if(g[i][j]) cur++;
			else{
				ans = max(ans, cur);
				cur = 0;
			}
		}
		ans = max(ans, cur);
		best[i] = ans;
	}
	rep(i, q){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a][b] ^= 1;
		int ans = 0;
		int cur = 0;
		rep(k, m){
			if(g[a][k] == 1) cur++;
			else{
				ans = max(ans, cur);
				cur = 0;
			}	
		}
		ans = max(ans, cur);
		best[a] = ans;
		int res = 0;
		rep(i, n) res = max(res, best[i]);
		cout << res << endl;
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
