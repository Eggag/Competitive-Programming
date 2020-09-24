#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
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
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
char g[1005][1005];
int v[1005][1005];
int pwn[1005][1005];

bool valid(int p){
	return ((p >= 0) && (p < n));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	int p = 0;
	memset(v, 0, sizeof(v));
	memset(pwn, 0, sizeof(pwn));
	vector<pi> pw;
	pi kn = {-1, -1};
	rep(i, n) rep(j, n){
		cin >> g[i][j];
		if(g[i][j] == '*') p++, pwn[i][j] = 1, pw.pb(mp(i, j));
		if(g[i][j] == 'K') kn = mp(i, j);
	}
	if(kn.fi != -1){
		for(int k = 0; k < 8; k++){
			int x = kn.fi + dx[k];
			int y = kn.se + dy[k];
			if(valid(x) && valid(y)){
				if(g[x][y] == '*'){
					p--;
					v[x][y] = 1;
				}
			}
		}
	}
	rep(i, pw.size()){
		int f = 1;
		if(valid(pw[i].fi + 1) && valid(pw[i].se + 1) && g[pw[i].fi + 1][pw[i].se + 1] == '-') f = 0;
		if(valid(pw[i].fi + 1) && valid(pw[i].se - 1) && g[pw[i].fi + 1][pw[i].se - 1] == '-') f = 0;
		if(f){
			cout << -1 << endl;
			return 0;
		}
	}
	rep(k, pw.size()){
		int i = pw[k].fi, j = pw[k].se;
		if(pwn[i][j] && !v[i][j]){
			if(pwn[i][j + 2] && !v[i][j + 2] && valid(i + 1) && valid(j + 1) && !v[i + 1][j + 1] && g[i + 1][j + 1] == '-'){
				v[i][j] = 1, v[i][j + 2] = 1, v[i + 1][j + 1] = 1;
				p--;
			}
		}
	}
	cout << p << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
