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

int d[25][25][25][25];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, 20) rep(j, 20) rep(k, 20) rep(l, 20) d[i][j][k][l] = 1e9;
	rep(i, h) cin >> s[i];
	rep(i, h) rep(j, w) if(s[i][j] == '.') d[i][j][i][j] = 0;
	rep(i, h) rep(j, w) if(s[i][j] == '.'){
		rep(k, 4){
			int x = dx[k] + i;
			int y = dy[k] + j;
			if(x >= 0 && x < h && y >= 0 && y < w && s[x][y] == '.'){
				d[i][j][x][y] = 1;
			}
		}
	}
	rep(k, h) rep(k1, w) rep(i, h) rep(i1, w) rep(j, h) rep(j1, w) if(s[k][k1] == '.' && s[i][i1] == '.' && s[j][j1] == '.'){
		d[i][i1][j][j1] = min(d[i][i1][j][j1], d[i][i1][k][k1] + d[k][k1][j][j1]);
	}
	int ans = 0;
	rep(i, h) rep(j, w) rep(k, h) rep(l, w){
		if(s[i][j] == '.' && s[k][l] == '.'){
			if(d[i][j][k][l] != 1e9) ans = max(ans, d[i][j][k][l]);
		}
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
