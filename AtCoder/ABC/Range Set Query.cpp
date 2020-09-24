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

int bl = 0;

bool cmp(pair<pi, int> a1, pair<pi, int> b1){
	pi a = a1.fi, b = b1.fi;
	if(a.fi / bl != b.fi / bl){
		return (a.fi / bl) < (b.fi / bl);
	}
	return a.se < b.se;
}

int main(){
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	vi c(n + 1);
	repn(i, 1, n + 1) scanf("%d", &c[i]);
	vector<pair<pi, int>> p(q);
	bl = (int)sqrt(n);
	rep(i, q) cin >> p[i].fi.fi >> p[i].fi.se, p[i].se = i;
	vi ans(q);
	sort(all(p), cmp);
	int curL = 0, curR = 0;
	int un = 0;
	vi cnt(6e5 + 5, 0);
	rep(i, q){
		int l = p[i].fi.fi, r = p[i].fi.se;
		while(curR <= r){
			if(!cnt[c[curR]]) un++;
			cnt[c[curR]]++;
			curR++;
		}
		while(curR > (r + 1)){
			if(cnt[c[curR - 1]]){
				cnt[c[curR - 1]]--;
				if(!cnt[c[curR - 1]]) un--;
			}
			curR--;
		}
		while(curL < l){
			if(cnt[c[curL]]){
				cnt[c[curL]]--;
				if(!cnt[c[curL]]) un--;
			}
        		curL++;
		}
		while(curL > l){
			if(!cnt[c[curL - 1]]) un++;
			cnt[c[curL - 1]]++;
			curL--;
		}
		ans[p[i].se] = un;
	}
	rep(i, q) printf("%d\n", ans[i]);
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
