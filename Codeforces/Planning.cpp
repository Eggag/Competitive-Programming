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
	int n, k;
	cin >> n >> k;
	vector<pair<ll, int>> c(n);
	rep(i, n) cin >> c[i].fi, c[i].se = i + 1;
	set<int> st;
	repn(i, k + 1, n + k + 1) st.insert(i);
	vi ans(n, 0);
	sort(all(c));
	reverse(all(c));
	ll cost = 0;
	rep(i, n){
		int cur = c[i].se;
		int pos = *st.lb(cur);
		ans[c[i].se - 1] = pos;
		cost += (pos - c[i].se) * c[i].fi;
		st.erase(pos);
	}
	cout << cost << endl;
	rep(i, n){
		cout << ans[i];
		if(i != (n - 1)) cout << " ";
		else cout << endl;
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
