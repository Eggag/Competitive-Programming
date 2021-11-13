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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;

pi f(char c, pi a){
	if(c == 'U') return mp(a.fi - 1, a.se);
	if(c == 'R') return mp(a.fi, a.se + 1);
	if(c == 'D') return mp(a.fi + 1, a.se);
	if(c == 'L') return mp(a.fi, a.se - 1);
}

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void solve(){
	cin >> n >> m;
	vector<string> s(n), d(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> d[i];
	vector<vi> vis(n, vi(m, 0));
	vector<vi> cyc(n, vi(m, 0));
	vector<vector<pi>> pre(n, vector<pi>(m, mp(-1, -1)));
	int cnt = 1;
	int ans = 0;
	rep(i, n) rep(j, m) if(!vis[i][j]){
		int st = cnt;
		pi cur = mp(i, j);
		while(true){
			pi nxt = f(d[cur.fi][cur.se], cur);
			if(!cyc[nxt.fi][nxt.se]) pre[nxt.fi][nxt.se] = cur;
			vis[cur.fi][cur.se] = cnt++;
			if(vis[nxt.fi][nxt.se]){
				if(vis[nxt.fi][nxt.se] >= st){
					pre[nxt.fi][nxt.se] = cur;
					int nm = cnt - vis[nxt.fi][nxt.se];
					ans += nm;
					pi nw = cur;
					while(true){
						cyc[nw.fi][nw.se] = 1;
						nw = pre[nw.fi][nw.se];
						if(nw.fi == cur.fi && nw.se == cur.se) break;
					}
				}
				break;
			}
			cur = nxt;
		}
	}
	int ans1 = 0;
	rep(i, n) rep(j, m) if(cyc[i][j] && s[i][j] == '0') ans1++;
	vis = cyc;
	rep(i, n) rep(j, m) if(!vis[i][j]){
		pi cur = mp(i, j);
		pi st = mp(-1, -1), ot = mp(-1, -1);
		while(true){
			pi nxt = f(d[cur.fi][cur.se], cur);
			if(cyc[nxt.fi][nxt.se]){
				st = cur;
				ot = pre[nxt.fi][nxt.se];
				break;
			}
			cur = nxt;
		}
		pi in = ot;
		vector<pi> uwu;
		int sz = 0, fl = 0;
		queue<pair<int, pi>> q;
		q.push(mp(0, st));
		vis[st.fi][st.se] = 1;
		while(!q.empty()){
			pair<int, pi> cr = q.front();
			q.pop();
			if(s[cr.se.fi][cr.se.se] == '0'){
				if(cr.fi >= sz && !fl){
					while(cr.fi >= sz){
						uwu.pb(ot);
						sz++;
						ot = pre[ot.fi][ot.se];
						if(ot.fi == in.fi && ot.se == in.se){
							fl = 1;
							break;
						}
					}
				}
				pi nw = uwu[cr.fi % sz];	
				if(s[nw.fi][nw.se] == '1'){
					s[nw.fi][nw.se] = '0';
					ans1++;
				}
			}
			rep(k, 4){
				int x = cr.se.fi + dx[k], y = cr.se.se + dy[k];
				if(valid(x, y) && !vis[x][y]){
					pi nx = f(d[x][y], mp(x, y));		
					if(nx.fi == cr.se.fi && nx.se == cr.se.se){
						vis[x][y] = 1;
						q.push(mp(cr.fi + 1, mp(x, y)));
					}
				}
			}
		}
	}
	cout << ans << " " << ans1 << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
