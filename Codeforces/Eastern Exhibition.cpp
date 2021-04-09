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
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
#define sq(x) ((x) * (x))

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

void solve(){
	int n;
	cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	ll mn = 1e18;
	sort(all(x));
	vi bst;
	rep(i, n){
		ll cur = 0LL;
		rep(j, n) cur += abs(x[i] - x[j]);
		if(cur == mn) bst.pb(x[i]);
		if(cur < mn){
			mn = cur;
			bst.clear();
			bst.pb(x[i]);
		}
	}
	make_unique(bst);
	ll dx = 1;
	sort(all(bst));
	if(bst.size() > 1) dx = bst[1] - bst[0] + 1;
	swap(x, y);
	mn = 1e18;
	sort(all(x));
	bst.clear();
	rep(i, n){
		ll cur = 0LL;
		rep(j, n) cur += abs(x[i] - x[j]);
		if(cur == mn) bst.pb(x[i]);
		if(cur < mn){
			mn = cur;
			bst.clear();
			bst.pb(x[i]);
		}
	}
	make_unique(bst);
	ll dy = 1;
	sort(all(bst));
	if(bst.size() > 1) dy = bst[1] - bst[0] + 1;
	cout << dx * dy << endl;

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
