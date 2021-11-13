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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, w;
vi st[mxN], en[mxN];
ll cnt[mxN];
ll s[4 * mxN], lazy[4 * mxN];

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

void increase(int x, int y, ll u, int id = 1, int l = 0, int r = w){
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

ll sum(int x, int y, int id = 1, int l = 0, int r = w){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> w;
	vi l(n);
	vector<array<int, 3>> upd;
	multiset<int> cr;
	rep(i, n){
		cin >> l[i];
		vi a(l[i]);
		rep(j, l[i]) cin >> a[j];
		if(l[i] <= w / 2){
			int mx = 0;
			rep(j, l[i]){
				mx = max(mx, a[j]);
				cnt[j] += (ll)(mx);
			}
			mx = 0;
			for(int j = w - 1; j >= (w - l[i]); j--){
				mx = max(mx, a[l[i] - (w - j)]);
				cnt[j] += (ll)(mx);
			}
			int le = l[i], ri = w - l[i] - 1;
			if(le <= ri) upd.pb(array<int, 3>{le, ri, mx});
		}
		else{
			rep(j, l[i]){
				st[j].pb(a[j]);
				en[w - (l[i] - 1 - j)].pb(a[j]);
			}
			rep(j, w + 1){
				for(int x : st[j]) cr.insert(x);
				for(int x : en[j]){
					auto it = cr.find(x);
					if(it != cr.end()) cr.erase(it);
				}
				if(j == w) break;
				ll add = (ll)(*(--cr.end()));
				if((j + 1) + l[i] <= w) add = max(add, 0LL);
				if((w - j) + l[i] <= w) add = max(add, 0LL);
				cnt[j] += add;
			}
			cr.clear();
			rep(j, l[i]){
				st[j].pop_back();
				en[w - (l[i] - 1 - j)].pop_back();
			}
		}
	}
	rep(i, upd.size()) increase(upd[i][0], upd[i][1] + 1, (ll)(upd[i][2]));
	rep(i, w) cout << cnt[i] + sum(i, i + 1) << " ";
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
