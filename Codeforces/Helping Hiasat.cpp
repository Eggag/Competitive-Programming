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
const int mxM = 45;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxM];
int ok[mxM][mxM];
int dp[1 << 21], dp1[1 << 21];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pair<int, string>> q(n);
	set<string> v;
	rep(i, n){
		int t;
		cin >> t;
		string s = "";
		if(t == 2) cin >> s, v.insert(s);
		q[i] = mp(t, s);
	}
	if(m == 1){
		cout << 1 << endl;
		return 0;
	}
	int nm = 0;
	map<string, int> cc;
	for(string s : v) cc[s] = nm++;
	int cnt = -1;
	rep(i, n){
		if(q[i].fi == 1) cnt++;
		else g[cc[q[i].se]].pb(cnt);
	}
	rep(i, m) rep(j, m) if(i != j){
		int f = 1;
		rep(k, g[i].size()){
			auto it = lb(all(g[j]), g[i][k]);
			if(it != g[j].end()){
				if(*it == g[i][k]){
					f = 0;
					break;
				}
			}
		}
		ok[i][j] = ok[j][i] = f;
	}
	int n1 = m / 2, n2 = (m + 1) / 2;
	rep(i, 1 << n1){
		vi ch;
		rep(j, n1) if(i & (1 << j)) ch.pb(j);
		rep(j, n1) if(!(i & (1 << j))){
			int f = 1;
			rep(k, ch.size()) if(!ok[ch[k]][j]){
				f = 0;
				break;
			}
			dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] + f);
		}
	}
	rep(i, 1 << n2){
		vi ch;
		rep(j, n2) if(i & (1 << j)) ch.pb(j);
		rep(j, n2) if(!(i & (1 << j))){
			int f = 1;
			rep(k, ch.size()) if(!ok[ch[k] + n1][j + n1]){
				f = 0;
				break;
			}
			dp1[i | (1 << j)] = max(dp1[i | (1 << j)], dp1[i] + f);
		}
	}
	rep(i, 1 << n2) rep(j, n2) dp1[i | (1 << j)] = max(dp1[i | (1 << j)], dp1[i]);
	int ans = 0;
	rep(i, 1 << n1){
		vi ch;
		rep(j, n1) if(i & (1 << j)) ch.pb(j);
		int msk = 0;
		repn(j, n1, m){
			int f = 1;
			rep(k, ch.size()) if(!ok[ch[k]][j]){
				f = 0;
				break;
			}
			if(f) msk |= (1 << (j - n1));
		}
		ans = max(ans, dp[i] + dp1[msk]);
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
