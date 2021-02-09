#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi cnt[mxN];

void solve(){
	int n, m;
	cin >> n >> m;
	vi a(n), b(n), c(m);
	vi cr(n + 1, 0), wr(n + 1, 0);
	rep(i, n + 1) cnt[i].clear();
	rep(i, n) cin >> a[i];
	rep(i, n){
		cin >> b[i];
		if(b[i] != a[i]) wr[b[i]]++;
	}
	rep(i, m) cin >> c[i], cnt[c[i]].pb(i);
	int ind = -1;
	rep(i, n) if(b[i] == c[m - 1]) ind = i;
	if(wr[c[m - 1]]) rep(i, n) if(b[i] == c[m - 1] && a[i] != b[i]) ind = i;
	if(ind == -1){
		cout << "NO" << '\n';
		return;
	}	
	int num = 0;
	vi ans(m, ind);
	rep(i, n) if(a[i] != b[i]){
		if(cr[b[i]] == cnt[b[i]].size()){
			cout << "NO" << '\n';
			return;
		}
		ans[cnt[b[i]][cr[b[i]]]] = i;
		cr[b[i]]++;
		num++;
	}
	if(num > m && ans[m - 1] != ind){
		cout << "NO" << '\n';
		return;
	}
	cout << "YES" << '\n';
	rep(i, m) cout << ans[i] + 1 << " ";
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
