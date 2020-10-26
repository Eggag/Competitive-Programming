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

int lcm(int a, int b){
	return (a * b) / gcd(a, b);
}

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	for(int i = 0; i < n; i += 2){
		int neg = 0, neg1 = 0;
		if(a[i] < 0) neg = 1, a[i] *= -1;
		if(a[i + 1] < 0) neg1 = 1, a[i + 1] *= -1;
		int l = lcm(a[i], a[i + 1]);
		int x = l / a[i], y = l / a[i + 1];
		if(neg) x *= -1;
		if(!neg1) y *= -1;
		cout << x << " " << y << " ";
	}
	cout << endl;
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
