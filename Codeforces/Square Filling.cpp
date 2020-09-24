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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int g[55][55];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];
	set<pi> ans;
	rep(i, n) rep(j, m){
		if(g[i][j]){
			int f = 1;
			if((i > 0) && g[i - 1][j] && (j < (m - 1)) && g[i - 1][j + 1] && g[i][j + 1]){
				f = 0;
				ans.insert(mp(i - 1, j));
			}
			if((i < (n - 1)) && g[i + 1][j] && (j < (m - 1)) && g[i + 1][j + 1] && g[i][j + 1]){
				f = 0;
				ans.insert(mp(i, j));
			}
			if((i > 0) && g[i - 1][j] && (j > 0) && g[i - 1][j - 1] && g[i][j - 1]){
				f = 0;
				ans.insert(mp(i - 1, j - 1));
			}
			if((i < (n - 1)) && g[i + 1][j] && (j > 0) && g[i + 1][j - 1] && g[i][j - 1]){
				f = 0;
				ans.insert(mp(i, j - 1));
			}
			if(f){
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	for(auto x : ans){
		cout << (x.fi + 1) << " " << (x.se + 1) << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
