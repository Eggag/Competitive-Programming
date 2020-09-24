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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int mxN = 805;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int h, w, k;
int vis[mxN][mxN];
int dist[mxN][mxN];

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < h && j < w);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> h >> w >> k;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	pi st;
	rep(i, h) rep(j, w) if(s[i][j] == 'S') st = mp(i, j), s[i][j] = '.';
	vector<pi> proc = {st};
	vis[st.fi][st.se] = 1;
	queue<pi> q;
	q.push(st);
	int cnt = 0;
	while(cnt < k && !q.empty()){
		queue<pi> q1;
		while(!q.empty()){
			pi cur = q.front();
			q.pop();
			rep(i, 4){
				int x = dx[i] + cur.fi, y = dy[i] + cur.se;
				if(valid(x, y) && !vis[x][y] && s[x][y] != '#'){
					vis[x][y] = 1;
					proc.pb(mp(x, y));
					q1.push(mp(x, y));
				}
			}
		}	
		cnt++;
		q = q1;
	}
	rep(i, mxN) rep(j, mxN) dist[i][j] = 1e9;
	set<pair<int, pi>> q2;
	rep(i, proc.size()){
		dist[proc[i].fi][proc[i].se] = 0;
		q2.insert(mp(0, mp(proc[i].fi, proc[i].se)));
	}
	int ans = 1e9;
	while(!q2.empty()){
		pair<int, pi> cur = *q2.begin();
		q2.erase(q2.begin());
		rep(i, 4){
			int x = dx[i] + cur.se.fi, y = dy[i] + cur.se.se;
			if(valid(x, y) && dist[x][y] > (1 + dist[cur.se.fi][cur.se.se])){
				q2.erase(mp(dist[x][y], mp(x, y)));
				dist[x][y] = dist[cur.se.fi][cur.se.se] + 1;
				q2.insert(mp(dist[x][y], mp(x, y)));
			}
		}
	}
	rep(i, h) ans = min(ans, (dist[i][w - 1] + k - 1) / k);
	rep(i, h) ans = min(ans, (dist[i][0] + k - 1) / k);
	rep(j, w) ans = min(ans, (dist[h - 1][j] + k - 1) / k);
	rep(j, w) ans = min(ans, (dist[0][j] + k - 1) / k);
	cout << ans + 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
