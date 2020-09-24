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

ll s[105][105];
int vis[105][105];

ll solve(){
	int r, c;
	cin >> r >> c;
	rep(i, r) rep(j, c) cin >> s[i][j];
	ll ans = 0LL;
	rep(i, r) rep(j, c) vis[i][j] = 0;
	while(true){
		//simulate the process
		vector<pi> proc;
		rep(i, r) rep(j, c) if(!vis[i][j]){
			ans += s[i][j];
			int i1 = i + 1;
			ll av = 0, av1 = 0, av2 = 0, av3 = 0;
			while(i1 < r){
				if(!vis[i1][j]){
					av = s[i1][j];
					break;
				}
				i1++;
			}
			i1 = i - 1;
			while(i1 >= 0){
				if(!vis[i1][j]){
					av1 = s[i1][j];
					break;
				}
				i1--;
			}
			int j1 = j + 1;
			while(j1 < c){
				if(!vis[i][j1]) {
					av2 = s[i][j1];
					break;
				}
				j1++;
			}
			j1 = j - 1;
			while(j1 >= 0){
				if(!vis[i][j1]){
					av3 = s[i][j1];
					break;
				}
				j1--;
			}
			ll cnt = (av > 0) + (av1 > 0) + (av2 > 0) + (av3 > 0);
			if((s[i][j] * cnt) < (av + av1 + av2 + av3)){
				proc.pb(mp(i, j));
			}
		}
		if(!proc.size()) break;
		rep(i, proc.size()) vis[proc[i].fi][proc[i].se] = 1;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": " << solve() << endl;
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
