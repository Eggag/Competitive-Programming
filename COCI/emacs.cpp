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
string s[105];
int v[105][105];

void dfs(int x, int y){
	if(v[x][y]) return;
	v[x][y] = 1;
	if((x + 1) < n && s[x + 1][y] == '*') dfs(x + 1, y);
	if((y + 1) < m && s[x][y + 1] == '*') dfs(x, y + 1);
	if((x - 1) >= 0 && s[x - 1][y] == '*') dfs(x - 1, y);
	if((y - 1) >= 0 && s[x][y - 1] == '*') dfs(x, y - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> s[i];
	memset(v, 0, sizeof(v));
	int comp = 0;
	rep(i, n) rep(j, m) if(s[i][j] == '*' && !v[i][j]){
		comp++;
		dfs(i, j);
	}
	cout << comp << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
