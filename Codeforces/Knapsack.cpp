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

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	ll w;
	cin >> n >> w;
	vector<pair<ll, int>> a(n);
	ll sm = 0LL;
	rep(i, n){
		cin >> a[i].fi;
		sm += a[i].fi;
		a[i].se = i;
	}
	if(sm < ((w + 1) / 2)){
		cout << -1 << '\n';
		return;
	}
	rep(i, n) if(a[i].fi <= w && a[i].fi >= ((w + 1) / 2)){
		cout << 1 << '\n';
		cout << i + 1 << '\n';
		return;
	}
	sort(all(a));
	ll cur = 0LL;
	vi ans;
	rep(i, n){
		cur += a[i].fi;
		ans.pb(a[i].se + 1);
		if(cur >= ((w + 1) / 2)){
			if(cur <= w) break;
			else{
				cout << -1 << '\n';
				return;
			}
		}
	}
	cout << (int)ans.size() << endl;
	for(int x : ans) cout << x << " ";
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
