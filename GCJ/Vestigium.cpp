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

int g[105][105];

void solve(){
	int n;
	cin >> n;
	rep(i, n) rep(j, n) cin >> g[i][j];
	int ans = 0, ans1 = 0, ans2 = 0;
	rep(i, n) ans += g[i][i];
	rep(i, n){
		int f = 0;
		vi cnt(105, 0);
		rep(j, n){
			if(cnt[g[i][j]]){
				f = 1;
				break;
			}
			cnt[g[i][j]]++;
		}
		if(f) ans1++;
	}
	rep(j, n){
		int f = 0;
		vi cnt(105, 0);
		rep(i, n){
			if(cnt[g[i][j]]){
				f = 1;
				break;
			}
			cnt[g[i][j]]++;
		}
		if(f) ans2++;
	}
	cout << ans << " " << ans1 << " " << ans2 << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	cin >> t;
	repn(i, 1, t + 1){
		cout << "Case #" << i << ": ";
		solve();
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
