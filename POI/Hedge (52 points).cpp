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
string s[1005], s1[1005];
int cc = 0;
int vis[1005][1005];

void dfs(int i, int j){
	if(vis[i][j]) return;
	vis[i][j] = 1;
	if((i + 1) < n && s1[i][j] != 'C') dfs(i + 1, j);
	if((j + 1) < m && s[i][j] != 'C') dfs(i, j + 1);
	if(i > 0 && s1[i - 1][j] != 'C') dfs(i - 1, j);
	if(j > 0 && s[i][j - 1] != 'C') dfs(i, j - 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	int c = 0;
	rep(i, n) cin >> s[i];
	rep(i, n) rep(j, m - 1) c += (s[i][j] == 'C');
	rep(i, n - 1) cin >> s1[i];
	rep(i, n - 1) rep(j, m) c += (s1[i][j] == 'C');
	//(1, 0) to (1, 1) we check that s[1][0] is a C
	//(1, 1) to (2, 1) we check s[1][1] is a C
	rep(i, n) rep(j, m) if(!vis[i][j]){
		cc++;
		dfs(i, j);
	}
	int req = (m - 1) * (n - 1);
	cout << req << " " << c - (cc - 1) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
