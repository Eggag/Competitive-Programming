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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
 
template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }
 
int n, m;
char g[1005][1005];
int dist[1005][1005];
char prv[1005][1005];
 
bool valid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#');
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	pi st, fn;
	rep(i, n) rep(j, m){
		cin >> g[i][j];
		if(g[i][j] == 'A') st = mp(i, j);
		if(g[i][j] == 'B') fn = mp(i, j);
	}
	rep(i, n) rep(j, m) dist[i][j] = 1e9;
	dist[st.fi][st.se] = 0;
	rep(i, n) rep(j, m) prv[i][j] = '.';
	set<pair<int, pi>> q;
	q.insert(mp(0, st));
	vector<char> ch = {'R', 'D', 'L', 'U'};
	while(!q.empty()){
		pi cur = q.begin() -> se;
		q.erase(q.begin());
		rep(i, 4){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && dist[x][y] > (dist[cur.fi][cur.se] + 1)){
				q.erase(mp(dist[x][y], mp(x, y)));
				dist[x][y] = dist[cur.fi][cur.se] + 1;
				prv[x][y] = ch[i];
				q.insert(mp(dist[x][y], mp(x, y)));
			}
		}
	}
	if(dist[fn.fi][fn.se] <= 1e8){
		cout << "YES" << endl;
		cout << dist[fn.fi][fn.se] << endl;
		string ans = "";
		pi nw = mp(fn.fi, fn.se);
		while(prv[nw.fi][nw.se] != '.'){
			ans += prv[nw.fi][nw.se];
			char c = prv[nw.fi][nw.se];
			if(c == 'L') nw.fi++;
			if(c == 'R') nw.fi--;
			if(c == 'U') nw.se++;
			if(c == 'D') nw.se--;
		}
		reverse(all(ans));
		rep(i, ans.size()){
			if(ans[i] == 'U') ans[i] = 'L';
			else if(ans[i] == 'D') ans[i] = 'R';
			else if(ans[i] == 'L') ans[i] = 'U';
			else if(ans[i] == 'R') ans[i] = 'D';
		}
		cout << ans << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
