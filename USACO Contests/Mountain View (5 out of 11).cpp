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
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int n;
	cin >> n;
	vi x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	//find the bases
	vector<pi> base1(n);
	rep(i, n){
		base1[i].fi = x[i] - y[i];
		base1[i].se = x[i] + y[i];
	}
	vector<pi> base;
	set<pi> st;
	rep(i, n) st.insert(mp(base1[i].fi, base1[i].se));
	for(auto x : st) base.pb(mp(x.fi, x.se));
	vi pos((int)(base.size()), 1);
	rep(i, base.size()) repn(j, i + 1, base.size()){
		//check if i is obscured by j
		if(base[j].fi <= base[i].fi && base[i].se <= base[j].se) pos[i] = 0;
		//and the other way around
		if(base[i].fi <= base[j].fi && base[j].se <= base[i].se) pos[j] = 0;
	}
	int ans = 0;
	rep(i, base.size()) ans += pos[i];
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
