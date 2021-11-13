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
#define unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
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
	int a, b;
	cin >> a >> b;
	int o = 0, z = 0;
	int n = (a + b);
	rep(i, n) if(i & 1) o++;
	z = n - o;
	vi cnt(a + b + 5, 0);
	rep(i, o + 1){
		if(i > a) break;
		if(z >= a - i){
			int l = i + max(0, min(b, z - (a - i)));
			cnt[l]++;
		}
	}
	rep(i, z + 1){
		if(i > b) break;
		if(o >= b - i){
			int l = i + max(0, min(a, o - (b - i)));
			cnt[l]++;
		}
	}
	swap(o, z);
	rep(i, o + 1){
		if(i > a) break;
		if(z >= a - i){
			int l = i + max(0, min(b, z - (a - i)));
			cnt[l]++;
		}
	}
	rep(i, z + 1){
		if(i > b) break;
		if(o >= b - i){
			int l = i + max(0, min(a, o - (b - i)));
			cnt[l]++;
		}
	}
	vi ans;
	rep(i, a + b + 2) if(cnt[i]) ans.pb(i);
	cout << (int)(ans.size()) << '\n';
	for(int x : ans) cout << x << ' ';
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
