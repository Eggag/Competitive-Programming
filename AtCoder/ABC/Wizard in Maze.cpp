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
const int mxN = 1005;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int dist[mxN][mxN];
int h, w;

bool valid(int i, int j){
	return (i >= 0 && i < h && j >= 0 && j < w);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> h >> w;
	int ch, cw, dh, dw;
	cin >> ch >> cw;
	cin >> dh >> dw;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	rep(i, h) rep(j, w) dist[i][j] = 1e9;
	dist[ch - 1][cw - 1] = 0LL;
	set<pair<int, pi>> q;
	q.insert(mp(0LL, mp(ch - 1, cw - 1)));
	while(!q.empty()){
		pair<int, pi> cur1 = *q.begin();
		pi cur = cur1.se;
		q.erase(q.begin());
		if(cur.fi == dh - 1 && cur.se == dw - 1){
			cout << cur1.fi << endl;
			return 0;
		}
		rep(i, 4){
			int x = cur.fi + dx[i], y = cur.se + dy[i];
			if(valid(x, y) && dist[cur.fi][cur.se] < dist[x][y] && s[x][y] == '.'){
				q.erase(mp(dist[x][y], mp(x, y)));
				dist[x][y] = dist[cur.fi][cur.se];
				q.insert(mp(dist[x][y], mp(x, y)));
			}
		}
		for(int i = -2; i <= 2; i++){
			for(int j = -2; j <= 2; j++){
				int x = cur.fi + i, y = cur.se + j;
				if(valid(x, y) && (dist[cur.fi][cur.se] + 1) < dist[x][y] & s[x][y] == '.'){
					q.erase(mp(dist[x][y], mp(x, y)));
					dist[x][y] = dist[cur.fi][cur.se] + 1;
					q.insert(mp(dist[x][y], mp(x, y)));
				}
			}
		}
	}
	if(dist[dh - 1][dw - 1] == 1e9) dist[dh - 1][dw - 1] = -1;
	cout << dist[dh - 1][dw - 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
