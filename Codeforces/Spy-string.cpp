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

pair<int, pair<int, char>> dp[15][26][1 << 12];

void solve(){
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	rep(i, m + 1) rep(j, 26) rep(k, 1 << 12) dp[i][j][k] = mp(0, mp(-1, '.'));
	rep(i, 26) dp[0][i][0] = mp(1, mp(-1, '.'));	
	repn(i, 1, m + 1){
		rep(j, 26) rep(l, 26){ //j is previous letter, l is our current choice
			rep(k, 1 << n) if(dp[i - 1][j][k].fi){
				int cur = 0; //our current mask
				rep(p, n) if(s[p][i - 1] != (char)('a' + l)) cur |= 1 << p;
				int bad = 0;
				if((cur + k) != (cur | k)) bad = 1;
				/*
				rep(p, n) if((cur & (1 << p)) && (k & (1 << p))){
					bad = 1;
					break;
				}
				*/
				if(!bad){
					dp[i][l][k | cur] = mp(1, mp(k, (char)('a' + j)));
				}
			}
		}
	}
	//now we reconstruct the answer
	rep(j, 26) rep(k, 1 << n){
		if(dp[m][j][k].fi){
			string ans = "";
			ans += (char)('a' + j);
			int prev = dp[m][j][k].se.fi;
			char lst = dp[m][j][k].se.se;
			for(int i = m - 1; i >= 1; i--){
				if(ans.size() == m) break;
				ans += lst;
				char lst1 = lst;
				lst = dp[i][(int)(lst - 'a')][prev].se.se;
				prev = dp[i][(int)(lst1 - 'a')][prev].se.fi;
				//ans += dp[i][(int)(lst - 'a')][prev].se.fi;
				//prev = 
			}
			reverse(all(ans));
			cout << ans << endl;
			return;
		}
	}
	cout << -1 << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
