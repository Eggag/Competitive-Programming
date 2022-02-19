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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(array<int, 3> a, array<int, 3> b){
	return a[0] < b[0];
}

bool cmp1(array<int, 3> a, array<int, 3> b){
	return a[1] < b[1];
}

void solve(){
	int n;
	cin >> n;
	vi ans(n, 0);
	vector<array<int, 3>> p(n);
	rep(i, n) cin >> p[i][0];
	rep(i, n) cin >> p[i][1], p[i][2] = i;
	sort(all(p), cmp);
	vi ps(n + 1, 0);
	ps[n - 1] = p[n - 1][1];
	int mn = p[n - 1][1];
	for(int i = n - 2; i >= 0; i--){
		mn = min(mn, p[i][1]);
		ps[i] = ps[i + 1];
		if(p[i][1] > ps[i + 1]) ps[i] = mn;
	}
	int mx = 0;
	rep(i, n){
		mx = max(mx, p[i][1]);
		if(mx > ps[i + 1]) ans[p[i][2]] = 1;
	}
	sort(all(p), cmp1);
	vi ps1(n + 1, 0);
	ps1[n - 1] = p[n - 1][0];
	mn = p[n - 1][1];
	for(int i = n - 2; i >= 0; i--){
		mn = min(mn, p[i][0]);
		ps1[i] = ps1[i + 1];
		if(p[i][0] > ps1[i + 1]) ps1[i] = mn;
	}
	mx = 0;
	rep(i, n){
		mx = max(mx, p[i][0]);
		if(mx > ps1[i + 1]) ans[p[i][2]] = 1;
	}
	rep(i, n) cout << ans[i];
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
