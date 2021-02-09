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
const int mxN = 2005;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const char dir[4] = {'v', '^', '<', '>'};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
int dist[mxN][mxN];
int p[mxN][mxN];

bool valid(int i, int j){
	return (min(i, j) >= 0 && i < n && j < m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	pi st, go;
	rep(i, n) rep(j, m){
		if(s[i][j] == 'o') st = mp(i, j);
		else if(s[i][j] == 'x') go = mp(i, j);
	}
	memset(dist, 0x3f3f3f3f, sizeof(dist));
	dist[st.fi][st.se] = 0;
	p[st.fi][st.se] = -1;
	set<pair<int, pi>> q;
	q.insert(mp(0, st));
	while(!q.empty()){
		pair<int, pi> cur = *q.begin();
		q.erase(q.begin());
		int k = cur.se.fi, j = cur.se.se;
		rep(i, 4){
			int x = k + dx[i], y = j + dy[i];
			int cst = 1;
			if(s[k][j] == 'o' || s[k][j] == dir[i]) cst = 0;
			if(valid(x, y) && cur.fi + cst < dist[x][y]){
				q.erase(mp(dist[x][y], mp(x, y)));
				dist[x][y] = cst + cur.fi;
				p[x][y] = i;
				q.insert(mp(dist[x][y], mp(x, y)));
			}
		}
	}
	pi cur = go;
	while(p[cur.fi][cur.se] != -1){
		char ch = dir[p[cur.fi][cur.se]];
		pi cur1 = cur;
		cur1.fi += dx[p[cur.fi][cur.se]] * -1;
		cur1.se += dy[p[cur.fi][cur.se]] * -1;
		cur = cur1;
		if(s[cur.fi][cur.se] != 'o') s[cur.fi][cur.se] = ch;
	}
	cout << dist[go.fi][go.se] << '\n';
	rep(i, n) cout << s[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
