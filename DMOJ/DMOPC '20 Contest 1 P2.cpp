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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> sum(n);
	sum[0] = a[0];
	repn(i, 1, n) sum[i] = sum[i - 1] + a[i];
	int l = 0, r = n - 1; //[l, r]
	rep(i, d){
		int ni;
		cin >> ni;
		int ls = sum[l + ni - 1] - (l ? sum[l - 1] : 0);
		int rs = (sum[r] - (l ? sum[l - 1] : 0)) - ls;
		int ans = 0;
		if(ls >= rs) l += ni, ans = ls;
		else ans = rs, r = l + ni - 1;
		cout << ans << '\n';
	}
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
