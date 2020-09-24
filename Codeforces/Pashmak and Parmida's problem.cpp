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
const int MAXN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[MAXN], s[4 * MAXN], lazy[4 * MAXN];

void build(int id = 1, int l = 0, int r = n){
	if((r - l) < 2){
		s[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = (s[id * 2] + s[id * 2 + 1]);
}

void down(int id, int l, int r){
	if(lazy[id]){
		s[id] += lazy[id];
		if((r - l) > 1){
			lazy[2 * id] = lazy[id];
			lazy[2 * id + 1] = lazy[id];
		}
	}
	lazy[id] = 0;
}

void increase(int x, int y, ll u, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return;
	if(x <= l && r <= y){
		lazy[id] = u;
		down(id, l, r);
		return;
	}
	int mid = (l + r) / 2;
	increase(x, y, u, id * 2, l, mid);
	increase(x, y, u, id * 2 + 1, mid, r);
	s[id] = s[id * 2] + s[id * 2 + 1];
}

int sum(int x, int y, int id = 1, int l = 0, int r = n){
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
	cin >> n;
	rep(i, n) cin >> a[i];
	unordered_map<int, int> m, m1;
	rep(i, n) m[a[i]]++;
	ll ans = 0;
	m[a[n - 1]]--;
	m1[a[n - 1]]++;
	memset(s, 0, sizeof(s));
	increase(1, 2, 1);
	for(int i = n - 2; i >= 0; i--){
		int x = m[a[i]];
		ans += sum(0, x);
		m[a[i]]--;
		m1[a[i]]++;
		increase(m1[a[i]], m1[a[i]] + 1, 1);
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
