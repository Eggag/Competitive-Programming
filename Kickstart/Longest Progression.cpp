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

void solve(){
	int n;
	cin >> n;
	vi a(n), b;
	rep(i, n) cin >> a[i];
	repn(i, 1, n) b.pb(a[i] - a[i - 1]);
	int nm = 1, mx = 1;
	vector<pi> cnt;
	repn(i, 1, n - 1){
		if(b[i] == b[i - 1]) nm++;
		else{
			cnt.pb(mp(b[i - 1], nm));
			mx = max(mx, nm + 1), nm = 1;
		}
	}
	mx = max(mx, nm + (nm != (n - 1)));
	mx++;
	cnt.pb(mp(b[n - 2], nm));
	rep(i, (int)(cnt.size()) - 3){
		if(cnt[i].fi == cnt[i + 3].fi){
			if(cnt[i + 1].fi + cnt[i + 2].fi == cnt[i].fi * 2){
				mx = max(mx, cnt[i].se + cnt[i + 3].se + 3);
			}
		}
	}
	rep(i, (int)(cnt.size()) - 2){
		if(cnt[i + 1].fi + cnt[i + 2].fi == cnt[i].fi * 2){
			mx = max(mx, cnt[i].se + 3);
		}
	}
	repn(i, 2, cnt.size()){
		if(cnt[i - 1].fi + cnt[i - 2].fi == cnt[i].fi * 2){
			mx = max(mx, cnt[i].se + 3);
		}
	}
	cout << mx << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
