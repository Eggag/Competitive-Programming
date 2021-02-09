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
const int logn = 23;
const int mxN = 4e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

pi pa[logn][mxN];
pair<int, ll> pa1[logn][mxN];
ll val[mxN];
int nxt[mxN];
int de[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int Q;
	cin >> Q;
	int lst = 0;
	int cur = 0;
	pa[0][cur] = mp(0, 0);
	repn(i, 1, logn){
		pa[i][cur] = mp(pa[i - 1][pa[i - 1][cur].fi].fi, max(pa[i - 1][cur].se, pa[i - 1][pa[i - 1][cur].fi].se));
	}
	pa1[0][cur] = mp(0, 0);
	repn(i, 1, logn){
		pa1[i][cur] = mp(pa1[i - 1][pa1[i - 1][cur].fi].fi, pa1[i - 1][cur].se + pa1[i - 1][pa1[i - 1][cur].fi].se);
	}
	cur = 1;
	de[0] = 1;
	rep(j, Q){
		int t;
		cin >> t;
		if(t == 1){
			int p;
			ll q;
			cin >> p >> q;
			p ^= lst, q ^= lst;
			val[cur] = q;
			p--;
			pa[0][cur] = mp(p, max(q, val[p]));
			repn(i, 1, logn){
				pa[i][cur] = mp(pa[i - 1][pa[i - 1][cur].fi].fi, max(pa[i - 1][cur].se, pa[i - 1][pa[i - 1][cur].fi].se));
			}
			int cr = pa[0][cur].fi;
			for(int i = logn - 1; i >= 0; i--){
				if(pa[i][cr].se < q){
					cr = pa[i][cr].fi;
				}
			}
			if(val[cr] < val[cur]){
				if(val[pa[0][cr].fi] >= val[cur]) cr = pa[0][cr].fi;
				else cr = cur;
			}
			nxt[cur] = cr;
			if(nxt[cur] == cur) de[cur] = 1;
			else de[cur] = de[nxt[cur]] + 1;
			pa1[0][cur] = mp(nxt[cur], val[nxt[cur]]);
			repn(i, 1, logn){
				pa1[i][cur] = mp(pa1[i - 1][pa1[i - 1][cur].fi].fi, pa1[i - 1][cur].se + pa1[i - 1][pa1[i - 1][cur].fi].se);
			}
			cur++;
		}
		else{
			int p;
			ll q;
			cin >> p >> q;
			p ^= lst, q ^= lst;
			p--;
			if(val[p] > q){
				cout << 0 << '\n';
				lst = 0;
				continue;
			}
			if(!p){
				cout << 1 << '\n';
				lst = 1;
				continue;
			}
			int ans = 1;
			int cr = p;
			q -= val[p];
			for(int i = logn - 1; i >= 0; i--){
				if(pa1[i][cr].se <= q){
					q -= pa1[i][cr].se;
					cr = pa1[i][cr].fi;
					ans += (1 << i);
				}
			}			
			ans = min(ans, de[p]);
			cout << ans << '\n';
			lst = ans;
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
