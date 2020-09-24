#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

int gcd(int a, int b){ return ((b == 0) ? a : gcd(b, a % b)); }

int e[4005][4005];
int deg[4005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, 4005) rep(j, 4005) e[i][j] = 0;
	rep(i, 4005) deg[i] = 0;
	rep(i, m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		e[a][b] = 1, e[b][a] = 1;
		deg[a]++, deg[b]++;
	}
	int mn = 1e9;
	rep(i, n) repn(j, i + 1, n) repn(k, j + 1, n) if(e[i][j] && e[j][k] && e[i][k]){
		int sum = deg[i] + deg[j] + deg[k] - 6;
		mn = min(sum, mn);
	}
	cout << ((mn == 1e9) ? -1 : mn) << endl; 
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
