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
	freopen("cowdate.in", "r", stdin);
	freopen("cowdate.out", "w", stdout);
	int n;
	cin >> n;
	vector<ld> p(n);
	rep(i, n){
		cin >> p[i];
		p[i] /= 1e6;
	}
	vector<ld> l(n), r(n);
	l[0] = (1 - p[0]);
	repn(i, 1, n) l[i] = l[i - 1] * (1 - p[i]);
	r[n - 1] = (1 - p[n - 1]);
	for(int i = n - 2; i >= 0; i--) r[i] = r[i + 1] * (1 - p[i]);
	ld ans = 0;
	rep(i, n){
		ans = max(ans, p[i]);
		ld prev = p[i];
		repn(j, i + 1, n){
			ld now = prev * (1 - p[j]);
			ld cur = (ld)((l[n - 1]) / ((i ? l[i - 1] : 1.0)));
			cur /= (((j + 1) < n) ? r[j + 1] : 1.0);
			now += (p[j] * (cur / (1 - p[j])));
			ans = max(ans, now);
			prev = now;
		}
	}
	cout << floor(ans * 1e6) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
