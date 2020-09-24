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

void solve(){
	int n, x;
	cin >> n >> x;
	vi d(n), h(n);
	bool f = 0;
	int mx = 0;
	rep(i, n) cin >> d[i] >> h[i], mx = max(mx, d[i]), f |= (d[i] > h[i]);
	if(!f && (x > mx)){
		cout << -1 << endl;
		return;
	}
	if(x <= mx){
		cout << 1 << endl;
		return;
	}
	//basically what happens, is you use the most efficient blow, unless d[i] >= curX
	//the best is the best by delta
	int delta = -1e9;
	rep(i, n) delta = max(delta, d[i] - h[i]);
	int div = (x - mx) / delta;
	if((x - mx) % delta != 0) div++;
	cout << div + 1 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Array bounds
	- Special cases
Be careful!
*/
