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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

struct rect{
	int x, y, x1, y1;
};

int g[1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<rect> p(n);
	memset(g, 0, sizeof(g));
	rep(i, n){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		p[i] = (rect){a, b, c, d};
	}
	rep(i, n){
		g[p[i].x][p[i].y]++;
		g[p[i].x1][p[i].y]--;
		g[p[i].x][p[i].y1]--;
		g[p[i].x1][p[i].y1]++;
	}
	repn(i, 1, 1005) rep(j, 1005) g[i][j] = g[i - 1][j] + g[i][j];
	rep(i, 1005) repn(j, 1, 1005) g[i][j] = g[i][j] + g[i][j - 1];
	int cnt = 0;
	rep(i, 1005) rep(j, 1005) if(g[i][j] == k) cnt++;
	cout << cnt << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
