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

bool cmp(pi a, pi b){
	if(a.se != b.se) return a.se > b.se;
	return a.fi < b.fi;
}

void solve(){
	int n;
	cin >> n;
	vi a(n + 1, -1);
	rep(i, n) cin >> a[i];
	int cur = n;
	vi p(n + 1, 0);
	p[n] = n + 1;
	vector<pi> q;
	rep(i, n) if(~a[i]) q.pb(mp(i, a[i] - 1));
	sort(all(q), cmp);
	int f = 1;
	rep(i, q.size()){
		int x = q[i].fi, y = q[i].se;
		if(!p[x] && !p[y]) p[x] = cur - 1, p[y] = cur, cur -= 2;
		if(!p[x] && p[y]) p[x] = cur--;
		if(p[x] && !p[y]){
			f = 0;
			break;
		}
	}
	rep(i, n) if(!p[i]) p[i] = cur--;
	vector<pi> stk;
	for(int i = n; i >= 0; i--){
		while(stk.size()){
			pi tp = stk[(int)(stk.size()) - 1];
			if(tp.fi < p[i]) stk.pop_back();
			else break;
		}
		if(~a[i] && stk.size()){
			pi tp = stk[(int)(stk.size()) - 1];
			if(tp.se != (a[i] - 1)){
				f = 0;
				break;
			}
		}
		stk.pb(mp(p[i], i));
	}
	if(!f) cout << -1 << '\n';
	else{
		rep(i, n) cout << p[i] << " ";
		cout << '\n';
	}
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
