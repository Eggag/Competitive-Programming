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

bool cmp(pi a, pi b){
	return b.se > a.se;
}

int dp[200005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vector<pi> p(n + 1);
	rep(i, n){
		int a, b;
		cin >> a >> b;
		p[i + 1] = mp(a - b, a + b);
	}
	sort(1 + all(p), cmp);
	//rep(i, n) cout << p[i].fi << " " << p[i].se << endl;
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	vi mx(n + 1);
	mx[0] = 0;
	mx[1] = 1;
	repn(i, 2, n + 1){
		int l = 0, r = i - 1;
		while(l < r){
			int mid = (l + r + 1) / 2;
			if(p[i].fi >= p[mid].se) l = mid;
			else r = mid - 1;
		}
		dp[i] = mx[l] + 1;
		mx[i] = max(mx[i - 1], dp[i]);
	}
	cout << mx[n] << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
