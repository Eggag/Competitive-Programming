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
ll b[MAXN], s1[4 * MAXN];

void build(int id = 1, int l = 1, int r = n + 1){
	if(r - l < 2){
		s1[id] = b[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s1[id] = max(s1[id * 2], s1[id * 2 + 1]);
}

ll maxQ(int x, int y, int id = 1, int l = 1, int r = n + 1){
	if(x >= r || l >= y) return -1e18;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return max(maxQ(x, y, id * 2, l, mid), maxQ(x, y, id * 2 + 1, mid, r));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	vector<pair<ll, ll>> a(n + 1);
	repn(i, 1, n + 1) cin >> a[i].fi >> a[i].se;
	sort(1 + all(a));
	vector<ll> sum(n + 1, 0);
	repn(i, 1, n + 1) sum[i] += sum[i - 1] + a[i].se;
	ll ans = 0;
	repn(i, 1, n + 1) b[i] = sum[i] - a[i].fi;
	build();
	repn(i, 1, n + 1){
		//we need to have the maximum valueSum - 
		ll mxScore = maxQ(i, n + 1);
		ans = max(ans, mxScore - sum[i - 1] + a[i].fi);
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
