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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll a, b;
	cin >> a >> b;
	int q;
	cin >> q;
	vector<ll> s(a), t(b);
	rep(i, a) cin >> s[i];
	rep(i, b) cin >> t[i];
	rep(i, q){
	    ll x;
	    cin >> x;
	    int p = lb(all(s), x) - s.begin();
	    int p1 = lb(all(t), x) - t.begin();
	    int p2 = p - 1;
	    int p3 = p1 - 1;
	    ll ans = 1e18;
	    if(p < a && p1 < b) ans = min(ans, max(abs(x - s[p]), abs(x - t[p1])));
	    if(p2 >= 0 && p3 >= 0) ans = min(ans, max(abs(x - s[p2]), abs(x - t[p3])));
	    if(p < a && p3 >= 0) ans = min(ans, min(abs(x - t[p3]) + abs(s[p] - t[p3]), abs(x - s[p]) + abs(s[p] - t[p3])));
	    if(p2 >= 0 && p1 < b) ans = min(ans, min(abs(x - t[p1]) + abs(s[p2] - t[p1]), abs(x - s[p2]) + abs(s[p2] - t[p1])));
	    cout << ans << endl;
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
