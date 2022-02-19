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

struct point{
	ll x, y;
};

int ccw(point a, point b, point c){
	ll cur = ((c.y - a.y) * (b.x - a.x)) - ((b.y - a.y) * (c.x - a.x));
	if(cur > 0) return 1;
	else if(cur == 0) return 0;
	else return -1;
}

int inside(point p, vector<point> t){
	vi s(3);
	rep(i, 3){
		s[i] = ccw(p, t[(i + 1) % 3], t[i]);
		if(!s[i]) return 1;
	}
	if(s[0] == s[1] && s[1] == s[2]) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	vector<vector<point>> p(n);
	rep(i, n){
		rep(j, 3){
			ll x, y;
			cin >> x >> y;
			point p1 = {x, y};
			p[i].pb(p1);
		}
	}
	rep(i, q){
		int ans = 0;
		ll x, y;
		cin >> x >> y;
		point p1 = {x, y};
		rep(j, n){
			if(inside(p1, p[j])) ans++;
		}
		cout << ans << '\n';
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
