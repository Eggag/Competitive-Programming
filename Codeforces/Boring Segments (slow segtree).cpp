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
const int mxN = 3e5 + 5;
const int mxM = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n, m;
array<int, 3> p[mxN];
int s1[4 * mxM], lazy[4 * mxM];
 
void down(int id, int l, int r){
	if(lazy[id]){
		s1[id] += lazy[id];
		if((r - l) > 1){
			lazy[id << 1] += lazy[id];
			lazy[(id << 1) + 1] += lazy[id];
		}
	}
	lazy[id] = 0;
}
 
void increase(int x, int y, int u, int id = 1, int l = 0, int r = m + 1){
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
	s1[id] = min(s1[id << 1], s1[(id << 1) + 1]);
}
 
int minQ(int x, int y, int id = 1, int l = 0, int r = m + 1){
	down(id, l, r);
	if(x >= r || l >= y) return 1e9;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}

bool cmp(array<int, 3> a, array<int, 3> b){
	return a[2] < b[2];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> m;
	rep(i, n) cin >> p[i][0] >> p[i][1] >> p[i][2];
	sort(p, p + n, cmp);
	int ans = 1e6, le = 0;
	memset(s1, 0, sizeof(s1));
	memset(lazy, 0, sizeof(lazy));
	rep(i, n){
		if(i) increase(p[i - 1][0] + (p[i - 1][0] != 1), p[i - 1][1] + 1, -1);
		while(le < n && !minQ(1, m + 1)){
			increase(p[le][0] + (p[le][0] != 1), p[le][1] + 1, 1);
			le++;
		}
		if(minQ(1, m + 1)) ans = min(ans, (le == i ? 0 : p[le - 1][2] - p[i][2]));
	}
	cout << ans << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
