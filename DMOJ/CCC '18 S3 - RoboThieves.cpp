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
int dist[105][105];
char s[105][105], g[105][105];

bool valid(int x, int y){
	return (x >= 0 && y >= 0 && x < n && y < m);
}

bool dir(char x){
	return (x == 'L' || x == 'R' || x == 'U' || x == 'D');
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	int x = -1, y = -1;
	rep(i, n) rep(j, m){
		cin >> s[i][j];
		if(s[i][j] == 'S') x = i, y = j;
	}
	memcpy(g, s, sizeof(s));
	/*
	rep(i, n){
		rep(j, m) cout << g[i][j] << " ";
		cout << endl;
	}
	*/
	rep(i, n) rep(j, m) if(s[i][j] == 'C'){
		int x1 = i;
		while(x1 < n && s[x1][j] != 'W') g[x1][j] = 'W', x1++;
		x1 = i;
		while(x1 >= 0 && s[x1][j] != 'W') g[x1][j] = 'W', x1--;
		int y1 = j;
		while(y1 < m && s[i][y1] != 'W') g[i][y1] = 'W', y1++;
		y1 = j;
		while(y1 >= 0 && s[i][y1] != 'W') g[i][y1] = 'W', y1--;
	}
	/*
	cout << "------" << endl;
	rep(i, n){
		rep(j, m) cout << g[i][j] << " ";
		cout << endl;
	}
	cout << "------" << endl;
	rep(i, n){
		rep(j, m) cout << s[i][j] << " ";
		cout << endl;
	}
	cout << "------" << endl;
	*/
	rep(i, 105) rep(j, 105) dist[i][j] = 1e9;
	dist[x][y] = 0;
	set<pair<int, pi>> q;
	q.insert(mp(dist[x][y], mp(x, y)));
	while(!q.empty()){
		pi u = q.begin() -> se; //current cell
		q.erase(q.begin());
		if(dir(s[u.fi][u.se])){
			//debug2(u.fi, u.se);
			char c = s[u.fi][u.se];
			int dx1 = 0, dy1 = 0;
			if(c == 'L') dy1 = -1;
			if(c == 'R') dy1 = 1;
			if(c == 'U') dx1 = -1;
			if(c == 'D') dx1 = 1;
			int x1 = u.fi + dx1, y1 = u.se + dy1;
			//debug2(x1, y1);
			if(valid(x1, y1) && (dir(s[x1][y1]) || g[x1][y1] != 'W')){
				if((dist[u.fi][u.se] + !dir(s[x1][y1])) < dist[x1][y1]){
					q.erase(mp(dist[x1][y1], mp(x1, y1)));
					dist[x1][y1] = dist[u.fi][u.se] + !dir(s[x1][y1]);
					q.insert(mp(dist[x1][y1], mp(x1, y1)));
				}
			}
		}
		else if(g[u.fi][u.se] != 'W'){
			rep(i, 4){
				int x1 = u.fi + dx[i], y1 = u.se + dy[i];
				if(valid(x1, y1) && (dir(s[x1][y1]) || g[x1][y1] != 'W')){
					if((dist[u.fi][u.se] + !dir(s[x1][y1])) < dist[x1][y1]){
						q.erase(mp(dist[x1][y1], mp(x1, y1)));
						dist[x1][y1] = dist[u.fi][u.se] + !dir(s[x1][y1]);
						q.insert(mp(dist[x1][y1], mp(x1, y1)));
					}
				}
			}
		}
	}
	rep(i, n) rep(j, m) if(s[i][j] == '.'){
		int res = dist[i][j];
		if(res >= 1e8) res = -1;
		cout << res << endl;
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
