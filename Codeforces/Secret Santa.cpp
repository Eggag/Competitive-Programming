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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

vi g[mxN];

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n + 1) g[i].clear();
	rep(i, n) cin >> a[i], a[i]--, g[a[i]].pb(i);
	vi bd(n, 0);
	rep(i, n) if(!g[i].size()) bd[i] = 1;
	vi vs(n, -1), vv(n, 0);
	int cnt = 0;
	rep(i, n){
		int f = 0;
		for(int x : g[i]) if(vs[x] == -1){
			if(bd[x]){
				vs[x] = i;
				vv[i] = 1;
				cnt++;
				f = 1;
				break;
			}
		}
		if(!f){
			for(int x : g[i]) if(vs[x] == -1){
				if(!bd[x]){
					vs[x] = i;
					vv[i] = 1;
					cnt++;
					break;
				}
			}
		}
	}
	vi st, en;
	vi bb(n, 0);
	rep(i, n) if(vs[i] == -1 && !vv[i]) st.pb(i), bb[i] = 1;
	rep(i, st.size()) if(!vv[st[i]]) en.pb(st[i]), vv[st[i]] = 1;
	rep(i, n) if(!bb[i] && vs[i] == -1) st.pb(i);
	rep(i, n) if(!vv[i]) en.pb(i);
	assert((int)st.size() == (int)en.size());
	rep(i, st.size()){
		int nxt = i + 1;
		if(nxt == (int)(en.size())) nxt = 0;
		vs[st[i]] = en[nxt];
	}
	rep(i, n) if(vs[i] == i){
		swap(vs[i], vs[(i + 1) % n]);
		cnt--;
	}
	int ans = 0;
	rep(i, n) if(a[i] == vs[i]) ans++;
	cout << ans << '\n';
	rep(i, n) cout << vs[i] + 1 << " ";
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
