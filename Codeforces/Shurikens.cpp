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
	int n;
	cin >> n;
	set<int> st;
	vector<pi> p;
	vi a;
	rep(i, 2 * n){
		char c;
		cin >> c;
		if(c == '+') st.insert(i);
		else{
			int cs;
			cin >> cs;
			p.pb({cs, i});
			a.pb(cs);
		}
	}	
	vector<pi> sta;
	vi b(n);
	rep(i, n){
		while(sta.size() && sta.back().fi < a[i]) sta.pop_back();
		if(sta.size()) b[i] = sta.back().se;
		else b[i] = -1;
		sta.pb({a[i], p[i].se});
	}
	vector<pi> ans;
	rep(i, p.size()){
		auto it = st.lb(b[i] + 1);
		int ps = *it;
		if(ps >= p[i].se || ps <= b[i]){
			cout << "NO" << endl;
			return 0;
		}
		if(it != st.end()) st.erase(it);
		ans.pb({ps, p[i].fi});
	}
	cout << "YES" << endl;
	sort(all(ans));
	rep(i, ans.size()) cout << ans[i].se << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
