#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
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
	vi ar(n);
	rep(i, n) cin >> ar[i];
	vi cnt(100005, 0), cnt1(100005, 0);
	for(int i = 0; i < n; i += 2) cnt[ar[i]]++;
	for(int i = 1; i < n; i += 2) cnt1[ar[i]]++;
	vector<pi> a;
	rep(i, 100005) a.pb({cnt[i], i});
	sort(all(a));
	reverse(all(a));
	vector<pi> b;
	rep(i, 100005) b.pb({cnt1[i], i});
	sort(all(b));
	reverse(all(b));
	int ans = n - b[0].fi - a[0].fi;
	if(a[0].se != b[0].se) cout << ans << endl;
	else{
		int ans = n - a[0].fi;
		if(b.size() > 1) ans -= b[1].fi;
		int ans1 = n - b[0].fi;
		if(a.size() > 1) ans1 -= a[1].fi;
		cout << min(ans, ans1) << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
