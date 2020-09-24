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

vector<pi> g[35];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, gr;
	cin >> n >> gr;
	rep(i, n){
		//for each c do like
		int a, b, c;
		cin >> a >> b >> c;
		g[c].pb(mp(a, b));
	}
	vi cnt1(100005, 0);
	repn(i, 1, gr + 1){
		vi cnt(100005, 0);
		rep(j, g[i].size()){
			cnt[g[i][j].fi]++;
			cnt[g[i][j].se + 1]--;
		}
		partial_sum(all(cnt), cnt.begin());
		rep(j, 100005) cnt1[j] += min(1, cnt[j]);
	}
	int ans = 0;
	rep(i, 100005) ans = max(ans, cnt1[i]);
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
