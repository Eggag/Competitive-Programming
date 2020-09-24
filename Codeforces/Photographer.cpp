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

ll n, d, a, b;

bool cmp(pair<pair<ll, ll>, int> c, pair<pair<ll, ll>, int> d){
	return (c.fi.fi * a + c.fi.se * b) < (d.fi.fi * a + d.fi.se * b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> d;
	cin >> a >> b;
	vector<pair<pair<ll, ll>, int>> p(n);
	rep(i, n) cin >> p[i].fi.fi >> p[i].fi.se, p[i].se = i;
	sort(all(p), cmp);
	ll cur = 0;
	vi ans;
	rep(i, n){
		cur += p[i].fi.fi * a + p[i].fi.se * b;
		if(cur > d){
			cout << ans.size() << endl;
			for(int x : ans) cout << x + 1 << " ";
			cout << endl;
			return 0;
		}
		else ans.pb(p[i].se);
	}
	cout << ans.size() << endl;
	for(int x : ans) cout << x + 1 << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
