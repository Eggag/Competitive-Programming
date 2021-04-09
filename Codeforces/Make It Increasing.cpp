#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << endl
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
#define inf 0x3f3f3f3f

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi a(n);
	rep(i, n) cin >> a[i];
	vi b1(k), bd(n, 0), b;
	rep(i, k) cin >> b1[i], bd[b1[i] - 1] = 1;
	int lst = -inf, ind = inf;
	if(!bd[0]) b.pb(0);
	rep(i, n) if(bd[i]){
		if(lst >= a[i] || (a[i] - lst - 1) < (i - ind - 1)){
			cout << -1 << '\n';
			return 0;
		}
		lst = a[i];
		ind = i;
		b.pb(i);
	}
	if(!bd[n - 1]) b.pb(n - 1);
	int ans = 0;
	//a[i] - i > a[j] - j
	rep(i, (int)(b.size()) - 1){
		int f = 0, f1 = 0;
		if(!b[i] && !bd[b[i]]) f = 1;
		if(b[i + 1] == (n - 1) && !bd[n - 1]) f1 = 1;
		vi c((b[i + 1] - b[i]) + 5, inf);
		c[0] = -inf;
		int cur = inf;
		repn(j, b[i], b[i + 1] + 1){
			int l = 0, r = j - b[i];
			while(l < r){
				int mid = (l + r + 1) / 2;
				if((a[j] - j) >= c[mid]) l = mid;
				else r = mid - 1;
			}
			if(l) c[l + 1] = min(c[l + 1], a[j] - j);
			else if((j != b[i] && f) || j == b[i]) c[l + 1] = min(c[l + 1], a[j] - j);
			if(f1 || j == b[i + 1]) cur = min(cur, b[i + 1] - b[i] - l);
		}
		ans += cur;
	}
	cout << ans << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
