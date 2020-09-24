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
const int mxN = 3005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int l[mxN], r[mxN];

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i], l[a[i]] = 0, r[a[i]] = 0;
	ll ret = 0LL;
	rep(i, n){
		//now we go back, keeping track of all the numbers, right
		ll ans = 0LL;
		ll tot = 0LL;
		l[a[i]]++;
		for(int j = i; j >= 0; j--){
			if(a[j] == a[i]) ans += tot;
			ll nw = (l[a[j]] - (a[j] == a[i])) * (r[a[j]] - (a[i] == a[j]));
			if(l[a[j]] - (a[j] == a[i]) > 0 && r[a[j]] - (a[i] == a[j]) > 0) tot -= nw;
			l[a[j]]--, r[a[j]]++;
			nw = (l[a[j]] - (a[i] == a[j])) * (r[a[j]] - (a[j] == a[i]));
			if(l[a[j]] - (a[j] == a[i]) > 0 && r[a[j]] - (a[i] == a[j]) > 0) tot += nw;
		}
		ret += ans;
		rep(j, i + 1) l[a[j]] = 0, r[a[j]] = 0;
		rep(j, i + 1) l[a[j]]++;
	}
	cout << ret << endl;
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
