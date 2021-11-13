#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define debug(x) cerr << #x << ": " << x << '\n'
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
	int n, m;
	cin >> n >> m;
	int mx = 0;
	repn(i, 1, n + 1) mx += (i - 1) / 2;
	if(m > mx){
		cout << -1 << '\n';
		return 0;
	}
	vi ans;
	int cnt = 0;
	repn(i, 1, n + 1){
		cnt += (i - 1) / 2;
		if(cnt > m){
			cnt -= (i - 1) / 2;
			break;
		}
		ans.pb(i);
	}
	int dif = m - cnt;
	if(dif > 0){
		int nm = (int)(ans.size()) - 1;
		ans.pb(ans[nm] + ans[nm - ((2 * dif) - 1)]);
	}
	if((int)(ans.size()) < n){
		int st = 1e7, gap = ans[(int)(ans.size()) - 1] + ans[(int)(ans.size()) - 2] + 1;
		while((int)(ans.size()) < n) ans.pb(st), st += gap;
	}
	rep(i, n) cout << ans[i] << " ";
	cout << '\n';
	return 0;
}
/*
Things to look out for:
	- Integer overflows
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
