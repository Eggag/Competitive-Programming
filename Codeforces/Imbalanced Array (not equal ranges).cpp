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
const int mxN = 1e6 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
ll a[mxN], s1[4 * mxN], s[4 * mxN];

void build(int id = 1, int l = 0, int r = n){
	if(r - l < 2){
		s1[id] = a[l];
		s[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s[id] = max(s[id * 2], s[id * 2 + 1]);
	s1[id] = min(s1[id * 2], s1[id * 2 + 1]);
}

ll minQ(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return 1e18;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return min(minQ(x, y, id * 2, l, mid), minQ(x, y, id * 2 + 1, mid, r));
}

ll maxQ(int x, int y, int id = 1, int l = 0, int r = n){
	if(x >= r || l >= y) return -1e18;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return max(maxQ(x, y, id * 2, l, mid), maxQ(x, y, id * 2 + 1, mid, r));
}

ll ans = 0LL;
vi pos[mxN];

void solveMax(int l, int r){
	if(l >= r) return;
	ll mx = maxQ(l, r);
	int m = (l + r) / 2;
	int l1 = 0, r1 = pos[mx].size() - 1;
	while(l1 < r1){
		int mid1 = (l1 + r1) / 2;
		if(pos[mx][mid1] >= l) r1 = mid1;
		else l1 = mid1 + 1;
	}
	int bst = l1;
	assert(bst != -1);
	ll add = (ll)(1LL * (pos[mx][bst] - l + 1) * (r - pos[mx][bst]) * mx);
	ans += add;
	if(l < pos[mx][bst]) solveMax(l, pos[mx][bst]);
	if(pos[mx][bst] + 1 < r) solveMax(pos[mx][bst] + 1, r);
}

void solveMin(int l, int r){
	if(l >= r) return;
	ll mx = minQ(l, r);
	int m = (l + r) / 2;
	int l1 = 0, r1 = pos[mx].size() - 1;
	while(l1 < r1){
		int mid1 = (l1 + r1) / 2;
		if(pos[mx][mid1] >= l) r1 = mid1;
		else l1 = mid1 + 1;
	}
	int bst = l1;
	ll sub = (ll)(1LL * (pos[mx][bst] - l + 1) * (r - pos[mx][bst]) * mx);
	ans -= sub;
	if(l < pos[mx][bst]) solveMin(l, pos[mx][bst]);
	if(pos[mx][bst] + 1 < r) solveMin(pos[mx][bst] + 1, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i], pos[a[i]].pb(i);
	build();
	solveMax(0, n);
	solveMin(0, n);
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
