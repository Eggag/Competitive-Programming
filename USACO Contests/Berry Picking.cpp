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

int n, k;
int b[1005];

int go(int heig){
	vi c;
	rep(i, n){
		int nm = b[i];
		while(nm >= heig){
			c.pb(heig);
			nm -= heig;
		}
		c.pb(nm);
	}
	if(c.size() >= k){
		sort(all(c));
		reverse(all(c));
		int sum = 0;
		repn(i, k / 2, k) sum += c[i];
		return sum;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("berries.in", "r", stdin);
	freopen("berries.out", "w", stdout);
	cin >> n >> k;
	rep(i, n) cin >> b[i];
	sort(b, b + n);
	reverse(b, b + n);
	int ans = 0;
	repn(i, 1, 1001) ans = max(ans, go(i));
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
