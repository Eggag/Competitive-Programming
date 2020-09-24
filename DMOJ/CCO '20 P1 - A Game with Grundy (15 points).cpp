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
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	int l, r;
	ld y;
	cin >> l >> r >> y;
	l += 2e6, r += 2e6; //we don't want to deal with negatives
	vi cnt(4e6, 0);
	rep(i, n){
		ld x;
		cin >> x;
		ld v, h;
		cin >> v >> h;
		ld mn1 = x - (ld)((ld)(y / v) * h), mx1 = x + (ld)((ld)(y / v) * h);
		int mn, mx;
		mn = ceil(mn1);
		mx = floor(mx1);
		mn += 2e6, mx += 2e6;
		int bd = 0;
		if(abs(mn1 - (mn - 2e6)) < 1e-4) bd = 1;
		int bd1 = 0;
		if(abs(mx1 - (mx - 2e6)) < 1e-4) bd1 = 1;
		cnt[max(0, mn + bd)]++, cnt[min((int)4e6 - 1, (mx - bd1) + 1)]--;
	}
	partial_sum(all(cnt), cnt.begin());
	unordered_map<int, int> m;
	repn(i, l, r + 1) m[cnt[i]]++;
	rep(i, n + 1){
		m[i] += m[i - 1];
		cout << m[i] << endl;
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
