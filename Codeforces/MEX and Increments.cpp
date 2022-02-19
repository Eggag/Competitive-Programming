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

void solve(){
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	sort(all(a));
	int ind = 0;
	ll pr = 0;
	vi lft;
	int f = 1;
	rep(i, n + 1){
		if(!f){
			cout << -1 << ' ';
			continue;
		}
		int cnt = 0;
		while(ind < n && a[ind] <= i){
			if(a[ind] == i) cnt++;
			ind++;
		}
		if(i && !lft.size()){
			cout << -1 << ' ';
			f = 0;
		}
		else{
			ll uwu = pr + cnt + (i ? ((i - 1) - lft.back()) : 0);
			if(i) lft.pop_back();
			rep(j, cnt) lft.pb(i);
			pr = uwu - cnt;
			cout << uwu << ' ';
		}
	}
	cout << '\n';
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
