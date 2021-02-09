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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, logn;
int a[mxN], mn[22][mxN], maxQ[mxN];
vi m[mxN];

int minQ(int l, int r) { // [l; r)
	int t = __lg(r - l);
	return min(mn[t][l], mn[t][r - (1 << t)]);
}

void solve(){
	cin >> n;
	vi a(n), b(n);
	rep(i, n + 2) m[i].clear();
	unordered_map<int, int> cnt;
	int ind = 1;
	rep(i, n) cin >> a[i], b[i] = a[i];
	sort(all(b));
	rep(i, n) if(!cnt[b[i]]) cnt[b[i]] = ind++;
	rep(i, n) a[i] = cnt[a[i]];
	rep(i, n) m[a[i]].pb(i);
	logn = (int)(__lg(n)) + 1;
	rep(i, n) mn[0][i] = a[i];
	maxQ[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--) maxQ[i] = max(maxQ[i + 1], a[i]);
	for(int l = 0; l < logn - 1; l++){
		for(int i = 0; i + (2 << l) <= n; i++){
			mn[l + 1][i] = min(mn[l][i], mn[l][i + (1 << l)]);
		}
	}
	int mx1 = 0;
	rep(i, n - 2){
		//[0, i] is the max prefix
		mx1 = max(mx1, a[i]);
		if(m[mx1].size() < 3 || m[mx1][(int)(m[mx1].size()) - 2] <= i) continue;
		int nxt = *lb(all(m[mx1]), i + 1), lst = m[mx1][(int)(m[mx1].size()) - 1];
		if(minQ(i + 1, nxt + 1) != mx1) continue;
		if(maxQ[lst] != mx1) continue;
		int l = nxt, r = lst - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(minQ(i + 1, mid + 1) == mx1) l = mid;
			else r = mid - 1;
		}
		if(minQ(i + 1, l + 1) == mx1 && maxQ[l + 1] == mx1){
			cout << "YES" << '\n';
			cout << i + 1 << " " << l - i << " " << n - ((i + 1) + (l - i)) << '\n';
			return;
		}
	}
	cout << "NO" << '\n';
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
