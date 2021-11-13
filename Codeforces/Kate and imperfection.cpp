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
const int mxN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxN], vis[mxN];
vi fact[mxN];
int crn = 0;
vector<pi> d1;

void f(int ind, int num){
	if(ind == (int)(d1.size())){
		if(num != 1) fact[crn].pb(num);
		return;
	}
	rep(i, d1[ind].se + 1){
		f(ind + 1, num);
		num *= d1[ind].fi;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int pr = 1;
	repn(i, 2, n + 1){
		if(!p[i]) p[i] = i, pr++, vis[i] = 1;
		for(int j = i + i; j <= n; j += i) if(!p[j]) p[j] = i;
	}
	repn(i, 2, n + 1){
		vi d;
		int cr = i;
		crn = i;
		while(cr > 1){
			d.pb(p[cr]);
			cr /= p[cr];
		}
		sort(all(d));
		int cnt = 1;
		repn(j, 1, d.size()){
			if(d[j] == d[j - 1]) cnt++;
			else{
				d1.pb(mp(d[j - 1], cnt));
				cnt = 1;
			}
		}
		d1.pb(mp(d[(int)(d.size()) - 1], cnt));
		f(0, 1);
		d1.clear();
	}
	vi ans(n + 1, 1);
	int st = pr + 1;
	for(int i = 2; i <= n; i++){
		int nw = 0;
		rep(j, i + 1){
			if(i * j > n) break;
			if(vis[i * j] || (i * j) == 0) continue;
			int cur = i * j;
			int f = 1;
			for(int k : fact[cur]) if(vis[k] && k > i){
				f = 0;
				break;
			}
			if(f){
				for(int k : fact[cur]) vis[k] = 1;
				nw++;
			}
		}
		repn(j, st, st + nw){
			if(j > n) break;
			ans[j] = i;
		}
		st = st + nw;
	}
	repn(i, 2, n + 1) cout << ans[i] << " ";
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
