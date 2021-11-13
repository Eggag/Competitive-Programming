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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n; ll k;
	cin >> n >> k;
	vector<ll> a(n);
	ll mn = 1e9, mx = 0;
	rep(i, n) cin >> a[i], mn = min(mn, a[i]), mx = max(mx, a[i]);
	ll cnt1 = 0;
	rep(i, n) cnt1 += mx - a[i];
	if(cnt1 <= k){
		cout << mx + (k - cnt1) / n << '\n';
		return 0;
	}
	ll ans = 1;
	sort(all(a));
	vector<ll> cnt(n);
	cnt[0] = a[0];
	repn(i, 1, n) cnt[i] = cnt[i - 1] + a[i];
	repn(i, 2, mx){
		ll nd = 0;
		rep(j, n){
			ll cr = ((a[j] + i - 1) / i) * i;
			int l = j, r = n - 1;
			while(l < r){
				int mid = (l + r + 1) / 2;
				if(a[mid] <= cr) l = mid;
				else r = mid - 1;
			}
			ll sm = cnt[l] - (j ? cnt[j - 1] : 0);
			nd += (1LL * cr * (ll)(l - j + 1)) - sm;
			j = l;
		}
		if(nd <= k) ans = i;
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
