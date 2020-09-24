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

int cnt[105], val[105];

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i], cnt[i] = 0, val[i] = 0;
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	if((int)a.size() > k){
		cout << -1 << endl;
		return;
	}
	vi ans(1e4, 0);
	rep(i, 1e4){
		if(!val[i % k]){
			if(i < a.size()) val[i % k] = a[i];
			else val[i % k] = 1;
		}
		ans[i] = val[i % k];
	}
	cout << 1e4 << endl;
	rep(i, 1e4) cout << ans[i] << " ";
	cout << endl;
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
	- Array bounds
	- Special cases
Be careful!
*/
