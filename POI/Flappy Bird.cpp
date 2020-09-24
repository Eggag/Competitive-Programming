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
	int n, X;
	cin >> n >> X;
	if(!n){
		cout << 0 << endl;
		return 0;
	}
	vi x(n), a(n), b(n);
	rep(i, n) cin >> x[i] >> a[i] >> b[i];
	pi prev = {0, 0};
	rep(i, n){
		int mx = prev.fi + (x[i] - (i ? x[i - 1] : 0));
		int mn = prev.se - (x[i] - (i ? x[i - 1] : 0));
		pi prev1 = prev;
		prev.fi = min(b[i] - 1, mx);
		prev.se = max(a[i] + 1, mn);
		if(((x[i] - (i ? x[i - 1] : 0)) & 1) != (abs(prev1.fi - prev.fi) & 1)) prev.fi--;
		if(((x[i] - (i ? x[i - 1] : 0)) & 1) != (abs(prev1.se - prev.se) & 1)) prev.se++;
		if(prev.se > prev.fi){
			cout << "NIE" << endl;
			return 0;
		}
	}
	int ans = (x[n - 1] - abs(prev.se)) / 2;
	cout << ans + (prev.se > 0 ? prev.se : 0) << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
