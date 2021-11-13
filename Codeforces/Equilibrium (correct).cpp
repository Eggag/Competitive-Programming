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

int n, q;
ll dat[1 << 20], dat1[1 << 20];

void update(int i, int s, int e, int x, ll v){
	if(s == e){
		dat[i] = v;
		dat1[i] = v;
		return;
	}
	int m = (s + e) / 2;
	if(x <= m) update(i << 1, s, m, x, v);
	else update(i << 1 | 1, m + 1, e, x, v);
	dat[i] = min(dat[i << 1], dat[i << 1 | 1]);
	dat1[i] = max(dat1[i << 1], dat1[i << 1 | 1]);
}

void update(int x, ll v){
	update(1, 0, n, x, v);
}

ll minQ(int i, int s, int e, int x, int y){
	if(e < x || y < s) return 1e18;
	if(x <= s && e <= y) return dat[i];
	int m = (s + e) / 2;
	return min(minQ(i << 1, s, m, x, y), minQ(i << 1 | 1, m + 1, e, x, y));
}

ll minQ(int x, int y){
	return minQ(1, 0, n, x, y);
}

ll maxQ(int i, int s, int e, int x, int y){
	if(e < x || y < s) return -1e18;
	if(x <= s && e <= y) return dat1[i];
	int m = (s + e) / 2;
	return max(maxQ(i << 1, s, m, x, y), maxQ(i << 1 | 1, m + 1, e, x, y));
}

ll maxQ(int x, int y){
	return maxQ(1, 0, n, x, y);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> q;
	vector<ll> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<ll> cnt(n, 0LL), cnt1(n, 0LL);
	cnt[0] = a[0];
	cnt1[0] = b[0];
	repn(i, 1, n){
		cnt[i] = cnt[i - 1] + a[i];
		cnt1[i] = cnt1[i - 1] + b[i];
	}
	rep(i, (1 << 20)){
		dat[i] = 1e18;
		dat1[i] = -1e18;
	}
	vector<ll> dif(n, 0LL);
	dif[0] = a[0] - b[0];
	repn(i, 1, n) dif[i] = dif[i - 1] + (a[i] - b[i]);
	rep(i, n) update(i, dif[i]);
	rep(i, q){
		int l, r;
		cin >> l >> r;
		l--, r--;
		ll sm = cnt[r] - (l ? cnt[l - 1] : 0LL);
		ll sm1 = cnt1[r] - (l ? cnt1[l - 1] : 0LL);
		ll mn = minQ(l, r), mx = maxQ(l, r);
		if(sm != sm1 || (mx - (l ? dif[l - 1] : 0LL)) > 0){
			cout << "-1\n";
			continue;
		}
		cout << max(abs(mn - (l ? dif[l - 1] : 0LL)), abs(mx - (l ? dif[l - 1] : 0LL))) << '\n';
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
