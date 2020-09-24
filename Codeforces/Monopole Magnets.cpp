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

int n, m;
string s[1005];
int v[1005][1005];

void dfs(int x, int y){
	if(v[x][y]) return;
	v[x][y] = 1;
	if((x + 1) < n && s[x + 1][y] == '#') dfs(x + 1, y);
	if((y + 1) < m && s[x][y + 1] == '#') dfs(x, y + 1);
	if((x - 1) >= 0 && s[x - 1][y] == '#') dfs(x - 1, y);
	if((y - 1) >= 0 && s[x][y - 1] == '#') dfs(x, y - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	int ans = 0;
	rep(i, n) rep(j, m) if(s[i][j] == '#' && !v[i][j]){
		ans++;
		dfs(i, j);
	}
	rep(i, n){
		int v = 0;
		rep(j, m){
			if(!v && s[i][j] == '#') v++;
			if(v == 1 && s[i][j] == '.') v++;
			if(v == 2 && s[i][j] == '#'){
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	rep(j, m){
		int v = 0;
		rep(i, n){
			if(!v && s[i][j] == '#') v++;
			if(v == 1 && s[i][j] == '.') v++;
			if(v == 2 && s[i][j] == '#'){
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	int lst = -1;
	rep(i, n){
		int cur = 0;
		rep(j, m) cur += (s[i][j] == '#');
		if(cur == 0 && lst == m){
			cout << "-1" << endl;
			return 0;
		}
		if(cur == m && lst == 0){
			cout << "-1" << endl;
			return 0;
		}
		lst = cur;
	}
	rep(j, m){
		int cur = 0;
		rep(i, n) cur += (s[i][j] == '#');
		if(cur == 0 && lst == n){
			cout << "-1" << endl;
			return 0;
		}
		if(cur == n && lst == 0){
			cout << "-1" << endl;
			return 0;
		}
		lst = cur;
	}
	vi sc(m, 0);
	rep(j, m) rep(i, n) sc[j] += (s[i][j] == '#');
	vi sc1(n, 0);
	rep(i, n) rep(j, m) sc1[i] += (s[i][j] == '#');
	rep(i, n){
		int b = 0;
		int cnt = 0;
		rep(j, m){
			if(!sc[j]) b = 1;
			cnt += (s[i][j] == '#');
		}
		if(!b && !cnt){
			cout << "-1" << endl;
			return 0;
		}
	}
	rep(j, m){
		int b = 0;
		int cnt = 0;
		rep(i, n){
			if(!sc1[i]) b = 1;
			cnt += (s[i][j] == '#');
		}
		if(!b && !cnt){
			cout << "-1" << endl;
			return 0;
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
