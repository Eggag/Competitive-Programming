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
int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int dy[8] = {-2, 2, -1, 1, -2, 2, -1, 1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

char g[105][105];
int n;

bool valid(int x, int y){
	return ((y >= 0 && y < n) && (x >= 0 && x < n));
}

void dfs(int x, int y){
	rep(i, 8){
		int x1 = dx[i] + x, y1 = dy[i] + y;
		if(valid(x1, y1) && g[x1][y1] == 'a'){ //not visited before
			if(g[x][y] == 'W') g[x1][y1] = 'B';
			else g[x1][y1] = 'W';
			dfs(x1, y1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, 105) rep(j, 105) g[i][j] = 'a';
	g[0][0] = 'W';
	dfs(0, 0);
	rep(i, n){
		rep(j, n) cout << ((g[i][j] == 'a') ? 'B' : g[i][j]);
		cout << endl;
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
