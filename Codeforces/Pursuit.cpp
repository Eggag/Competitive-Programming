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
const int mxN = 1e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
int a[mxN], b[mxN];

bool check(int g){
	int k = (n + g) - ((n + g) / 4);
	int sum = 0, sum1 = 0;
	rep(i, min(k, n)) sum += b[i];
	if(k <= g) sum1 = 100 * k;
	else{
		sum1 = 100 * g;
		rep(i, min(n, k - g)) sum1 += a[i];
	}
	return sum1 >= sum;
}

void solve(){
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	reverse(a, a + n);
	reverse(b, b + n);
	int l = 0, r = 2 * n;
	while(l < r){
		int mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
