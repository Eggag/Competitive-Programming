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

unordered_map<int, unordered_map<int, vector<pi>>> tel;
unordered_map<int, unordered_map<int, int>> minDist;
unordered_map<int, unordered_map<int, int>> vis;
vector<pi> telp1;

bool cmp(pi a, pi b){
	if(a.fi != b.fi) return a.fi < b.fi;
	else return a.se < b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("boards.in", "r", stdin);
	freopen("boards.out", "w", stdout);
	int n, p;
	cin >> n >> p;
	rep(i, p){
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		telp1.pb(mp(x, y));
		tel[x][y].pb(mp(x1, y1));
	}
	sort(all(telp1), cmp);
	set<pair<pi, int>> st; //coords, dist
	st.insert(mp(mp(0, 0), 0));
	minDist[0][0] = 0;
	vis[0][0] = 1;
	while(!st.empty()){
		pi cur = st.begin() -> fi;
		st.erase(st.begin());
		//try to take the teleporters
		for(pi tl : tel[cur.fi][cur.se]){
			if(minDist[cur.fi][cur.se] < minDist[tl.fi][tl.se] || !vis[tl.fi][tl.se]){
				st.erase({{tl.fi, tl.se}, minDist[tl.fi][tl.se]});
				minDist[tl.fi][tl.se] = minDist[cur.fi][cur.se];
				vis[tl.fi][tl.se] = 1;
				st.insert({{tl.fi, tl.se}, minDist[tl.fi][tl.se]});
			}
		}
		//try to walk to them, or the goal
		int start = (lb(all(telp1), mp(cur.fi - 1, (int)1e9))) - telp1.begin();
		repn(i, start, p){
			pi telp = telp1[i];
			if(telp.fi >= cur.fi && telp.se >= cur.se && !(telp.fi == cur.fi && telp.se == cur.se)){ //if we can go to it
				int d = (telp.fi - cur.fi) + (telp.se - cur.se);
				if((minDist[cur.fi][cur.se] + d) < minDist[telp.fi][telp.se] || !vis[telp.fi][telp.se]){
					st.erase({{telp.fi, telp.se}, minDist[telp.fi][telp.se]});
					minDist[telp.fi][telp.se] = minDist[cur.fi][cur.se] + d;
					vis[telp.fi][telp.se] = 1;
					st.insert({{telp.fi, telp.se}, minDist[telp.fi][telp.se]});
				}
			}	
		}
		//try to go straight for the (n, n)
		int d1 = 2 * n - cur.fi - cur.se;
		if(!vis[n][n] || (minDist[n][n] > (minDist[cur.fi][cur.se] + d1))){
			st.erase({{n, n}, minDist[n][n]});
			minDist[n][n] = minDist[cur.fi][cur.se] + d1;
			vis[n][n] = 1;
			st.insert({{n, n}, minDist[n][n]});
		}
	}
	cout << minDist[n][n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
