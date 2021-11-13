#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void no(){
	cout << "NO\n";
	exit(0);
}

void solve(int n, int m){
	int rot = 0;
	int cnt = 1;
	vector<vi> g1(n);
	rep(i, n) g1[i].resize(m);
	rep(i, n) rep(j, m) g1[i][j] = cnt++;
	if(m < 4){
		vector<vi> g3(m);
		rep(i, m) g3[i].resize(n);
		rep(i, n) rep(j, m) g3[m - 1 - j][i] = g1[i][j];
		g1 = g3;
		swap(n, m), rot = 1;
	}
	vector<vi> g(n);
	if(m == 4){
		rep(i, n){
			if(i % 2 == 0){
				g[i].pb(g1[i][2]);
				g[i].pb(g1[i][0]);
				g[i].pb(g1[i][3]);
				g[i].pb(g1[i][1]);
			}
			else{
				g[i].pb(g1[i][1]);
				g[i].pb(g1[i][3]);
				g[i].pb(g1[i][0]);
				g[i].pb(g1[i][2]);
			}
		}
	}
	else{
		rep(i, n){
			if(i % 2 == 0){
				rep(j, m) if(j % 2 == 0) g[i].pb(g1[i][j]);
				rep(j, m) if(j & 1) g[i].pb(g1[i][j]);
			}
			else{
				rep(j, m) if(j & 1) g[i].pb(g1[i][j]);
				rep(j, m) if(j % 2 == 0) g[i].pb(g1[i][j]);
			}
		}
	}
	if(rot){
		vector<vi> g2(m);
		rep(i, m) g2[i].resize(n);
		rep(i, n) rep(j, m) g2[j][n - i - 1] = g[i][j];
		g = g2;
		swap(n, m);
	}
	cout << "YES\n";
	rep(i, n){
		rep(j, m) cout << g[i][j] << " ";
		cout << '\n';
	}
}

void solve1(int n, int m){
	if(n == 3 && m == 3){
		cout << "YES\n";
		cout << "1 5 9\n";
		cout << "7 3 4\n";
		cout << "2 8 6\n";
	}
	else no();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if(n == 1 && m == 1){
		cout << "YES\n";
		cout << "1\n";
		return 0;
	}
	if(max(n, m) >= 4) solve(n, m);
	else solve1(n, m);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
