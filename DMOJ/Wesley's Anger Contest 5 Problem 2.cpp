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
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	reverse(all(a));
	vector<ll> mn(n), mx(n);
	mn[0] = mx[0] = a[0];
	repn(i, 1, n) mn[i] = min(mn[i - 1], a[i]);
	repn(i, 1, n) mx[i] = max(mx[i - 1], a[i]);
	rep(i, q){
		ll l, e;
		cin >> l >> e;
		int l1 = 0, r1 = n - 1;
		while(l1 < r1){
			int mid = (l1 + r1 + 1) / 2;
			if((mn[mid] >= (l - e)) && (mx[mid] <= (l + e))) l1 = mid;
			else r1 = mid - 1;
		}
		if((mn[l1] >= (l - e)) && (mx[l1] <= (l + e))) l1++;
		cout << l1 << '\n';
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
