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
const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy[8] = {1, -1, 0, 1, -1, -1, 1, 0};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
vector<string> s;
vector<string> g;
vector<vi> dist, dist1;

bool valid(int i, int j){
	return (min(i, j) >= 0 && i < n && j < m);
}

bool check(int t){
	queue<pi> q;
	rep(i, n) rep(j, m){
		g[i][j] = '.';
		dist1[i][j] = 0;
		if(dist[i][j] > t){
			g[i][j] = 'X';
			dist1[i][j] = t + 1;
			q.push(mp(i, j));
		}
	}
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		rep(i, 8){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && dist1[x][y] < (dist1[cur.fi][cur.se] - 1)){
				dist1[x][y] = dist1[cur.fi][cur.se] - 1;
				q.push(mp(x, y));
			}
		}
	}
	rep(i, n) rep(j, m){
		if(s[i][j] == '.'){
			if(dist1[i][j] > 0) return 0;
		}
		else if(dist1[i][j] <= 0) return 0;
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	s.resize(n);
	rep(i, n) cin >> s[i];
	string a = "";
	rep(j, m) a += '.';
	g.resize(n);
	rep(i, n) g[i] = a;
	dist.resize(n);
	dist1.resize(n);
	vi b(m, 0);
	rep(i, n) dist[i] = dist1[i] = b;
	queue<pi> q;
	rep(i, n) rep(j, m){
		if(s[i][j] == '.'){
			dist[i][j] = 0;
			q.push(mp(i, j));
		}
		else dist[i][j] = 1e9;
	}
	while(!q.empty()){
		pi cur = q.front();
		q.pop();
		rep(i, 8){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && dist[x][y] == 1e9){
				dist[x][y] = dist[cur.fi][cur.se] + 1;
				q.push(mp(x, y));
			}
		}
	}
	rep(i, n) rep(j, m){
		dist[i][j] = min({dist[i][j], i + 1, j + 1, (n - i), (m - j)});
	}
	int l = 0, r = min(n, m) + 1;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	assert(check(l));
	rep(i, n) cout << g[i] << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
