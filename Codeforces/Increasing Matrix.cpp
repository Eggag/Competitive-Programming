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

int g[505][505];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) cin >> g[i][j], sum += g[i][j];
	rep(i, n) rep(j, m) if(!g[i][j]){
		g[i][j] = min(g[i - 1][j], g[i][j - 1]) - 1;
		sum += g[i][j];
	}
	rep(i, n){
		repn(j, 1, m){
			if(g[i][j] >= g[i][j - 1]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	rep(j, m) repn(i, 1, n){
		if(g[i][j] >= g[i - 1][j]){
			cout << -1 << endl;
			return 0;
		}
	}
	cout << sum << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
