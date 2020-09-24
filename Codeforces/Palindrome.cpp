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
const int mxN = 5e4 + 1;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[27];
pi mn[27][51];
int dp[mxN][51][4];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	rep(i, n) g[s[i] - 'a'].pb(i);
	rep(i, n) rep(k, 51) rep(l, 4) dp[i][k][l] = 0;
	rep(i, 26) rep(j, 51){
		if(!j) mn[i][j] = {n, 0};
		else mn[i][j] = {1e9, -1};
	}
	rep(i, n){
		int v = s[i] - 'a';
		for(int len = 49; len >= 0; len--) rep(j, 26) if(mn[j][len].fi != 1e9){
			if(!len){
				if(g[v][(int)g[v].size() - 1] > i){
					if(mn[v][1].fi == 1e9 || mn[v][1].fi < g[v][(int)g[v].size() - 1]){
						mn[v][1] = {g[v][g[v].size() - 1], i};
						dp[i][1][0] = 1;
						dp[i][1][1] = -1;
						dp[i][1][2] = mn[v][1].fi;
						dp[i][1][3] = -1;
					}
				}
			}
			else{
				int l = 0, r = g[v].size() - 1;
				while(l < r){
					int mid = (l + r + 1) / 2;
					if(g[v][mid] < mn[j][len].fi) l = mid;
					else r = mid - 1;
				}
				if(g[v][l] > i){
					if(mn[v][len + 1].fi == 1e9 || mn[v][len + 1].fi < g[v][l]){
						mn[v][len + 1] = {g[v][l], i};
						dp[i][len + 1][0] = 1;
						dp[i][len + 1][1] = j;
						dp[i][len + 1][2] = mn[v][len + 1].fi;
						dp[i][len + 1][3] = mn[j][len].se;
					}
				}
			}
		}
	}
	int ans = 0;
	rep(i, n) rep(k, 51) if(dp[i][k][0]) ans = max(ans, k);
	if(ans == 50){
		int mx = 0;
		array<int, 2> bst = {-1, -1};
		rep(i, n) rep(k, 51){
			if(dp[i][k][0]){
				int cur = k;
				if(cur > mx){
					mx = cur;
					bst = {i, k};
				}
			}
		}
		if(bst[0] == -1){
			cout << s[0] << endl;
			return 0;
		}
		int st = bst[0];
		string res = "";
		while(mx--){
			if(bst[1] == -1) break;
			else if(bst[0] == -1) break;
			else{
				res += s[bst[0]];
				bst[0] = dp[bst[0]][bst[1]][3], bst[1]--;
			}
		}
		string res1 = res;
		reverse(all(res1));
		cout << res1 << res << endl;
	}
	else{
		int mx = 0;
		array<int, 2> bst = {-1, -1};
		int f = 0;
		rep(i, n) rep(k, 51){
			if(dp[i][k][0]){
				int cur = 2 * k + ((dp[i][k][2] - i) > 1);
				if(cur == mx){
					mx = cur;
					f |= ((dp[i][k][2] - i) > 1);
					bst = {i, k};
				}
				if(cur > mx){
					mx = cur;
					f = ((dp[i][k][2] - i) > 1);
					bst = {i, k};
				}
			}
		}
		if(bst[0] == -1){
			cout << s[0] << endl;
			return 0;
		}
		int st = bst[0];
		if(f) mx--;
		string res = "";
		while(mx--){
			if(bst[1] == -1) break;
			else if(bst[0] == -1) break;
			else{
				res += s[bst[0]];
				bst[0] = dp[bst[0]][bst[1]][3], bst[1]--;
			}
		}
		string res1 = res;
		reverse(all(res1));
		if(f) cout << res1 << s[st + 1] << res << endl;
		else cout << res1 << res << endl;
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
