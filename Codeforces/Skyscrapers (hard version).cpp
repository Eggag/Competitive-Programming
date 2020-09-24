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
ll a[MAXN], s[4 * MAXN], lazy[4 * MAXN], b[MAXN], marked[4 * MAXN];

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
		s[id] = 1LL * lazy[id] * (r - l);
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

ll sum(int x, int y, int id = 1, int l = 0, int r = n){
	down(id, l, r);
	if(x >= r || l >= y) return 0;
	if(x <= l && r <= y) return s[id];
	int mid = (l + r) / 2;
	return (sum(x, y, id * 2, l, mid) + sum(x, y, id * 2 + 1, mid, r));
}

ll dp[MAXN];
ll dp1[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n;
	rep(i, n) cin >> a[i], b[i] = a[i];
	memset(dp, 0LL, sizeof(dp));
	memset(dp1, 0LL, sizeof(dp1));
	memset(s, 0LL, sizeof(s));
	memset(lazy, 0LL, sizeof(lazy));
	build();
	dp[0] = a[0]; //base case
	repn(i, 1, n){
		dp[i] = dp[i - 1];
		dp[i] += a[i];
		if(a[i] < sum(i - 1, i)){ //we have a problem
			//binary search for the first one that is larger than a[i];
			int l = 0, r = i;
			while(l < r){
				int mid = (l + r) / 2;
				if(sum(mid, mid + 1) >= a[i]) r = mid;
				else l = mid + 1;
			}
			increase(l, i, a[i]);
			dp[i] = sum(0, i + 1);
		}
	}
	rep(i, n) a[i] = b[i];
	reverse(a, a + n);
	memset(s, 0LL, sizeof(s));
	memset(lazy, 0LL, sizeof(lazy));
	build();
	dp1[0] = a[0];
	repn(i, 1, n){
		dp1[i] = dp1[i - 1];
		dp1[i] += a[i];
		if(a[i] < sum(i - 1, i)){ //we have a problem
			//binary search for the first one that is larger than a[i];
			int l = 0, r = i;
			while(l < r){
				int mid = (l + r) / 2;
				if(sum(mid, mid + 1) >= a[i]) r = mid;
				else l = mid + 1;
			}
			increase(l, i, a[i]);
			dp1[i] = sum(0, i + 1);
		}
	}
	int ind = 0;
	ll bst = 0;
	repn(i, 0, n){
		ll cur = dp[i] + dp1[n - i - 1] - b[i]; //avoid double counting
		if(cur > bst) bst = cur, ind = i;
	}
	if(bst < (dp1[n - 1])) bst = dp1[n - 1], ind = 0;
	if(bst < (dp[n - 1])) bst = dp[n - 1], ind = n - 1;
	ll ans = b[ind];
	ll mn = b[ind];
	vector<ll> res;
	for(int j = ind - 1; j >= 0; j--){
		res.pb(min(mn, b[j]));
		ans += min(mn, b[j]);
		mn = min(mn, b[j]); //can't be larger
	}
	reverse(all(res));
	res.pb(b[ind]);
	mn = b[ind];
	for(int j = ind + 1; j < n; j++){
		res.pb(min(mn, b[j]));
		ans += min(mn, b[j]);
		mn = min(mn, b[j]); //can't be larger
	}
	for(ll x : res) cout << x << " ";
	cout << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
