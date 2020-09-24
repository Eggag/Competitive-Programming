#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
#define debug2(x, y) debug(x), debug(y);
#define repn(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(i, a) for(int i = 0; i < (int)(a); i++)
#define all(v) v.begin(), v.end() 
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	pi a, b, c;
	cin >> a.fi >> a.se >> b.fi >> b.se >> c.fi >> c.se;
	set<pi> ans;
	ans.insert({a.fi, a.se});
	ans.insert({b.fi, b.se});
	ans.insert({c.fi, c.se});
	if(a.fi > b.fi) swap(a.fi, b.fi), swap(a.se, b.se);	
	if(b.fi > c.fi) swap(b.fi, c.fi), swap(b.se, c.se);
	if(a.fi > b.fi) swap(a.fi, b.fi), swap(a.se, b.se);	
	for(int i = min({a.se, b.se, c.se}); i <= max({a.se, b.se, c.se}); i++)
		ans.insert({b.fi, i});
	for(int i = a.fi; i < b.fi; i++)
		ans.insert({i, a.se});
	for(int i = b.fi + 1; i <= c.fi; i++)
		ans.insert({i, c.se});
	cout << ans.size() << endl;
	for(auto x : ans) cout << x.fi << " " << x.se << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
