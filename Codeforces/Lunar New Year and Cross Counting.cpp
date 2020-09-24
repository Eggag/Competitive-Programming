#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cout << #x << ": " << x << endl
#define repn(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) for(int i = 0; i < (a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl '\n'

char g[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> g[i][j];
	int ans = 0;
	repn(i, 1, n - 1) repn(j, 1, n - 1){
		int f = 1;
		if(g[i][j] != 'X') f = 0;
		if(g[i + 1][j - 1] != 'X') f = 0;
		if(g[i + 1][j + 1] != 'X') f = 0;
		if(g[i - 1][j - 1] != 'X') f = 0;
		if(g[i - 1][j + 1] != 'X') f = 0;
		if(f) ans++;
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
