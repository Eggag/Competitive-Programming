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

bool intersect(int a, int b, int c, int d){
	return ((a >= c && a <= d) || (b >= c && b <= d) || (c >= a && c <= b) || (d >= a && d <= b));
}

void solve(){
	int n, m;
	cin >> n >> m;
	vi t(n), l(n), h(n);
	rep(i, n) cin >> t[i] >> l[i] >> h[i];
	int le = m, ri = m;
	rep(i, n){
		int mx1 = le + (t[i] - (!i ? 0 : t[i - 1]));
		int mn1 = le - (t[i] - (!i ? 0 : t[i - 1]));
		int mx2 = ri + (t[i] - (!i ? 0 : t[i - 1]));
		int mn2 = ri - (t[i] - (!i ? 0 : t[i - 1]));
		/*
		debug(i);
		debug2(mx1, mn1);
		debug2(mx2, mn2);
		debug2(le, ri);
		debug2(l[i], h[i]);
		debug2(mn2, mx1);
		*/
		if(!intersect(l[i], h[i], mn2, mx1)){
			cout << "NO" << endl;
			return;
		}
		int mn = min({mx1, mx2, mn1, mn2});
		int mx = max({mx1, mx2, mn1, mn2});
		int hi = mx;
		if(hi > h[i]){
			hi = h[i];
		}
		int lw = mn;
		if(lw < l[i]){
			lw = l[i];
		}
		le = hi, ri = lw;
		/*
		debug2(le, ri);
		cout << "---" << endl;
		*/
	}
	cout << "YES" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q;
	while(q--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
