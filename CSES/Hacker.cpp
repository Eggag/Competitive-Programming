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
const int MAXN = 5e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int b[MAXN], s1[4 * MAXN];

void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		s1[id] = b[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s1[id] = min(s1[id * 2], s1[id * 2 + 1]);
}

int minQ(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 1e9;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	int ans = 0;
	int cur = 0;
	rep(i, (n + 1) / 2) cur += a[i];
	int lst = 0;
	int nxt = (n + 1) / 2;
	b[0] = cur;
	repn(i, 1, n){
		b[i] = b[i - 1];
		b[i] -= a[lst];
		lst++;
		b[i] += a[nxt];
		nxt++;
		if(nxt == n) nxt = 0;
	}
	build();
	rep(i, n){
		int st = max(0, i - ((n + 1) / 2) + 1);
		int cur = min(minQ(st, min(i + 1, st + (n + 1) / 2)), minQ(n - max((n + 1) / 2 - i, 0) + 1, n));
		ans = max(ans, cur);
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
