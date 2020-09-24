#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) debug(x) debug(y);
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

int cnt[30][1005][1005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<pair<int, pi>> segs;
	rep(j, m){
		vector<pi> sg;
		int cur = 1, st = 0;
		repn(i, 1, n){
			if(s[i][j] == s[i - 1][j]) cur++;
			else{
				sg.pb(mp(st, cur));
				st = i;
				cur = 1;
			}
		}
		sg.pb(mp(st, cur));
		rep(i, sg.size() - 2){
			if(sg[i].se >= sg[i + 1].se && sg[i + 1].se <= sg[i + 2].se){
				//segs.pb(mp(j, mp(sg[i].fi, sg[i].fi + (3 * sg[i].se) - 1)));
				segs.pb(mp(j, mp(sg[i + 1].fi - sg[i + 1].se, sg[i + 1].fi + (2 * sg[i + 1].se) - 1)));
			}
		}
	}
	rep(k, 30) rep(j, m) rep(i, n){
		if(j > 0) cnt[k][j][i] += cnt[k][j - 1][i];
		cnt[k][j][i] += (s[i][j] == (char)('a' + k));
	}
	ll ans = 0;
	rep(i, segs.size()){
		ll mn = 1e18;
		int c = segs[i].fi;
		int l = segs[i].se.fi, r = segs[i].se.se;
		repn(j, l, r + 1){
			ll l1 = 0, r1 = (m - 1) - c;
			while(l1 < r1){
				int mid = (l1 + r1 + 1) / 2;
				int let = s[j][c] - 'a';
				if(cnt[let][c + mid][j] - cnt[let][c][j] == (mid)) l1 = mid;
				else r1 = mid - 1;
			}
			mn = min(mn, l1);
		}
		ans += mn + 1;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
