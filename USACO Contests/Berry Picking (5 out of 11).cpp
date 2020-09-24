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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("berries.in", "r", stdin);
	//freopen("berries.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	vi b(n);
	rep(i, n) cin >> b[i];
	sort(all(b));
	reverse(all(b));
	int ans = 0;
	rep(j, n){
		vi c;
		rep(i, j){
			c.pb(b[i] / 2);
			c.pb((b[i] + 1) / 2);
		}	
		repn(i, j, b.size()) c.pb(b[i]);
		sort(all(c));
		reverse(all(c));
		int sum = 0;
		repn(i, k / 2, k) sum += c[i];
		ans = max(ans, sum);
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
