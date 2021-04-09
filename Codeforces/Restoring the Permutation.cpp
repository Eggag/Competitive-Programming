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

void solve(){
	int n;
	cin >> n;
	vi q(n);
	rep(i, n) cin >> q[i];
	vi mn(n, -1), mx(n, -1), vis(n + 1, 0), pos;
	set<int> st;
	rep(i, n) if(!i || q[i] != q[i - 1]){
		mn[i] = q[i], mx[i] = q[i], vis[q[i]] = 1;
	}
	repn(i, 1, n + 1) if(!vis[i]) pos.pb(i), st.insert(i);
	int ind = 0;
	rep(i, n) if(mn[i] == -1) mn[i] = pos[ind++];
	rep(i, n) if(mx[i] == -1){
		auto it = st.lb(q[i]);
		assert(it != st.begin());
		it--;
		mx[i] = *it;
		st.erase(it);
	}
	for(int x : mn) cout << x << " ";
	cout << '\n';
	for(int x : mx) cout << x << " ";
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
