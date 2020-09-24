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
const int mxN = 3e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

ll mx[mxN], mx1[mxN];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int h, w, m;
	cin >> h >> w >> m;
	vi a(m), b(m);
	rep(i, m) cin >> a[i] >> b[i], mx[a[i]]++, mx1[b[i]]++;
	//basically
	//it is either max(mx) + max(mx1)
	//or that - 1
	ll a1 = 0LL, b1 = 0LL;
	ll bg = 0LL, bg1 = 0LL;
	rep(i, mxN) bg = max(bg, mx[i]);
	rep(i, mxN) if(mx[i] == bg) a1++;
	rep(i, mxN) bg1 = max(bg1, mx1[i]);
	rep(i, mxN) if(mx1[i] == bg1) b1++;
	ll num = a1 * b1, tot = 0LL;
	rep(i, m){
		if(mx[a[i]] == bg && mx1[b[i]] == bg1) tot++;
	}
	if(num != tot) cout << bg + bg1 << endl;
	else cout << bg + bg1 - 1 << endl;
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
