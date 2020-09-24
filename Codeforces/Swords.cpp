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

ll gcd(ll a, ll b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll lcm(ll a, ll b){
	return (abs(a * b) / (gcd(a, b)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n), b(n);
	rep(i, n) cin >> a[i], b[i] = a[i];
	sort(all(a));
	reverse(all(a));
	sort(all(b));
	ll g1 = 0;
	rep(i, n - 1){
		g1 = gcd(g1, (b[n - 1] - b[i])); //make equal to the largest
	}
	ll ans1 = 0;
	rep(i, n - 1){
		ans1 += (b[n - 1] - b[i]) / g1;
	}
	//ll g = 0;
	//rep(i, n) g = gcd(g, a[i]);
	//ll l = a[0];
	//repn(i, 1, n){
	//	if(a[i]) l = lcm(l, a[i]);
	//}
	//rep(i, n){
	//	if(!a[i]){
	//		if(l % g != 0){
	//			cout << ans1 << " " << g1 << endl;
	//			return 0;
	//		}
	//	}
	//}
	//ll ans = 0;
	//rep(i, n){
	//	ans += (l - a[i]) / g;
	//}
	//if(ans < ans1) cout << ans << " " << g << endl;
	cout << ans1 << " " << g1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
