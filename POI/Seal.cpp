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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m, a, b;
string s[mxN], t[mxN];
int vis[mxN][mxN];

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

void solve(){
	cin >> n >> m >> a >> b;
	rep(i, n) cin >> s[i];
	rep(i, a) cin >> t[i];
	vector<pi> ch;
	pi fr = {-1, -1};
	memset(vis, 0, sizeof(vis));
	rep(i, a) rep(j, b) if(t[i][j] == 'x'){
		if(fr.fi == -1) fr = {i, j};
		else ch.pb({i - fr.fi, j - fr.se});
	}
	rep(i, n) rep(j, m) if(s[i][j] == 'x' && !vis[i][j]){
		vis[i][j] = 1;
		rep(k, ch.size()){
			int x = i + ch[k].fi, y = j + ch[k].se;
			if(valid(x, y)){
				if(vis[x][y] || s[x][y] == '.'){
					cout << "NIE" << endl;
					return;
				}
				vis[x][y] = 1;
			}
			else{
				cout << "NIE" << endl;
				return;
			}
		}
	}
	rep(i, n) rep(j, m) if(s[i][j] == 'x' && !vis[i][j]){
		cout << "NIE" << endl;
		return;
	}
	cout << "TAK" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
