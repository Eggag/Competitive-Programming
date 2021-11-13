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
#define unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
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

void solve(){
	int n;
	cin >> n;
	vector<pi> p(n);
	vi cur1;
	rep(i, n){
		cin >> p[i].fi >> p[i].se;
		cur1.pb(p[i].fi);
		cur1.pb(p[i].se);
	}
	unique(cur1);
	map<int, int> m;
	int cnt = 0;
	for(int x : cur1) m[x] = cnt, cnt += 2;
	vi cnt1(cnt + 1, 0);
	rep(i, n){
		p[i].fi = m[p[i].fi], p[i].se = m[p[i].se];
		cnt1[p[i].fi]++;
		cnt1[p[i].se + 1]--;
	}
	vi cn(cnt + 1, 0);
	partial_sum(all(cnt1), cnt1.begin());
	int ff = 0, uwu = 0;
	rep(i, cnt){
		if(!ff && cnt1[i]) ff = 1;
		if(ff == 1 && !cnt1[i]) ff = 2;
		if(cnt1[i] > 1) uwu = 1;
		if((uwu || ff == 2) && cnt1[i] == 1 && cnt1[i + 1] > 1) cn[i]++;
	}
	int owo = 0;
	for(int i = cnt; i >= 1; i--){
		if(owo && cnt1[i] == 1 && cnt1[i - 1] > 1) cn[i]++;
		if(!cnt1[i]) owo = 1;
		else if(cnt1[i] > 1) owo = 0;
	}
	partial_sum(all(cn), cn.begin());
	vi pr(cnt + 1, 0), sf(cnt + 1, 0);
	rep(i, cnt){
		if(i) pr[i] = pr[i - 1];
		if(!cnt1[i] && cnt1[i + 1]) pr[i]++;
	}
	for(int i = cnt - 1; i >= 0; i--){
		if(i != (cnt - 1)) sf[i] = sf[i + 1];
		if(cnt1[i] && !cnt1[i + 1]) sf[i]++;
	}
	int mx = 0;
	rep(i, n) if(p[i].se >= p[i].fi){
		int cur = cn[p[i].se] - (p[i].fi ? cn[p[i].fi - 1] : 0);
		if(p[i].fi){
			cur += pr[p[i].fi - 1];
			if(!cnt1[p[i].fi - 1] && cnt1[p[i].fi] == 1) cur--;
		}
		cur += sf[p[i].se];
		if(cnt1[p[i].se] == 1 && !cnt1[p[i].se + 1]) cur--;
		mx = max(mx, cur);
	}
	cout << mx << '\n';
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
