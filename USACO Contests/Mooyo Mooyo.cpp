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

int n, k;
string g[105];
int v[105][15];

vector<pi> cur;

void dfs(int a, int b){
	cur.pb(mp(a, b));
	v[a][b] = 1;
	if(a + 1 < n && !v[a + 1][b] && g[a][b] == g[a + 1][b]) dfs(a + 1, b);
	if(b + 1 < 10 && !v[a][b + 1] && g[a][b] == g[a][b + 1]) dfs(a, b + 1);
	if(a - 1 >= 0 && !v[a - 1][b] && g[a][b] == g[a - 1][b]) dfs(a - 1, b);
	if(b - 1 >= 0 && !v[a][b - 1] && g[a][b] == g[a][b - 1]) dfs(a, b - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> g[i];
	while(1){
		int f = 0;
		rep(i, 105) rep(j, 15) v[i][j] = 0;
		rep(i, n) rep(j, 10) if(!v[i][j] && g[i][j] != '0'){
			cur.clear();
			dfs(i, j);
			if(cur.size() >= k){
				f = 1;
				rep(m, cur.size()){
					g[cur[m].fi][cur[m].se] = '0';
				}
			}
		}
		if(!f){
			break;
		}
		rep(i, 10){
			for(int j = n - 2; j >= 0; j--){
				int ind = j;
				while(ind < (n - 1) && g[ind + 1][i] == '0') swap(g[ind + 1][i], g[ind][i]), ind++;
			}
		}
	}
	rep(i, n){
		rep(j, 10) cout << g[i][j];
		cout << endl;
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
