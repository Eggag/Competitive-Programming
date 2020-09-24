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
const int MAXN = 405;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[MAXN], s1[4 * MAXN];

void build(int id = 1, int l = 1, int r = n + 1){
	if(r - l < 2){
		s1[id] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid, r);
	s1[id] = max(s1[id * 2], s1[id * 2 + 1]);
}

int maxQ(int x, int y, int id = 1, int l = 1, int r = n + 1){
	if(x >= r || l >= y) return -1e9;
	if(x <= l && r <= y) return s1[id];
	int mid = (l + r) / 2;
	return max(maxQ(x, y, id * 2, l, mid), maxQ(x, y, id * 2 + 1, mid, r));
}

int dp[405][405];
int pref[405];

int sum(int l, int r){
	return pref[r] - pref[l - 1];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	int k;
	cin >> n >> k;
	repn(i, 1, n + 1) cin >> a[i];
	pref[0] = 0;
	repn(i, 1, n + 1) pref[i] = pref[i - 1] + a[i];
	build();
	rep(i, 405) rep(j, 405) dp[i][j] = 1e9;
	dp[0][0] = 0;
	repn(i, 1, n + 1) rep(j, i){
		for(int k1 = k + 1; k1 >= 1; k1--){
			dp[i][k1] = min(dp[i][k1], dp[j][k1 - 1] + ((maxQ(j + 1, i + 1) * (i - j)) - sum(j + 1, i)));
		}
	}
	cout << dp[n][k + 1] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
