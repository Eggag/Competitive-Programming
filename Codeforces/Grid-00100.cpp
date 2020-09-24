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

char ans[305][305];

void solve(){
	int n, k;
	cin >> n >> k;
	int m = n;
	rep(i, n) rep(j, n) ans[i][j] = '0';
	int cur = 0, ad = 0;
	while(cur < k){
		rep(i, n){
			ans[i][(i + ad) % n] = '1';
			cur++;
			if(cur == k) break;
		}
		ad++;
	}
	int mn = 1e9, mx = 0;
	rep(i, n){
		int cnt = 0;
		rep(j, m) cnt += (ans[i][j] == '1');
		mx = max(mx, cnt);
		mn = min(mn, cnt);
	}
	int mn1 = 1e9, mx1 = 0;
	rep(j, m){
		int cnt = 0;
		rep(i, n) cnt += (ans[i][j] == '1');
		mx1 = max(mx1, cnt);
		mn1 = min(mn1, cnt);
	}
	cout << (ll)(sq(mx - mn) + sq(mx1 - mn1)) << endl;
	rep(i, n){
		rep(j, n) cout << ans[i][j];
		cout << endl;
	}
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
