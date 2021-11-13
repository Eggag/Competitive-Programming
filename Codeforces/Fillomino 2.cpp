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
const int mxN = 505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int ans[mxN][mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi p(n);
	rep(i, n) cin >> p[i];
	memset(ans, -1, sizeof(ans));
	int f = 1;
	rep(i, n){
		pi pos = {i, i};
		int cr = p[i];
		while(cr--){
			ans[pos.fi][pos.se] = p[i];
			if(cr){
				if(pos.se > 0 && ans[pos.fi][pos.se - 1] == -1) pos.se--;
				else if(pos.fi < (n - 1) && ans[pos.fi + 1][pos.se] == -1) pos.fi++;
				else f = 0;
			}
		}
	}
	if(!f){
		cout << -1 << '\n';
		return 0;
	}
	rep(i, n){
		rep(j, i + 1) cout << ans[i][j] << " ";
		cout << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
