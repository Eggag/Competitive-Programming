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
	ll n, m;
	cin >> n >> m;
	vector<ll> t(n), T(n), x(n), c(n);
	rep(i, n) cin >> t[i] >> T[i] >> x[i] >> c[i];
	ll tot = 0LL;
	rep(i, n){
		if(T[i] <= t[i]) tot += m * x[i] + c[i];
		else{
			if(m <= (T[i] - t[i])) tot += c[i];
			else{
				ll cur = 0LL;
				cur = (m / (T[i] - t[i]) - 1) * c[i];
				ll rem = m % (T[i] - t[i]);
				if(rem){
					cur = min(cur + 2 * c[i], cur + c[i] + (rem + (T[i] - t[i])) * x[i]);
				}
				else{
					cur += c[i];
				}
				cur = min(cur, c[i] + m * x[i]);
				tot += cur;
			}
		}
	}
	cout << tot << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
