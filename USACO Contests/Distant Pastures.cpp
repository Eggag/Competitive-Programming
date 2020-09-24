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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("distant.in", "r", stdin);
	freopen("distant.out", "w", stdout);
	int n, a, b;
	cin >> n >> a >> b;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	ll ans = 0LL;
	rep(k, n) rep(l, n){
		ll dist[n][n];
		rep(i, n) rep(j, n) dist[i][j] = 1e18;
		dist[k][l] = 0;
		set<pair<ll, pi>> q;
		q.insert({0, mp(k, l)});
		while(q.size()){
			ll p = q.begin() -> fi;
			pi cur = q.begin() -> se;
			q.erase(q.begin());
			if((cur.fi + 1) < n){
				if(dist[cur.fi + 1][cur.se] > (dist[cur.fi][cur.se] + ((s[cur.fi + 1][cur.se] == s[cur.fi][cur.se]) ? a : b))){
					q.erase({dist[cur.fi + 1][cur.se], mp(cur.fi + 1, cur.se)});
					dist[cur.fi + 1][cur.se] = dist[cur.fi][cur.se] + ((s[cur.fi + 1][cur.se] == s[cur.fi][cur.se]) ? a : b);
					q.insert({dist[cur.fi + 1][cur.se], mp(cur.fi + 1, cur.se)});
				}
			}
			if((cur.fi - 1) >= 0){
				if(dist[cur.fi - 1][cur.se] > (dist[cur.fi][cur.se] + ((s[cur.fi - 1][cur.se] == s[cur.fi][cur.se]) ? a : b))){
					q.erase({dist[cur.fi - 1][cur.se], mp(cur.fi - 1, cur.se)});
					dist[cur.fi - 1][cur.se] = dist[cur.fi][cur.se] + ((s[cur.fi - 1][cur.se] == s[cur.fi][cur.se]) ? a : b);
					q.insert({dist[cur.fi - 1][cur.se], mp(cur.fi - 1, cur.se)});
				}
			}
			if((cur.se + 1) < n){
				if(dist[cur.fi][cur.se + 1] > (dist[cur.fi][cur.se] + ((s[cur.fi][cur.se + 1] == s[cur.fi][cur.se]) ? a : b))){
					q.erase({dist[cur.fi][cur.se + 1], mp(cur.fi, cur.se + 1)});
					dist[cur.fi][cur.se + 1] = dist[cur.fi][cur.se] + ((s[cur.fi][cur.se + 1] == s[cur.fi][cur.se]) ? a : b);
					q.insert({dist[cur.fi][cur.se + 1], mp(cur.fi, cur.se + 1)});
				}
			}
			if((cur.se - 1) >= 0){
				if(dist[cur.fi][cur.se - 1] > (dist[cur.fi][cur.se] + ((s[cur.fi][cur.se - 1] == s[cur.fi][cur.se]) ? a : b))){
					q.erase({dist[cur.fi][cur.se - 1], mp(cur.fi, cur.se - 1)});
					dist[cur.fi][cur.se - 1] = dist[cur.fi][cur.se] + ((s[cur.fi][cur.se - 1] == s[cur.fi][cur.se]) ? a : b);
					q.insert({dist[cur.fi][cur.se - 1], mp(cur.fi, cur.se - 1)});
				}
			}
		}
		rep(i, n) rep(j, n) ans = max(ans, dist[i][j]);
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
