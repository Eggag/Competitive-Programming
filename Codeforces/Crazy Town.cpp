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
#define endl '\n'

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	ll x, y;
	cin >> x >> y;
	ll x1, y1;
	cin >> x1 >> y1;
	int n;
	cin >> n;
	vector<ll> a(n), b(n), c(n);
	rep(i, n){
		cin >> a[i] >> b[i] >> c[i];
	}
	int ans = 0;
	rep(i, n){
		if((ll)(a[i] * x + b[i] * y + c[i]) < 0 && (ll)(a[i] * x1 + b[i] * y1 + c[i]) > 0) ans++;
		if((ll)(a[i] * x + b[i] * y + c[i]) > 0 && (ll)(a[i] * x1 + b[i] * y1 + c[i]) < 0) ans++;
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
