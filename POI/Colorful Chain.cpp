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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int req[mxN], cnt[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vi c(m), l(m);
	rep(i, m) cin >> l[i];
	ll tot = 0;
	rep(i, m){
		cin >> c[i];
		req[c[i]] = l[i];
		tot += l[i];
	}
	if(tot > n){
		cout << 0 << endl;
		return 0;
	}
	vi a(n);
	rep(i, n) cin >> a[i];
	int nm = 0, ans = 0;
	rep(i, tot){
		cnt[a[i]]++;
		if(cnt[a[i]] == (req[a[i]] + 1)) nm--;
		if(cnt[a[i]] == req[a[i]]) nm++;
		if(nm == m) ans++;
	}
	repn(i, tot, n){
		cnt[a[i]]++;
		if(cnt[a[i]] == (req[a[i]] + 1)) nm--;
		if(cnt[a[i]] == req[a[i]]) nm++;
		cnt[a[i - tot]]--;
		if(cnt[a[i - tot]] == (req[a[i - tot]] - 1)) nm--;
		if(cnt[a[i - tot]] == req[a[i - tot]]) nm++;
		if(nm == m) ans++;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
