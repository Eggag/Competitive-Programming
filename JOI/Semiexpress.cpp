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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	ll a, b, c;
	cin >> a >> b >> c;
	ll t;
	cin >> t;
	vector<ll> s(m);
	rep(i, m) cin >> s[i];
	ll tot = 0LL;
	vector<ll> nm(m, 0LL);
	rep(i, m - 1){
		ll cr = b * (s[i] - 1);
		ll l = 0, r = s[i + 1] - s[i] - 1;
		while(l < r){
			ll mid = (l + r + 1) / 2;
			if((mid * a + cr) <= t) l = mid;
			else r = mid - 1;
		}
		if(l <= r && l * a + cr <= t) tot += l + 1, nm[i] = l + 1;
	}
	if(b * (s[m - 1] - 1) <= t) tot++;
	multiset<pair<ll, int>> bst;
	rep(i, m - 1){
		ll cr = b * (s[i] - 1) + c * nm[i];
		ll l = 0, r = s[i + 1] - (s[i] + nm[i]) - 1;
		while(l < r){
			ll mid = (l + r + 1) / 2;
			if((mid * a + cr) <= t) l = mid;
			else r = mid - 1;
		}
		if(l <= r && l * a + cr <= t) bst.insert({l + 1, i});
	}
	int lft = k - m;
	while(lft--){
		if(!bst.size()) break;
		auto it = --bst.end();
		pair<ll, int> cur = *it;
		bst.erase(it);
		tot += cur.fi;
		int i = cur.se;
		nm[i] += cur.fi;
		ll cr = b * (s[i] - 1) + c * nm[i];
		ll l = 0, r = s[i + 1] - (s[i] + nm[i]) - 1;
		while(l < r){
			ll mid = (l + r + 1) / 2;
			if((mid * a + cr) <= t) l = mid;
			else r = mid - 1;
		}
		if(l <= r && (l * a + cr) <= t) bst.insert({l + 1, i});
	}
	cout << tot - 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
