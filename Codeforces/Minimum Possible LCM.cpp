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
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
const int mxD = 1e7 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int p[mxD], lst[mxD];
pair<pi, pi> m[mxD];
vector<pi> d;
vi pr;
int nw = 0, pos = 0;

void sieve(int n){
	for(int i = 2; i < n; i++) if(!p[i]){
		p[i] = i;
		for(int j = i + i; j < n; j += i) if(!p[j]) p[j] = i;
	}	
}

void f(int ind, int num){
	if(num > 1 && (!m[num].se.fi || (nw / num) < m[num].se.fi) && lst[num] != pos) pr.pb(num), lst[num] = pos;
	if(ind == d.size()) return;
	int mul = 1;
	rep(i, d[ind].se + 1) f(ind + 1, num * mul), mul *= d[ind].fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> b(n);
	rep(i, n) cin >> b[i].fi, b[i].se = i;
	sort(all(b));
	vector<pi> a;
	int cnt = 1;
	a.pb(b[0]);
	repn(i, 1, n){
		if(b[i].fi == b[i - 1].fi) cnt++;
		else cnt = 1;
		if(cnt <= 2) a.pb(b[i]);
	}
	n = a.size();
	sieve(mxD);
	rep(i, mxD) m[i] = mp(mp(0, 0), mp(0, 0));
	memset(lst, -1, sizeof(lst));
	rep(i, n){
		if(!m[1].fi.fi || a[i].fi < m[1].fi.fi){
			m[1].se = m[1].fi;
			m[1].fi = mp(a[i].fi, a[i].se);
		}
		else if(!m[1].se.fi || a[i].fi < m[1].se.fi){
			m[1].se = mp(a[i].fi, a[i].se);
		}
		if(a[i].fi == 1) continue;
		int cur = a[i].fi;
		nw = a[i].fi;
		pos = i;
		vi div;
		while(cur > 1){
			div.pb(p[cur]);
			cur /= p[cur];
		}
		sort(all(div));
		int cnt = 1;
		repn(j, 1, div.size()){
			if(div[j] == div[j - 1]) cnt++;
			else{
				d.pb(mp(div[j - 1], cnt));
				cnt = 1;
			}
		}
		d.pb(mp(div[div.size() - 1], cnt));
		f(0, 1);
		for(int num : pr){
			int cr = nw / num;
			if(!m[num].fi.fi || cr < m[num].fi.fi){
				m[num].se = m[num].fi;
				m[num].fi = mp(cr, a[i].se);
			}
			else if(!m[num].se.fi || cr < m[num].se.fi){
				m[num].se = mp(cr, a[i].se);
			}
		}
		pr.clear();
		d.clear();
	}
	ll ans = 1e18;
	pi bst = {0, 0};
	repn(i, 1, mxD) if(m[i].fi.fi && m[i].se.fi){
		ll nm = (ll)(1LL * i * (ll)(m[i].fi.fi) * (ll)(m[i].se.fi));
		if(nm < ans) ans = nm, bst = mp(m[i].fi.se, m[i].se.se);
	}
	if(bst.fi > bst.se) swap(bst.fi, bst.se);
	cout << bst.fi + 1 << " " << bst.se + 1 << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
