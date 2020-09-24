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
	int n, q;
	cin >> n >> q;
	vi r(n + 1);
	repn(i, 1, n + 1) cin >> r[i];
	vi c(n + 1);
	repn(i, 1, n + 1) cin >> c[i];
	vi cnt(n + 1, 0), cnt1(n + 1, 0);
	repn(i, 1, n + 1) cnt[i] = cnt[i - 1] + (r[i] % 2);
	repn(i, 1, n + 1) cnt1[i] = cnt1[i - 1] + (c[i] % 2);
	while(q--){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int even = 0, odd = 0;
		if(c > a) odd += cnt[c] - cnt[a - 1];
		else odd += cnt[a] - cnt[c - 1];
		if(b > d) odd += cnt1[b] - cnt1[d - 1];
		else odd += cnt1[d] - cnt1[b - 1];
		even = (abs(a - c) + 1 + abs(b - d) + 1) - odd;
		if(!odd || !even) cout << "YES" << endl;
		else cout << "NO" << endl;
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
