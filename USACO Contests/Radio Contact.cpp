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

int dp[1005][1005];
pi p[1005], p1[1005];

int dist(pi a, pi b){
	return sq(a.fi - b.fi) + sq(a.se - b.se);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int fx, fy;
	cin >> fx >> fy;
	int bx, by;
	cin >> bx >> by;
	string a, b;
	cin >> a >> b;
	rep(i, 1005) rep(j, 1005) dp[i][j] = 1e9;
	dp[0][0] = 0;
	pi cur = {fx, fy};
	p[0] = {fx, fy};
	repn(i, 1, n + 1){
		char c = a[i - 1];
		if(c == 'N') cur.se++;
		if(c == 'S') cur.se--;
		if(c == 'W') cur.fi--;
		if(c == 'E') cur.fi++;
		p[i] = cur;
	}
	cur = {bx, by};
	p1[0] = {bx, by};
	repn(i, 1, m + 1){
		char c = b[i - 1];
		if(c == 'N') cur.se++;
		if(c == 'S') cur.se--;
		if(c == 'W') cur.fi--;
		if(c == 'E') cur.fi++;
		p1[i] = cur;
	}
	rep(i, n + 1){
		rep(j, m + 1){
			if(!i && !j) continue;
			if(i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (dist(p[i], p1[j])));
			if(j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (dist(p[i], p1[j])));
			if(i && j) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (dist(p[i], p1[j])));
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
