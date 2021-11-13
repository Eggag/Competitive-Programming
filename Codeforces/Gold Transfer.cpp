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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll a[mxN], c[mxN];
int d[mxN];
pair<ll, ll> cnt[mxN];
int up[22][mxN];

int main(){
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int q;
	cin >> q >> a[0] >> c[0];
	rep(i, mxN) cnt[i] = mp(0LL, 0LL);
	cnt[0] = mp(a[0], c[0]);
	repn(i, 1, q + 1){
		int t;
		cin >> t;
		if(t == 1){
			int pr;
			cin >> pr >> a[i] >> c[i];
			cnt[i] = mp(a[i], c[i]);
			d[i] = d[pr] + 1;
			up[0][i] = pr;
			repn(j, 1, 22) up[j][i] = up[j - 1][up[j - 1][i]];
		}
		else{
			int v;
			ll w;
			cin >> v >> w;
			int st = v;
			for(int j = 21; j >= 0; j--) if(a[up[j][v]] == cnt[up[j][v]].fi){
				v = up[j][v];
			}
			v = up[0][v];
			ll tot = 0LL, cst = 0LL;
			while(tot < w){
				if(cnt[v].fi > (w - tot)){
					cnt[v].fi -= (w - tot);
					cst += (ll)((w - tot) * cnt[v].se);
					tot = w;
				}
				else{
					tot += cnt[v].fi;
					cst += (cnt[v].fi * cnt[v].se);
					cnt[v].fi = 0LL;
					if(v == st) break;
					int dist = d[st] - d[v];
					int cr = st;
					for(int j = 21; j >= 0; j--) if((dist - 1) & (1 << j)) cr = up[j][cr];
					v = cr;
				}
			}
			cout << tot << " " << cst << endl;
		}
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
