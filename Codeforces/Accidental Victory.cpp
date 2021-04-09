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
const int mxN = 2e5 + 5;

template<class T> T gcd(T a, T b){ return ((b == 0) ? a : gcd(b, a % b)); }

int n;
pi a[mxN];

bool check(int g){
	int cur = a[g].fi;
	ll tot = cur;
	int ind = -1;
	rep(i, n) if(a[i].fi == cur) ind = i;
	for(int i = n - 1; i >= 0; i--){
		if(i != ind){
			if(tot < a[i].fi) return 0;
			tot += a[i].fi;
		}
	}
	return 1;
}

void solve(){
	cin >> n;
	rep(i, n) cin >> a[i].fi, a[i].se = i;
	sort(a, a + n);
	reverse(a, a + n);
	int l = 0, r = n - 1;
	while(l < r){
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	while(!check(l) && l) l--;
	if(!check(l) && !l){
		cout << 0 << '\n';
		return;
	}
	vi ans;
	rep(i, n) if(a[i].fi >= a[l].fi) ans.pb(a[i].se + 1);
	cout << (int)(ans.size()) << endl;
	sort(all(ans));
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
