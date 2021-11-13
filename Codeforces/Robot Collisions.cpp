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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> p(n), p1(n);
	rep(i, n) cin >> p[i][0], p[i][2] = i;
	rep(i, n){
		char c;
		cin >> c;
		p[i][1] = (c == 'L');
	}
	p1 = p;
	sort(all(p));
	vector<array<int, 3>> a, b;
	rep(i, n){
		if(p[i][0] & 1) a.pb(p[i]);
		else b.pb(p[i]);
	}
	int x = (int)(a.size()), y = (int)(b.size());
	vi ans(n, -1);
	vi vis(n, 0);
	vector<pi> cur;
	rep(i, x){
		if(a[i][1]){
			if(cur.size()){
				pi nw = cur.back();
				if(!nw.fi){
					ans[a[i][2]] = ans[nw.se] = abs(a[i][0] - p1[nw.se][0]) / 2;
					vis[a[i][2]] = vis[nw.se] = 1;
					cur.pop_back();
				}
				else cur.pb(mp(a[i][1], a[i][2]));
			}
			else cur.pb(mp(a[i][1], a[i][2]));
		}
		else cur.pb(mp(a[i][1], a[i][2]));
	}
	vector<array<int, 3>> a1;
	rep(i, x) if(!vis[a[i][2]]) a1.pb(a[i]);
	x = (int)(a1.size());
	int st = 0;
	rep(i, x) if(a1[i][1]) st++;
	int f = 0, f1 = 0;
	for(int i = 0; i < (st - 1); i += 2){
		ans[a1[i][2]] = ans[a1[i + 1][2]] = a1[i][0] + (a1[i + 1][0] - a1[i][0]) / 2;
		if((i + 1) == (st - 1)) f = 1;
	}
	for(int i = x - 2; i >= st; i -= 2){
		ans[a1[i][2]] = ans[a1[i + 1][2]] = (m - a1[i + 1][0]) + (a1[i + 1][0] - a1[i][0]) / 2;
		if(i == st) f1 = 1;
	}
	if(st != 0 && st != x && !f && !f1){
		ans[a1[st][2]] = ans[a1[st - 1][2]] = (a1[st - 1][0] + (m - a1[st][0]) + m) / 2;
	}
	vi vis1(n, 0);
	cur.clear();
	rep(i, y){
		if(b[i][1]){
			if(cur.size()){
				pi nw = cur.back();
				if(!nw.fi){
					ans[b[i][2]] = ans[nw.se] = abs(b[i][0] - p1[nw.se][0]) / 2;
					vis1[b[i][2]] = vis1[nw.se] = 1;
					cur.pop_back();
				}
				else cur.pb(mp(b[i][1], b[i][2]));
			}
			else cur.pb(mp(b[i][1], b[i][2]));
		}
		else cur.pb(mp(b[i][1], b[i][2]));
	}
	vector<array<int, 3>> b1;
	rep(i, y) if(!vis1[b[i][2]]) b1.pb(b[i]);
	y = (int)(b1.size());
	st = 0;
	rep(i, y) if(b1[i][1]) st++;
	f = 0, f1 = 0;
	for(int i = 0; i < (st - 1); i += 2){
		ans[b1[i][2]] = ans[b1[i + 1][2]] = b1[i][0] + (b1[i + 1][0] - b1[i][0]) / 2;
		if((i + 1) == (st - 1)) f = 1;
	}
	for(int i = y - 2; i >= st; i -= 2){
		ans[b1[i][2]] = ans[b1[i + 1][2]] = (m - b1[i + 1][0]) + (b1[i + 1][0] - b1[i][0]) / 2;
		if(i == st) f1 = 1;
	}
	if(st != 0 && st != y && !f && !f1){
		ans[b1[st][2]] = ans[b1[st - 1][2]] = (b1[st - 1][0] + (m - b1[st][0]) + m) / 2;
	}
	rep(i, n) cout << ans[i] << ' ';
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
