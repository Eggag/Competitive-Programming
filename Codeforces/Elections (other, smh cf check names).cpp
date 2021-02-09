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
const int mxN = 3005;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<pi> p(n);
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		g[p[i].fi].pb(p[i].se);
	}
	repn(i, 2, m + 1) sort(all(g[i]));
	ll mn = 1e18;
	repn(i, g[1].size(), n + 1) if(i){
		ll tot = 0LL;
		int cnt = (int)(g[1].size());
		multiset<int> st;
		repn(j, 2, m + 1){
			if((int)(g[j].size()) >= i){
				int num = (int)(g[j].size()) - i + 1;
				rep(k, num) tot += g[j][k];
				cnt += num;
			}
			int sta = max(0, (int)(g[j].size()) - i + 1);
			repn(k, sta, g[j].size()) st.insert(g[j][k]);
		}
		if(cnt <= i){
			while(cnt < i && !st.empty()){
				int tp = *st.begin();
				st.erase(st.begin());
				tot += (ll)(tp);
				cnt++;
			}
			if(cnt == i) mn = min(mn, tot);
		}
	}
	cout << mn << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
