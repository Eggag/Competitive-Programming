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
const int MOD = 1e9 + 7;
const int mxN = 2e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll n, k;
ll s[mxN * 4], lazy[mxN * 4];

void down(int id, int l, int r){
	if(lazy[id]){
		s[id] += 1LL * lazy[id] * (r - l);
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, ll u, int id = 1, int l = 0, int r = mxN){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] += u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id << 1, l, mid);
	increase(x, y, u, (id << 1) + 1, mid, r);
	s[id] = s[id << 1] + s[(id << 1) + 1];
}
 
ll sum(int x, int y, int id = 1, int l = 0, int r = mxN){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

void solve(){
	cin >> n >> k;
	vector<ll> l(n), w(n), h(n);
	memset(s, 0, sizeof(s));
	memset(lazy, 0, sizeof(lazy));
	rep(i, k) cin >> l[i];
	ll al, bl, cl, dl;
	cin >> al >> bl >> cl >> dl;
	repn(i, k, n) l[i] = ((al * l[i - 2] + bl * l[i - 1] + cl) % dl) + 1;
	rep(i, k) cin >> w[i];
	ll aw, bw, cw, dw;
	cin >> aw >> bw >> cw >> dw;
	repn(i, k, n) w[i] = ((aw * w[i - 2] + bw * w[i - 1] + cw) % dw) + 1;
	rep(i, k) cin >> h[i];
	ll ah, bh, ch, dh;
	cin >> ah >> bh >> ch >> dh;
	repn(i, k, n) h[i] = ((ah * h[i - 2] + bh * h[i - 1] + ch) % dh) + 1;
	vector<ll> cnt(n, 0);
	set<ll> st;
	map<ll, ll> m;
	rep(i, n) st.insert(l[i]), st.insert(l[i] + w[i]);
	ll cr = 0;
	for(ll x : st) m[x] = cr++;
	vector<ll> l1(n), l2(n);
	rep(i, n) l1[i] = m[l[i]];
	rep(i, n) l2[i] = m[l[i] + w[i]];
	set<ll> gap;
	rep(i, n){
		ll sm = sum(l1[i], l2[i] + 1);
		if(!sm) (cnt[i] += 2 * h[i]) %= MOD;
		auto it = gap.lb(l1[i]);
		int uwu = 0;
		while(it != gap.end() && *it < l2[i]){
		        uwu++;
		        auto it1 = it;
		        it++;
		        gap.erase(it1);
		}
		if(!sum(l2[i], l2[i] + 1) && uwu) uwu--;
		cnt[i] -= (uwu * 2 * h[i]) % MOD;
		if(cnt[i] < 0) cnt[i] += MOD;
		cnt[i] %= MOD;
		increase(l1[i], l2[i] + 1, 1);
		if(sum(l2[i], l2[i] + 1) == 1) gap.insert(l2[i]);
	}
	vector<array<ll, 3>> p;
	rep(i, n){
		p.pb(array<ll, 3>{l[i], 0, i});
		p.pb(array<ll, 3>{l[i] + w[i], 1, i});
	}
	sort(all(p));
	set<int> ind;
	ll lst = -1;
	rep(i, 2 * n){
		if(ind.size()) (cnt[*ind.begin()] += ((p[i][0] - lst) * 2) % MOD) %= MOD;
		lst = p[i][0];
		int st = p[i][0];
		while(i < (2 * n) && p[i][0] == st){
			if(!p[i][1]) ind.insert(p[i][2]);
			else ind.erase(ind.find(p[i][2]));
			i++;
		}
		i--;
	}
	repn(i, 1, n){
		cnt[i] += cnt[i - 1];
		if(cnt[i] < 0) cnt[i] += MOD;
		cnt[i] %= MOD;
		assert(cnt[i] >= 0);
	}
	ll ans = 1;
	rep(i, n) (ans *= cnt[i]) %= MOD;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
