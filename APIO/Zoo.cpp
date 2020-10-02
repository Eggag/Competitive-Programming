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
const int mxN = 5e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int st[mxN];
vi l[mxN], f[mxN];
int gd[mxN];
int bd[mxN];
int p[5][32][32];
int dp[2][32];
int ch[mxN][32];

int check(int i, int msk){
	rep(j, 5) if((gd[i] & (1 << j)) && (msk & (1 << j))) return 1;
	rep(j, 5) if((bd[i] & (1 << j)) && !(msk & (1 << j))) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, c;
	cin >> n >> c;
	rep(i, c){
		cin >> st[i];
		int x, x2;
		cin >> x >> x2;
		rep(j, x){
			int y;
			cin >> y;
			f[i].pb(y);
		}
		rep(j, x2){
			int y;
			cin >> y;
			l[i].pb(y);
		}
	}
	rep(i, c){
		int cur = st[i];
		rep(j, 5){
			rep(k, l[i].size()) if(l[i][k] == cur) gd[i] |= (1 << j);
			rep(k, f[i].size()) if(f[i][k] == cur) bd[i] |= (1 << j);
			cur++;
			if(cur == (n + 1)) cur = 1;
		}
	}
	int ans = 0;
	rep(i, 5){
		rep(j, 32) rep(k, 32){
			int fl = 1;
			rep(m, 5 - i){
				if((bool)(j & (1 << m)) != (bool)(k & (1 << (m + i)))){
					fl = 0;
					break;
				}
			}
			p[i][j][k] = fl;
		}
	}
	rep(i, c) rep(j, 32) ch[i][j] = check(i, j);
	rep(msk, (1 << 5)){
		memset(dp, -1, sizeof(dp));
		dp[0][msk] = ch[0][msk];
		ans = max(ans, dp[0][msk]);
		repn(i, 1, c){
			int cr = i & 1, pr = 1 - cr;
			rep(k, (1 << 5)){
				rep(j, (1 << 5)) if(dp[pr][j] != -1){
					int fl = 1;
					if((st[i] - st[i - 1]) < 5){
						int dif = st[i] - st[i - 1];
						fl = p[dif][k][j];
					}
					if(!fl) continue;
					if(((n - st[i]) + st[0]) < 5){
						int dif = (n - st[i]) + st[0];
						fl = p[dif][msk][k];
					}
					if(!fl) continue;
					dp[cr][k] = max(dp[cr][k], dp[pr][j] + ch[i][k]);
					ans = max(ans, dp[cr][k]);
				}
			}
			rep(j, 32) dp[pr][j] = -1;
		}
	}
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
