#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
const int mxN = 41;
const int MOD = 1e9 + 7;

int dp[mxN][mxN][mxN][mxN];
int inn[mxN][mxN][mxN][mxN];
int in[mxN][mxN][mxN];

struct point{
	int x, y;
};

int ccw(point a, point b, point c){
	int cur = ((c.y - a.y) * (b.x - a.x)) - ((b.y - a.y) * (c.x - a.x));
	assert(cur != 0);
	if(cur > 0) return 1;
	else return -1;
}

int inside(point p, vector<point> t){
	vi s(3);
	rep(i, 3) s[i] = ccw(p, t[(i + 1) % 3], t[i]);
	if(s[0] == s[1] && s[1] == s[2]) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<point> p(n);
	rep(i, n) cin >> p[i].x >> p[i].y;
	rep(i, n) rep(j, n) rep(k, n) if(i != j && i != k && j != k) dp[3][i][j][k] = 1;
	rep(i, n) rep(j, n) rep(k, n) if(i != j && j != k && i != k){
		vector<point> t = {p[i], p[j], p[k]};
		rep(l, n) if(i != l && j != l && k != l){
			if(inside(p[l], t)) in[i][j][k]++;
		}
	}
	rep(i, n) rep(j, n) rep(k, n) if(i != j && j != k && i != k){
		vector<point> t = {p[i], p[j], p[k]};
		rep(l, n) if(i != l && j != l && k != l){
			if(inside(p[l], t)) inn[l][i][j][k] = 1;
		}
	}
	repn(m, 4, n + 1){
		rep(i, n) rep(j, n) rep(k, n) if(i != j && j != k && i != k && dp[m - 1][i][j][k]){
			int ds = 0;
			rep(cur, n) if(cur != i && cur != j && cur != k){
				if(inn[cur][i][j][k]){
					if((in[i][j][k] + 3 - ds) >= m){
						dp[m][i][j][k] += dp[m - 1][i][j][k];
						if(dp[m][i][j][k] >= MOD) dp[m][i][j][k] -= MOD;
						ds++;
					}
					continue;
				}
				vi gd;
				if(inn[i][cur][j][k]) gd = {cur, j, k};
				else if(inn[j][cur][i][k]) gd = {cur, i, k};
				else if(inn[k][cur][i][j]) gd = {cur, i, j};
				else continue;
				dp[m][gd[0]][gd[1]][gd[2]] += dp[m - 1][i][j][k];
				if(dp[m][gd[0]][gd[1]][gd[2]] >= MOD) dp[m][gd[0]][gd[1]][gd[2]] -= MOD;
			}
		}
	}
	int ans = 0LL;
	rep(i, n) rep(j, n) rep(k, n){
		ans += dp[n][i][j][k];
		if(ans >= MOD) ans -= MOD;
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
