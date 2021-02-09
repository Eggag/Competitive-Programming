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
#define inf 0x3f3f3f3f
const int mxN = 12;
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, -2, 2, 1, -1, -1, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN][mxN];
int distK[mxN][mxN][mxN][mxN];
int distB[mxN][mxN][mxN][mxN];
pi dp[mxN * mxN][3];
pi pos[mxN * mxN];

bool valid(int i, int j){
	return (min(i, j) >= 0 && max(i, j) < n);
}

void chmin(pi& a, pi b){
	if(b.fi < a.fi) a = b;
	else if(b.fi == a.fi && b.se < a.se) a = b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) rep(j, n) cin >> a[i][j], pos[a[i][j]] = mp(i, j);
	memset(distK, inf, sizeof(distK));
	memset(distB, inf, sizeof(distB));
	//knight moves
	queue<pi> q;
	rep(i, n) rep(j, n){
		distK[i][j][i][j] = 0;
		q.push(mp(i, j));
		while(!q.empty()){
			pi cur = q.front();
			q.pop();
			rep(k, 8){
				int x = cur.fi + dx[k], y = cur.se + dy[k];
				if(valid(x, y) && distK[i][j][x][y] == inf){
					distK[i][j][x][y] = 1 + distK[i][j][cur.fi][cur.se];
					q.push(mp(x, y));
				}
			}
		}
	}
	//bishop moves
	rep(i, n) rep(j, n){
		distB[i][j][i][j] = 0;
		q.push(mp(i, j));
		while(!q.empty()){
			pi cur = q.front();
			q.pop();
			rep(k, 2) rep(l, 2) repn(m, 1, n){
				int dxB = (!k ? -1 : 1) * m;
				int dyB = (!l ? -1 : 1) * m;
				int x = cur.fi + dxB, y = cur.se + dyB;
				if(valid(x, y) && distB[i][j][x][y] == inf){
					distB[i][j][x][y] = 1 + distB[i][j][cur.fi][cur.se];
					q.push(mp(x, y));
				}
			}
		}
	}
	//dp
	rep(i, mxN * mxN) rep(j, 3) dp[i][j] = mp(inf, inf);
	dp[1][0] = dp[1][1] = dp[1][2] = mp(0, 0);
	repn(i, 2, (n * n) + 1){
		rep(j, 3) rep(k, 3) if(dp[i - 1][j].fi != inf){
			int cst = 0;
			if(!k){
				rep(m, n) rep(p, n){
					int num1 = distB[m][p][pos[i - 1].fi][pos[i - 1].se] + (j != 1);
					num1 += distK[m][p][pos[i].fi][pos[i].se] + 1;
					int num2 = (j != 1) + 1;
					pi pr = mp(dp[i - 1][j].fi + num1, dp[i - 1][j].se + num2);
					chmin(dp[i][k], pr);
				}
				cst = distK[pos[i].fi][pos[i].se][pos[i - 1].fi][pos[i - 1].se];
				if(cst == inf) continue;
			}
			else if(k == 1){
				rep(m, n) rep(p, n){
					int num1 = distK[m][p][pos[i - 1].fi][pos[i - 1].se] + (!!j);
					num1 += distB[m][p][pos[i].fi][pos[i].se] + 1;
					int num2 = (!!j) + 1;
					pi pr1 = mp(dp[i - 1][j].fi + num1, dp[i - 1][j].se + num2);
					chmin(dp[i][k], pr1);
				}
				cst = distB[pos[i].fi][pos[i].se][pos[i - 1].fi][pos[i - 1].se];
				if(cst == inf) continue;
			}
			else{
				cst = 1;
				if(pos[i].fi != pos[i - 1].fi && pos[i].se != pos[i - 1].se) cst++;
			}
			cst += (j != k);
			pi pr = mp(dp[i - 1][j].fi + cst, dp[i - 1][j].se + (j != k));
			chmin(dp[i][k], pr);
		}
	}
	pi ans = dp[n * n][0];
	chmin(ans, dp[n * n][1]);
	chmin(ans, dp[n * n][2]);
	cout << ans.fi << " " << ans.se << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
