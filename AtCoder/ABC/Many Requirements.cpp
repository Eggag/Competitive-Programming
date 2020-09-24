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

int n, m, q;
int a[150], b[150], c[150], d[150];
int ans = 0;

void dfs(int it, vi cur, int lft){
	if(it == n){
		//check the score
		int sc = 0;
		rep(i, q){
			//check the score
			int sm = 0;
			repn(j, a[i] - 1, b[i] - 1) sm += cur[j];
			if(sm == c[i]) sc += d[i];
		}
		ans = max(ans, sc);
		return;
	}
	//put here the difference
	rep(i, lft + 1){
		vi cur1 = cur;
		cur1.pb(i);
		dfs(it + 1, cur1, lft - i);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m >> q;
	rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];
	vi emp;
	dfs(0, emp, m - 1);
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
