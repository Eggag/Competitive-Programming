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
	int n, W;
	cin >> n >> W;
	vi w(n);
	vi cnt(25, 0);
	rep(i, n){
		cin >> w[i];
		rep(j, 25) if(w[i] & (1 << j)) cnt[j]++;
	}
	int rem = n;
	rep(i, n){
		int tot = W;
		for(int j = 24; j >= 0; j--){
			int d = tot / (1 << j);
			if(d < cnt[j]){
				cnt[j] -= d;
				tot -= (1 << j) * d;
				rem -= d;
			}
			else{
				tot -= (1 << j) * cnt[j];
				rem -= cnt[j];
				cnt[j] = 0;
			}
		}
		if(!rem){
			cout << i + 1 << '\n';
			return;
		}
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
	- Make sure that max is large enough (2e9, 4e18)
	- Special cases
Be careful!
*/
