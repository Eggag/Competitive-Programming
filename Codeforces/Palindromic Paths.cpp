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

pi ind[1005];
int vis[35][35], a[35][35], val[35][35];

void solve(){
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j], vis[i][j] = 0, val[i][j] = 0;
	queue<pair<pi, int>> q;
	q.push(mp(mp(0, 0), 1));
	vis[0][0] = 1;
	val[0][0] = 1;
	while(!q.empty()){
		pair<pi, int> cur = q.front();
		q.pop();
		int x = cur.fi.fi, y = cur.fi.se;
		if(x < (n - 1) && !vis[x + 1][y]){
			vis[x + 1][y] = 1;
			val[x + 1][y] = cur.se + 1;
			q.push(mp(mp(x + 1, y), cur.se + 1));
		}
		if(y < (m - 1) && !vis[x][y + 1]){
			vis[x][y + 1] = 1;
			val[x][y + 1] = cur.se + 1;
			q.push(mp(mp(x, y + 1), cur.se + 1));
		}
	}
	rep(i, n) rep(j, m) vis[i][j] = 0;
	q.push(mp(mp(n - 1, m - 1), 1));
	vis[n - 1][m - 1] = 1;
	val[n - 1][m - 1] = 1;
	int mx = 0;
	while(!q.empty()){
		pair<pi, int> cur = q.front();
		q.pop();
		int x = cur.fi.fi, y = cur.fi.se;
		mx = max(mx, val[x][y]);
		if(x > 0 && !vis[x - 1][y]){
			vis[x - 1][y] = 1;
			val[x - 1][y] = min(val[x - 1][y], cur.se + 1);
			q.push(mp(mp(x - 1, y), cur.se + 1));
		}
		if(y > 0 && !vis[x][y - 1]){
			vis[x][y - 1] = 1;
			val[x][y - 1] = min(val[x][y - 1], cur.se + 1);
			q.push(mp(mp(x, y - 1), cur.se + 1));
		}
	}
	rep(i, n * m) ind[i] = {0, 0};
	rep(i, n) rep(j, m){
		if(a[i][j]) ind[val[i][j]].fi++;
		else ind[val[i][j]].se++;
	}
	int ans = 0;
	rep(i, n * m) if(!(i == mx && (m & 1) == (n & 1))) ans += min(ind[i].fi, ind[i].se);
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
