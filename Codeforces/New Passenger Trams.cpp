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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, h, m, k;
	cin >> n >> h >> m >> k;
	vector<pi> p(n);
	vi uwu;
	rep(i, n) cin >> p[i].fi >> p[i].se, uwu.pb(p[i].se);
	sort(all(uwu));
	vector<pi> st;
	rep(i, n){
		if(p[i].se >= m / 2) st.pb(mp(p[i].se - (m / 2), p[i].se));
		else st.pb(mp(p[i].se, p[i].se + (m / 2)));
	}
	int bst = -1, ind = -1;
	rep(i, st.size()){
		int nw = 0;
		if(st[i].fi - k < 0){
			int s = k - st[i].fi;
			int l = m - s, r = m;
			int it = lb(all(uwu), r) - uwu.begin();
			int it1 = ub(all(uwu), l) - uwu.begin();
			nw += max(0, it - it1);
			l = -1, r = st[i].fi;
			it = lb(all(uwu), r) - uwu.begin();
			it1 = ub(all(uwu), l) - uwu.begin();
			nw += max(0, it - it1);
		}
		else{
			int l = st[i].fi - k, r = st[i].fi;
			int it = lb(all(uwu), r) - uwu.begin();
			int it1 = ub(all(uwu), l) - uwu.begin();
			nw += max(0, it - it1);
		}
		int l1 = st[i].se - k, r1 = st[i].se;
		int it2 = lb(all(uwu), r1) - uwu.begin();
		int it3 = ub(all(uwu), l1) - uwu.begin();
		nw += max(0, it2 - it3);
		nw = n - nw;
		if(nw > bst) bst = nw, ind = i;
	}
	cout << n - bst << " " << st[ind].fi << '\n';
	rep(j, n){
		int i = ind, f = 0;
		if(st[i].fi - k < 0){
			int s = k - st[i].fi;
			int l = m - s, r = m;
			if(p[j].se > l && p[j].se < r) f = 1;
			l = -1, r = st[i].fi;
			if(p[j].se > l && p[j].se < r) f = 1;
		}
		else{
			int l = st[i].fi - k, r = st[i].fi;
			if(p[j].se > l && p[j].se < r) f = 1;
		}
		int l1 = st[i].se - k, r1 = st[i].se;
		if(p[j].se > l1 && p[j].se < r1) f = 1;
		if(f) cout << j + 1 << " ";
	}
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
