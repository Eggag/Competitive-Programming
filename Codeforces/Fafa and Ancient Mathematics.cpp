#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
const int mxN = 1e4 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

string s;
int n, p, m;
int nxt[mxN];
int f = 0;

vector<pi> solve(int l, int r){
	vector<vector<pi>> dp(2, vector<pi>(p + 1, {1e9, -1e9})); //{min, max}
	int fr = 1, cr = 1;
	repn(i, l + 1, r) if(s[i] != '?'){
		if(s[i] >= '0' && s[i] <= '9'){
			int uwu = (int)(s[i] - '0');
			if(fr){
				dp[0][0] = mp(uwu, uwu);
				fr = 0;
				continue;
			}
			rep(j, p + 1){
				if(!f){
					//add
					if(j < p){
						dp[cr][j + 1].se = max(dp[cr][j + 1].se, dp[1 - cr][j].se + uwu);
						dp[cr][j + 1].fi = min(dp[cr][j + 1].fi, dp[1 - cr][j].fi + uwu);
					}
					//sub
					dp[cr][j].se = max(dp[cr][j].se, dp[1 - cr][j].se - uwu);
					dp[cr][j].fi = min(dp[cr][j].fi, dp[1 - cr][j].fi - uwu);
				}
				else{
					//sub
					if(j < p){
						dp[cr][j + 1].se = max(dp[cr][j + 1].se, dp[1 - cr][j].se - uwu);
						dp[cr][j + 1].fi = min(dp[cr][j + 1].fi, dp[1 - cr][j].fi - uwu);
					}
					//add
					dp[cr][j].se = max(dp[cr][j].se, dp[1 - cr][j].se + uwu);
					dp[cr][j].fi = min(dp[cr][j].fi, dp[1 - cr][j].fi + uwu);
				}
			}
			cr = 1 - cr;
			rep(k, p + 1) dp[cr][k] = mp(1e9, -1e9);
		}
		else{
			vector<pi> owo = solve(i, nxt[i]);
			if(fr){
				dp[0] = owo;
				fr = 0;
				i = nxt[i];
				continue;
			}
			rep(g, p + 1) rep(k, p + 1){
				if(p < (g + k)) break;
				int j = g + k;
				rep(h, 2){
					int uwu = owo[k].fi;
					if(h) uwu = owo[k].se;
					if(uwu >= 1e8 || uwu <= -1e8) continue;
					if(!f){
						//add
						if(j < p){
							dp[cr][j + 1].se = max(dp[cr][j + 1].se, dp[1 - cr][g].se + uwu);
							dp[cr][j + 1].fi = min(dp[cr][j + 1].fi, dp[1 - cr][g].fi + uwu);
						}
						//sub
						dp[cr][j].se = max(dp[cr][j].se, dp[1 - cr][g].se - uwu);
						dp[cr][j].fi = min(dp[cr][j].fi, dp[1 - cr][g].fi - uwu);
					}
					else{
						//sub
						if(j < p){
							dp[cr][j + 1].se = max(dp[cr][j + 1].se, dp[1 - cr][g].se - uwu);
							dp[cr][j + 1].fi = min(dp[cr][j + 1].fi, dp[1 - cr][g].fi - uwu);
						}
						//add
						dp[cr][j].se = max(dp[cr][j].se, dp[1 - cr][g].se + uwu);
						dp[cr][j].fi = min(dp[cr][j].fi, dp[1 - cr][g].fi + uwu);
					}
				}
			}
			cr = 1 - cr;
			rep(k, p + 1) dp[cr][k] = mp(1e9, -1e9);
			i = nxt[i];
		}
	}
	return dp[1 - cr];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> s;
	cin >> p >> m;
	if(m < p) swap(m, p), f = 1;
	n = (int)(s.size());
	if(n == 1){
		cout << s << '\n';
		return 0;
	}
	vi op;
	rep(i, n){
		if(s[i] == '(') op.pb(i);
		if(s[i] == ')'){
			nxt[op.back()] = i;
			op.pop_back();
		}
	}
	vector<pi> ans = solve(0, n - 1);
	cout << ans[p].se << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
