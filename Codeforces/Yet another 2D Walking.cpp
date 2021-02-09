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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

bool cmp(pi a, pi b){
	return max(a.fi, a.se) < max(b.fi, b.se);
}

bool mnL(pi a, pi b){
	if(a.fi < b.fi) return 1;
	return a.se > b.se;
}

bool mxR(pi a, pi b){
	if(a.fi > b.fi) return 1;
	return a.se < b.se;
}

ll dist(pi a, pi b){
	return 1LL * (abs(a.fi - b.fi) + abs(a.se - b.se));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p), cmp);
	pi le = {0, 0}, ri = {0, 0};
	ll l = 0LL, r = 0LL;
	rep(i, n){
		int a = i;
		pi lef = {-1, -1}, rig = {-1, -1};
		while(i < n && max(p[i].fi, p[i].se) == max(p[a].fi, p[a].se)){
			if(lef.fi == -1 || mnL(p[i], lef)) lef = p[i];
			if(rig.fi == -1 || mxR(p[i], rig)) rig = p[i];
			i++;
		}
		i--;
		ll l1 = l, r1 = r;
		r1 = min(l + dist(lef, le), r + dist(lef, ri)) + dist(lef, rig);
		l1 = min(l + dist(rig, le), r + dist(rig, ri)) + dist(lef, rig);
		le = lef, ri = rig;
		l = l1, r = r1;
	}
	cout << min(l, r) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
