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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int cnt[200005];

void solve(){
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i], cnt[i] = 0;
	cnt[0] = 0;
	repn(i, 1, n - 1) cnt[i] = cnt[i - 1] + (a[i] > a[i - 1] && a[i] > a[i + 1]);
	int mx = -1e9;
	int bst = -1;
	rep(i, n - k + 1){
		int cur = cnt[i + k - 2] - cnt[i];
		if(cur > mx){
			mx = cur;
			bst = i;
		}
	}
	assert(bst != -1);
	cout << mx + 1 << " " << bst + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
