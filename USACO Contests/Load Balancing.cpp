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

bool cmp(pi a, pi b){
	return a.se < b.se;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].fi >> p[i].se;
	sort(all(p));
	vi vert;
	rep(i, n){
		if(!i || p[i].fi != p[i - 1].fi) vert.pb(p[i].fi + 1);
	}
	sort(all(p), cmp);
	vi hor;
	rep(i, n){
		if(!i || p[i].se != p[i - 1].se) hor.pb(p[i].se + 1);
	}
	int ans = 1e9;
	for(int i = max(0, (int)(vert.size() / 2) - 200); i < min((int)vert.size(), (int)(vert.size() / 2) + 200); i++){
		for(int j = max(0, (int)(hor.size() / 2) - 200); j < min((int)hor.size(), (int)(hor.size() / 2) + 200); j++){
			int one = 0, two = 0, three = 0, four = 0;
			rep(k, n){
				if(p[k].fi < vert[i] && p[k].se > hor[j]) one++;
				else if(p[k].fi < vert[i] && p[k].se < hor[j]) two++;
				else if(p[k].fi > vert[i] && p[k].se < hor[j]) three++;
				else four++;
			}
			ans = min(ans, max({one, two, three, four}));
		}
	}
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
