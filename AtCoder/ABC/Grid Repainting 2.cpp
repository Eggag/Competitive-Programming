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

int num = 0;
int vis[55][55];
int h, w;
string s[55];

void dfs(int x, int y){
	if(vis[x][y]) return;
	vis[x][y] = 1;
	num++;
	if((x + 1) < h && s[x + 1][y] == '#') dfs(x + 1, y);
	if((y + 1) < w && s[x][y + 1] == '#') dfs(x, y + 1);
	if((x - 1) >= 0 && s[x - 1][y] == '#') dfs(x - 1, y);
	if((y - 1) >= 0 && s[x][y - 1] == '#') dfs(x, y - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> h >> w;
	int cnt = 0;
	rep(i, h) cin >> s[i];
	rep(i, h) rep(j, w) cnt += (s[i][j] == '#');
	int tot = 0;
	rep(i, h) rep(j, w) if(s[i][j] == '#' && !vis[i][j]){
		dfs(i, j);
		if(num > 1) tot += num;
		else{
			cout << "No" << endl;
			return 0;
		}
		num = 0;
	}
	cout << "Yes" << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
