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

int sum[105];
int a[105][105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	memset(sum, 0, sizeof(sum));
	rep(i, m) rep(j, n) cin >> a[i][j], sum[j] += a[i][j];
	int ans = m;
	vi best;
	rep(i, m) best.pb(i);
	rep(i, n - 1){
		if(sum[i] >= sum[n - 1]){
			cout << 0 << endl;
			return 0;
		}
		int d = sum[n - 1] - sum[i];
		vector<pi> pos;
		rep(j, m){
			pos.pb({a[j][i] - a[j][n - 1], j});
		}
		sort(all(pos));
		vi cur;
		int cnt = 0;
		rep(j, m){
			if(d <= 0) break;
			cnt++;
			cur.pb(pos[j].se);
			d += pos[j].fi;
		}
		if(cnt < ans){
			best = cur;
			ans = cnt;
		}
	}
	cout << ans << endl;
	rep(i, best.size()) cout << best[i] + 1 << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
