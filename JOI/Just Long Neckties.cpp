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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> a(n + 1);
	vi b(n);
	rep(i, n + 1) cin >> a[i].fi, a[i].se = i;
	rep(i, n) cin >> b[i];
	sort(all(b));
	sort(all(a));
	vi l(n + 1, 0);
	rep(i, n){
		if(!i) l[i] = max(0, a[i].fi - b[i]);
		else l[i] = max(l[i - 1], max(0, a[i].fi - b[i]));
	}
	vi r(n + 1, 0);
	for(int i = n - 1; i >= 0; i--){
		if(i == (n - 1)) r[i] = max(0, a[i + 1].fi - b[i]);
		else r[i] = max(r[i + 1], max(0, a[i + 1].fi - b[i]));
	}
	vi ans(n + 1);
	rep(i, n + 1){
		int j = a[i].se;
		if(i == n) ans[j] = l[n - 1];
		else ans[j] = max((!i ? 0 : l[i - 1]), r[i]);
	}
	rep(i, n + 1) cout << ans[i] << " ";
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
