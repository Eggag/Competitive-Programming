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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int n;
	cin >> n;
	vi a(n);
	rep(i, n) cin >> a[i];
	int pos = 0, neg = 0;
	vi ps, ng;
	rep(i, n){
		if(a[i] >= 0) pos++, ps.pb(i);
		else neg++, ng.pb(i);
	}
	int only = 1;
	if(pos && neg) only = 0;
	vector<pi> ans;
	if(only){
		if(pos){
			//keep subtracting from the lowest?
			sort(all(a));
			repn(i, 1, n - 1){
				ans.pb(mp(a[0], a[i]));
				a[0] -= a[i];
			}
			ans.pb(mp(a[n - 1], a[0]));
			a[n - 1] -= a[0];
			cout << a[n - 1] << endl;
			rep(i, ans.size()) cout << ans[i].fi << " " << ans[i].se << endl;
		}
		else{
			//keep adding to the lowest ig
			sort(all(a));
			reverse(all(a));
			repn(i, 1, n){
				ans.pb(mp(a[0], a[i]));
				a[0] -= a[i];
			}
			cout << a[0] << endl;
			rep(i, ans.size()) cout << ans[i].fi << " " << ans[i].se << endl;
		}
	}
	else{
		int pos1 = ps[0];
		int neg1 = ng[0];
		rep(i, n) if(i != pos1 && i != neg1){
			if(a[i] >= 0){
				ans.pb(mp(a[neg1], a[i]));
				a[neg1] -= a[i];
			}
			else{
				ans.pb(mp(a[pos1], a[i]));
				a[pos1] -= a[i];
			}
		}
		ans.pb(mp(a[pos1], a[neg1]));
		cout << a[pos1] - a[neg1] << endl;
		rep(i, ans.size()) cout << ans[i].fi << " " << ans[i].se << endl;
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
