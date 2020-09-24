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
const int MAXN = 2505;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int z;
int a[MAXN], s1[4 * MAXN];

void build(int id = 1, int l = 1, int r = z + 1){
	if(r - l < 2){
		s1[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s1[id] = min(s1[id * 2], s1[id * 2 + 1]);
}

int minQ(int x, int y, int id = 1, int l = 1, int r = z + 1){
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
	int n;
	ld k;
	cin >> n >> z >> k;
	vector<pi> p(n);
	rep(i, n) cin >> p[i].se >> p[i].fi;
	sort(all(p));
	repn(i, 1, z + 1) a[i] = 1e9;
	a[p[0].se] = 0;
	repn(i, 1, n){
		build();
		int cnt = 1;
		while((ld)((ld)(p[i].fi - p[i - 1].fi) / (ld)cnt) >= k) cnt++;
		cnt--;
		repn(j, 1, z + 1){
			a[j] = minQ(max(1, j - cnt), min(z, j + cnt) + 1) + abs(p[i].se - j);
		}
	}
	cout << a[p[n - 1].se] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
