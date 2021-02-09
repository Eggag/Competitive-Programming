#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y)
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sq(x) ((x) * (x))
#define inf 0x3f3f3f3f
const int mxN = 1005;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n, d;
int dist[mxN][mxN];
int dist1[mxN][mxN];
int dist2[mxN][mxN];
string s[mxN];

bool valid(int i, int j){
	return (min(i, j) >= 0 && max(i, j) < n);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	rep(i, n) cin >> s[i];
	set<pair<int, pi>> q;
	memset(dist, inf, sizeof(dist));
	rep(i, n) rep(j, n) if(s[i][j] == '#'){
		q.insert(mp(0, mp(i, j)));
		dist[i][j] = 0;
	}
	while(!q.empty()){
		pair<int, pi> cr = *q.begin();
		q.erase(q.begin());
		int x = cr.se.fi, y = cr.se.se;
		rep(i, 4){
			int x2 = x + dx[i], y2 = y + dy[i];
			if(valid(x2, y2)){
				if((cr.fi + 1) < dist[x2][y2]){
					q.erase(mp(dist[x2][y2], mp(x2, y2)));
					dist[x2][y2] = cr.fi + 1;
					q.insert(mp(dist[x2][y2], mp(x2, y2)));
				}
			}
		}
	}
	memset(dist1, inf, sizeof(dist1));
	rep(i, n) rep(j, n) if(s[i][j] == 'S'){
		dist1[i][j] = 0;
		q.insert(mp(0, mp(i, j)));
	}
	while(!q.empty()){
		pair<int, pi> cr = *q.begin();
		q.erase(q.begin());
		int x = cr.se.fi, y = cr.se.se;
		rep(i, 4){
			int x2 = x + dx[i], y2 = y + dy[i];
			if(valid(x2, y2)){
				if((cr.fi + 1) < dist1[x2][y2] && ((1 + ((cr.fi) / d)) <= dist[x][y]) && ((1 + ((cr.fi) / d)) <= dist[x2][y2]) && s[x2][y2] != '#'){
					q.erase(mp(dist1[x2][y2], mp(x2, y2)));
					dist1[x2][y2] = cr.fi + 1;
					q.insert(mp(dist1[x2][y2], mp(x2, y2)));
				}
			}
		}
	}
	memset(dist2, -1, sizeof(dist2));
	rep(i, n) rep(j, n) if(dist1[i][j] != inf){
		dist2[i][j] = (dist1[i][j] / d);
		if((1 + (dist1[i][j] / d)) > dist[i][j]) dist2[i][j] = ((dist1[i][j] - 1) / d);
		q.insert(mp(dist2[i][j], mp(i, j)));
	}
	while(!q.empty()){
		pair<int, pi> cr = *(--q.end());
		q.erase(--q.end());
		int x = cr.se.fi, y = cr.se.se;
		rep(i, 4){
			int x2 = x + dx[i], y2 = y + dy[i];
			if(valid(x2, y2)){
				if((cr.fi - 1) > dist2[x2][y2] && s[x2][y2] != '#'){
					q.erase(mp(dist2[x2][y2], mp(x2, y2)));
					dist2[x2][y2] = cr.fi - 1;
					q.insert(mp(dist2[x2][y2], mp(x2, y2)));
				}
			}
		}
	}
	int ans = 0;
	rep(i, n) rep(j, n) if(dist2[i][j] >= 0 && s[i][j] != '#') ans++;
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
